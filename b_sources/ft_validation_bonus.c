/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:53:44 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/22 20:17:18 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_bonus.h"

int	ft_validation(const char *format, int len, va_list arg, t_flags *flag)
{
	char	c;

	c = *format;
	if (c == '%' || c == 'c')
		len = ft_arg_c(format, len, arg, flag);
	else if (c == 's')
		len = ft_arg_s(len, arg, flag);
	else if (c == 'd' || c == 'i' || c == 'u')
		len = ft_arg_udi(format, len, arg, flag);
	else if (c == 'p')
		len = ft_arg_p(len, arg, flag);
	else if (c == 'x' || c == 'X')
		len = ft_arg_x(format, len, arg, flag);
	else
		len = 0;
	ft_bzero(flag, sizeof(t_flags));
	return (len);
}
