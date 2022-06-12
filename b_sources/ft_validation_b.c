/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:53:44 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/09 23:17:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_validation(const char *format, int len, va_list arg, t_flags *flag)
{
	char	c;

	c = *format;
	if (c == '%' || c == 'c')
		len = ft_arg_c(format, len, arg, flag);
	else if (c == 's' || c == 'd' || c == 'i' || c == 'u')
		len = ft_arg_sdi(format, len, arg, flag);
	else if (c == 'p')
		len = ft_arg_p(format, len, arg, flag);
	else if (c == 'x' || c == 'X')
		len = ft_arg_ux(format, len, arg, flag);
	else
		len = 0;
	ft_bzero(flag, sizeof(t_flags));
	return (len);
}
