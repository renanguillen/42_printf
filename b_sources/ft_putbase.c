/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:18:10 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/06 20:01:54 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

void	ft_putbase(unsigned long num, char *base)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	if (num / len_base > 0)
		ft_putbase(num / len_base, base);
	ft_putchar(base[num % len_base]);
}
