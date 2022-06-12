/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_ux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:51:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/09 23:39:19 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_arg_ux(const char *format, int len, va_list arg, t_flags *flag)
{
	unsigned int	u;
	int				hexalen;

	u = va_arg(arg, unsigned int);
	hexalen = ft_countdigits(u, 16);
	flag->width -= hexalen;
	if (flag->sharp)
	{
		len += 2;
		flag->width -= 2;
	}
	if (flag->width > 0)
		len += flag->width;
	if (flag->left)
	{
		if (flag->sharp)
			write(1, "0x", 2);
		if (*format == 'x')
			ft_putbase(u, HEXA_LOWER);
		else
			ft_putbase(u, HEXA_UPPER);
		while (flag->width-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (flag->width-- > 0)
			ft_putchar(' ');
		if (flag->sharp)
			write(1, "0x", 2);
		if (*format == 'x')
			ft_putbase(u, HEXA_LOWER);
		else
			ft_putbase(u, HEXA_UPPER);
	}
	len += hexalen;
	return (len);
}
