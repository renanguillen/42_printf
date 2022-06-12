/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_sdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:50:09 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/09 23:46:41 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_arg_sdi(const char *format, int len, va_list arg, t_flags *flag)
{
	char		*s;
	char		*str;
	long int	i;
	int			intlen;
	int			signal;

	signal = 1;
	if (*format == 's')
	{
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
		if (s)
		{
			free(s);
			s = NULL;
		}
	}
	else if (*format == 'd' || *format == 'i' || *format == 'u')
	{
		if (*format == 'u')
			i = va_arg(arg, unsigned int);
		else
			i = va_arg(arg, int);
		if (i < 0)
		{
			signal--;
			len++;
			i *= -1;
		}
		intlen = ft_countdigits(i, 10);
		flag->width -= intlen;
		if (signal && (flag->plus || flag->space))
			len++;
		if (i < 0 || flag->plus || flag->space)
			flag->width--;
		if (flag->width > 0)
			len += flag->width;
		if (flag->left)
		{
			if (flag->plus && signal)
				ft_putchar('+');
			else if (flag->space && signal)
				ft_putchar(' ');
			if (!signal)
				ft_putchar('-');
			ft_putbase(i, DECA);
			while (!flag->zero && flag->width-- > 0)
				ft_putchar(' ');
			while (flag->zero && flag->width-- > 0)
				ft_putchar('0');
		}
		else
		{
			if (flag->space && signal && !flag->plus)
				ft_putchar(' ');
			while (!flag->zero && flag->width-- > 0)
				ft_putchar(' ');
			while (flag->zero && flag->width-- > 0)
				ft_putchar('0');
			if (flag->plus && signal)
				ft_putchar('+');
			else if (!signal)
				ft_putchar('-');
			ft_putbase(i, DECA);	
		}
		len += intlen;
	}
	return (len);
}
