/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:49:05 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/28 14:30:17 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_arg_c(const char *format, int len, va_list arg)
{
	int	i;

	if (*format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	else if (*format == 'c')
	{
		i = va_arg(arg, int);
		write(1, &i, 1);
		len++;
	}
	return (len);
}
