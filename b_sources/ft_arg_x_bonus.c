/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_x_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:51:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/23 17:13:19 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_bonus.h"

static void	ft_checkcase(const char *format, t_flags *flag)
{
	if (*format == 'x')
	{
		flag->prefix = "0x";
		flag->base = HEXA_LOWER;
	}
	else
	{
		flag->prefix = "0X";
		flag->base = HEXA_UPPER;
	}
}

static void	ft_identation_left(unsigned int u, t_flags *flag)
{
	if (u == 0 && !flag->width)
		write(1, "0", 1);
	if (flag->width)
	{
		if (flag->sharp && u)
			write(1, flag->prefix, 2);
		while (flag->zero && flag->width-- > 0)
			write(1, "0", 1);
		ft_putbase(u, flag->base);
	}
	while (!flag->zero && flag->width-- > 0)
		ft_putchar(' ');
}

static void	ft_identation_right(unsigned int u, t_flags *flag)
{
	while (!flag->zero && flag->width-- > 0)
		ft_putchar(' ');
	if (u == 0 && !flag->width)
		write(1, "0", 1);
	if (flag->width)
	{
		if (flag->sharp && u)
			write(1, flag->prefix, 2);
		while (flag->zero && flag->width-- > 0)
			write(1, "0", 1);
		ft_putbase(u, flag->base);
	}
}

static int	ft_wid_adjustments(
	int len, unsigned int u, int hexalen, t_flags *flag)
{
	flag->width -= hexalen;
	if (flag->sharp)
	{
		len += 2;
		flag->width -= 2;
		if (u == 0)
			len -= 2;
	}
	if (flag->dot && (flag->precision > hexalen))
	{
		flag->zero = 1;
		if (flag->width < 0)
			flag->width = 0;
		flag->width += flag->precision - hexalen;
	}
	if (flag->width > 0)
		len += flag->width;
	return (len);
}

int	ft_arg_x(const char *format, int len, va_list arg, t_flags *flag)
{
	unsigned int	u;
	int				hexalen;

	u = va_arg(arg, unsigned int);
	hexalen = ft_countdigits(u, 16);
	len = ft_wid_adjustments(len, u, hexalen, flag);
	ft_checkcase(format, flag);
	if (flag->left)
		ft_identation_left(u, flag);
	else
		ft_identation_right(u, flag);
	len += hexalen;
	return (len);
}
