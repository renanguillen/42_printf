/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:28:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/26 21:48:33 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
