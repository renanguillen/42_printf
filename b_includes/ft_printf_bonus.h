/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:18:06 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/22 20:18:11 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define DECA "0123456789"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	dot;
	int	width;
	int	left;
	int	zero;
	int	sharp;
	int	space;
	int	plus;
	int	precision;
}		t_flags;

int			ft_strlen(const char *s);
void		ft_putchar(char c);
void		ft_putbase(unsigned long num, char *base);
int			ft_countdigits(unsigned long num, int base);
int			ft_validation(const char *format, int len, va_list arg,
				t_flags *flag);
int			ft_arg_c(const char *format, int len, va_list arg, t_flags *flag);
int			ft_arg_p(int len, va_list arg, t_flags *flag);
int			ft_arg_s(int len, va_list arg, t_flags *flag);
int			ft_arg_udi(const char *format, int len, va_list arg, t_flags *flag);
int			ft_arg_x(const char *format, int len, va_list arg, t_flags *flag);
void		ft_bzero(void *s, size_t n);
void		ft_checkflags(const char **format, t_flags *flag);
int			ft_isdigit(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_freethis(void *ptr);
int			ft_printf(const char *format, ...);

#endif
