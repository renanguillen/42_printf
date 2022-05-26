/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:51:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/26 21:55:50 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_arg4(const char *format, int len, va_list arg)
{
	unsigned int	u;

	if (*format == 'u')
	{
		u = va_arg(arg, unsigned int);
		ft_putbase(u, DECA);
		len = len + ft_countdigits(u, 10);
	}
	else if (*format == 'x')
	{
		u = va_arg(arg, unsigned int);
		ft_putbase(u, HEXA_LOWER);
		len = len + ft_countdigits(u, 16);
	}
	else if (*format == 'X')
	{
		u = va_arg(arg, unsigned int);
		ft_putbase(u, HEXA_UPPER);
		len = len + ft_countdigits(u, 16);
	}
	return (len);
}
