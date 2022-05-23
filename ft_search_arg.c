/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:53:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/23 19:57:28 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

static void	get_slen(char *s, t_structure *sc)
{
	if (!s)
	{
		write(1, "(null)", 6);
		sc->len += 6;
	}
	else
	{
		ft_putstr(s);
		sc->len += ft_strlen(s);
	}
	return ;
}

const char	*ft_search_arg(va_list arg, const char *format, t_structure *sc)
{
	int				d;
	char			*s;
	unsigned int	x;

	if (*format == 'd')
	{
		d = va_arg(arg, int);
		ft_putnbr(d);
		sc->len = ft_intlen(d, *format);
	}
	else if (*format == 's')
	{
		s = va_arg(arg, char *);
		get_slen(s, sc);
	}
	else if (*format == 'x')
	{
		x = va_arg(arg, unsigned int);
		ft_puthexa(x);
		sc->len += ft_intlen((int)x, *format);
	}
	else
		return (NULL);
	return (++format);
}
