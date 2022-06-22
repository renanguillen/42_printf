/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_c_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:49:05 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/22 20:16:21 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_bonus.h"

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
