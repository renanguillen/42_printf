/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:12:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/17 17:27:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_structure sc;

	va_start(arg, format);
	sc.len = 0;
	sc.wid = 0;
	while (*format)
	{
		if(*format == '%')
	}
}
