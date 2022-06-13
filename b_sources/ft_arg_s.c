/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:43:30 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/13 16:49:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_arg_s(int len, va_list arg, t_flags *flag)
{
	char		*s;
	char		*str;

	str = va_arg(arg, char *);
	s = ft_substr(str, 0, ft_strlen(str));
	if (!s)
		s = ft_substr("(null)", 0, 6);
	else if (flag->precision)
		s = ft_substr(s, 0, flag->precision);
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
	ft_freethis(s);
	return (len);
}
