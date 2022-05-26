/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:51:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/26 21:40:03 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_arg4(const char *format, int len, va_list arg)
{
	int				i;
	unsigned int	u;

	if (*format == 'u')
	{
		u = va_arg(arg, unsigned int);
		ft_putbase(u, DECA);
		len = len + ft_countdigits(u, 10);
	}
	else if (*format == 'x')
	{
		i = va_arg(arg, int);
		ft_putbase(i, HEXA_LOWER);
		len = len + ft_countdigits(i, 16);
	}
	else if (*format == 'X')
	{
		i = va_arg(arg, int);
		ft_putbase(i, HEXA_UPPER);
		len = len + ft_countdigits(i, 16);
	}
	return (len);
}
