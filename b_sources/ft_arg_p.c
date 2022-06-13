/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:51:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/12 22:37:28 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_arg_p(int len, va_list arg, t_flags *flag)
{
	char			*s;
	unsigned long	p;

	p = va_arg(arg, unsigned long);
	if (!p)
	{
		s = "(nil)";
		flag->width -= ft_strlen(s);
		if (flag->width > 0)
			len += flag->width;
		if (flag->left)
		{
			write(1, s, ft_strlen(s));
			while (flag->width-- > 0)
				ft_putchar(' ');
		}
		else
		{
			while (flag->width-- > 0)
				ft_putchar(' ');
			write(1, s, ft_strlen(s));
		}
		len = len + ft_strlen(s);
	}
	else
	{
		flag->width -= ft_countdigits(p, 16) + 2;
		if (flag->width > 0)
			len += flag->width;
		if (flag->left)
		{
			write(1, "0x", 2);
			ft_putbase(p, HEXA_LOWER);
			while (flag->width-- > 0)
				ft_putchar(' ');
		}
		else
		{
			while (flag->width-- > 0)
				ft_putchar(' ');
			write(1, "0x", 2);
			ft_putbase(p, HEXA_LOWER);
		}
		len = len + ft_countdigits(p, 16) + 2;
	}
	return (len);
}
