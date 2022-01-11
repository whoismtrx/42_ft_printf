/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:38:15 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/11 05:06:39 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
typedef struct s_flags
{
	int	width;
	int	precision;
	int	minus;
	int	dot;
	int	zero;
	int	flags1;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_conversion1(const char *format, int size, va_list ptr, t_flags flags);
int		ft_conversion2(const char *format, va_list ptr);
int		ft_check_after_percentage(const char *format, va_list ptr);
int		ft_check_flags(char c);
t_flags	ft_check_flags1(const char *format, t_flags flags);
int		ft_check_flags2(char c);
int		ft_check_specifier(char c);
int		ft_check_decimal(char c);
int		ft_check_hexa(char c);
int		ft_check_hash(const char *format, char c, int arg);
int		ft_check_plus(const char *format, int arg);
int		ft_check_width(const char *format);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putnbr(long long n);
int		ft_puthex(unsigned long n, char c);
int		ft_putaddress(unsigned long n);
int		ft_putnchar(char c, t_flags flags);
int		ft_putnstr(const char *str, t_flags flags);
int		ft_putnnbr(long long n, t_flags flags);
int		ft_putnhex(unsigned long n, char c, t_flags flags);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);

#endif