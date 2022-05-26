/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:14:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/26 21:42:09 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define DECA "0123456789"

# include <stdarg.h>
# include <unistd.h>

int			ft_strlen(const char *s);
void		ft_putchar(char c);
void		ft_putbase(unsigned long num, char *base);
int			ft_countdigits(unsigned long num, int base);
int			ft_validation(const char *format, int len, va_list arg);
int			ft_arg1(const char *format, int len, va_list arg);
int			ft_arg2(const char *format, int len, va_list arg);
int			ft_arg3(const char *format, int len, va_list arg);
int			ft_arg4(const char *format, int len, va_list arg);
int			ft_printf(const char *format, ...);

#endif
