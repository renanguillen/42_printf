/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:38:45 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/09 22:22:12 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	truelen;
	unsigned int	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		truelen = 1;
	else if (len >= slen)
		truelen = slen - start + 1;
	else
		truelen = len + 1;
	sub = (char *)malloc(truelen);
	if (!sub)
		return (NULL);
	while ((start < slen) && (i < len))
	{
		sub[i] = s[start];
		i++;
		start++;
	}	
	sub[i] = 0;
	return (sub);
}
