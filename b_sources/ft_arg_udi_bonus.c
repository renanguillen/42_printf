/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_udi_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:50:09 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/22 23:37:44 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_bonus.h"

static void	ft_identation_left(int signal, int i, t_flags *flag)
{
	if (flag->plus && signal)
		ft_putchar('+');
	else if (flag->space && signal)
		ft_putchar(' ');
	if (!signal)
		ft_putchar('-');
	if (i == -2147483648)
		ft_putbase(2147483648, DECA);
	else
		ft_putbase(i, DECA);
	while (!flag->zero && flag->width-- > 1)
		ft_putchar(' ');
	while (flag->zero && flag->width-- > 0)
		ft_putchar('0');
}

static void	ft_identation_right(int signal, int i, t_flags *flag)
{
	if (flag->space && signal && !flag->plus)
		ft_putchar(' ');
	while (!flag->zero && flag->width-- > 0)
		ft_putchar(' ');
	while (flag->zero && flag->width-- > 0)
		ft_putchar('0');
	if (flag->plus && signal)
		ft_putchar('+');
	else if (!signal)
		ft_putchar('-');
	if (i == -2147483648)
		ft_putbase(2147483648, DECA);
	else
		ft_putbase(i, DECA);
}

static int	ft_wid_adjustments(long int i, int signal, int len, t_flags *flag)
{
	if (signal && (flag->plus || flag->space))
		len++;
	if (i < 0 || flag->plus || flag->space)
		flag->width--;
	if (flag->width > 0)
		len += flag->width;
	return (len);
}

int	ft_arg_udi(const char *format, int len, va_list arg, t_flags *flag)
{
	long int	i;
	int			intlen;
	int			signal;

	signal = 1;
	if (*format == 'u')
		i = va_arg(arg, unsigned int);
	else
		i = va_arg(arg, int);
	if (i < 0)
	{
		signal--;
		i *= -1;
		if (i > 9)
			len++;
	}
	intlen = ft_countdigits(i, 10);
	flag->width -= intlen;
	len = ft_wid_adjustments(i, signal, len, flag);
	if (flag->left)
		ft_identation_left(signal, i, flag);
	else
		ft_identation_right(signal, i, flag);
	len += intlen;
	return (len);
}
