/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:50:09 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/26 21:39:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_arg2(const char *format, int len, va_list arg)
{
	char	*s;
	int		i;

	if (*format == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
			s = "(null)";
		write(1, s, ft_strlen(s));
		len = len + ft_strlen(s);
	}
	else if (*format == 'd' || *format == 'i')
	{
		i = va_arg(arg, int);
		ft_putbase(i, DECA);
		len = len + ft_countdigits(i, 10);
	}
	return (len);
}
