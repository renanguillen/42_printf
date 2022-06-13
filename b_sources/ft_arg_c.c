/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:49:05 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/13 16:19:07 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

static int	ft_spacelen(int len, t_flags *flag)
{
	while (flag->width > 0)
	{
		ft_putchar(' ');
		flag->width--;
		len++;
	}
	return (len);
}

int	ft_arg_c(const char *format, int len, va_list arg, t_flags *flag)
{
	int	i;

	if (*format == '%')
		write(1, "%", 1);
	else if (*format == 'c')
	{
		i = va_arg(arg, int);
		flag->width--;
		if (flag->left)
		{
			write(1, &i, 1);
			len = ft_spacelen(len, flag);
		}
		else
		{
			len = ft_spacelen(len, flag);
			write(1, &i, 1);
		}
	}
	return (++len);
}
