/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:49:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/23 20:50:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

const char	*ft_read_text(const char *format, t_structure *sc)
{
	char	*next;

	next = ft_strchr(format);
	if (next)
		sc->wid = next - format;
	else
		sc->wid = ft_strlen(format);
	write(1, format, sc->wid);
	sc->len += sc->wid;
	while (*format && *format != '%')
		format++;
	return (format);
}
