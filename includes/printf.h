/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:14:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/23 19:53:09 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_structure
{
	int	len;
	int	wid;
}	t_structure;

int			ft_strlen(const char *s);
char		*ft_strchr(const char *s);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nbr);
void		ft_puthexa(unsigned int x);
int			ft_intlen(int nbr, char c);
const char	*ft_read_text(const char *format, t_structure *sc);
const char	*ft_search_arg(va_list arg, const char *format, t_structure *sc);

#endif
