/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:28:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/06 20:02:03 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

int	ft_countdigits(unsigned long num, int base)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		num /= base;
		count++;
	}
	return (count);
}
