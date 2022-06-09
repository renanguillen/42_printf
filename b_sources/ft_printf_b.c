/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:08:51 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/06 20:01:46 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	t_flags	flag;

	len = 0;
	ft_bzero(&flag, sizeof(t_flags));
	va_start(arg, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			len++;
		}
		else
		{
			format++;
			ft_checkflags(&format, &flag);
			len = ft_validation(format, len, arg);
			format++;
		}
	}
	va_end(arg);
	return (len);
}
