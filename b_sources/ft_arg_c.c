/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:49:05 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/07 19:08:27 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_arg_c(const char *format, int len, va_list arg)
{
	int	i;

	if (*format == '%')
		write(1, "%", 1);
	else if (*format == 'c')
	{
		i = va_arg(arg, int);
		write(1, &i, 1);
	}
	return (++len);
}
