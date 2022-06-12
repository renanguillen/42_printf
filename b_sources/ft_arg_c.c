/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:49:05 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/09 21:38:12 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_arg_c(const char *format, int len, va_list arg, t_flags *flag)
{
	int	i;

	(void)flag;
	if (*format == '%')
		write(1, "%", 1);
	else if (*format == 'c')
	{
		i = va_arg(arg, int);
		flag->width--;
		if (flag->left)
		{
			write(1, &i, 1);
			while (flag->width > 0)
			{
				ft_putchar(' ');
				flag->width--;
				len++;
			}
		}
		else
		{
			while (flag->width > 0)
			{
				ft_putchar(' ');
				flag->width--;
				len++;
			}
			write(1, &i, 1);
		}
	}
	return (++len);
}
