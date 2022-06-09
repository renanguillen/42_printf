/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:14:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/06 20:03:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_B_H
# define FT_PRINTF_B_H

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define DECA "0123456789"

# include <stdarg.h>
# include <unistd.h>

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
int			ft_validation(const char *format, int len, va_list arg);
int			ft_arg_c(const char *format, int len, va_list arg);
int			ft_arg_p(const char *format, int len, va_list arg);
int			ft_arg_sdi(const char *format, int len, va_list arg);
int			ft_arg_ux(const char *format, int len, va_list arg);
void		ft_bzero(void *s, size_t n);
void		ft_checkflags(const char **format, t_flags *flag);
int			ft_isdigit(int c);
int			ft_printf(const char *format, ...);

#endif
