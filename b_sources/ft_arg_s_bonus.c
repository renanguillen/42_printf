/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_s_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:43:30 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/22 20:16:29 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_bonus.h"

static char	*ft_strtrim(char *str, t_flags *flag)
{
	if (!str)
		str = ft_substr("(nil)", 0, 5);
	else
		str = ft_substr(str, 0, ft_strlen(str));
	if (flag->precision)
		str = ft_substr(str, 0, flag->precision);
	return (str);
}

int	ft_arg_s(int len, va_list arg, t_flags *flag)
{
	char	*str;

	str = ft_strtrim(va_arg(arg, char *), flag);
	flag->width -= ft_strlen(str);
	if (flag->width > 0)
			len += flag->width;
	if (flag->left)
	{
		write(1, str, ft_strlen(str));
		while (flag->width-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (flag->width-- > 0)
			ft_putchar(' ');
		write(1, str, ft_strlen(str));
	}
	len = len + ft_strlen(str);
	ft_freethis(str);
	return (len);
}
