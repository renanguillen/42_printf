/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:51:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/26 19:51:46 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_arg3(const char *format, int len, va_list arg)
{
	char			*s;
	unsigned long	p;

	if (*format == 'p')
	{
		p = va_arg(arg, unsigned long);
		if (!p)
		{
			s = "(nil)";
			write(1, s, ft_strlen(s));
			len = len + ft_strlen(s);
		}
		else
		{
			write(1, "0x", 2);
			ft_putbase(p, HEXA_LOWER);
			len = len + ft_countdigits(p, 16) + 2;
		}
	}
	return (len);
}
