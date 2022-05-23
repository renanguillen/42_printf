/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:44:12 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/23 19:48:17 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	if_d(int nbr)
{
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static int	if_x(int nbr)
{
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ft_intlen(int nbr, char c)
{
	int	i;
	int	neg;

	i = 0;
	if (!nbr)
		return (1);
	if (nbr < 0)
	{
		neg = 1;
		nbr = -nbr;
	}
	else
		neg = 0;
	if (c == 'd')
		return (if_d(nbr) + neg);
	else if (c == 'x')
		return (if_x(nbr));
	return (0);
}
