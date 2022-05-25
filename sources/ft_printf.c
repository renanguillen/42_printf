/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:08:51 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/25 23:05:26 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_validation(const char c)
{
	if (c == '%' || c == 'c')
		return (1);
	else if (c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X')
		return (2);
	return (0);
}

int	ft_arg2(const char *format, int len, va_list arg)
{
	char	*s;
	unsigned long p;

	if (*format == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
			s = "(null)";
		write(1, s, ft_strlen(s));
		len = len + ft_strlen(s);
	}
	else if (*format == 'p')
	{
		p = va_arg(arg, unsigned long);
		if (!p)
			s = "(null)";
		write(1, s, ft_strlen(s));
		len = len + ft_strlen(s);
	}
	return (len);
}

int	ft_arg1(const char *format, int len, va_list arg)
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

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		index;

	len = 0;
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
			index = ft_validation(*format);
			if (index == 1)
				len = ft_arg1(format++, len, arg);
			else if (index == 2)
				len = ft_arg2(format++, len, arg);
			else
				return (0);
		}
	}
	return (len);
}
