/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:38:15 by orekabe           #+#    #+#             */
/*   Updated: 2021/12/22 02:55:20 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_conversion(const char *format, va_list ptr);
int	ft_check_after_percentage(const char *format, va_list ptr);
int	ft_check_flags2(char c);
int	ft_check_specifier(char c);
int	ft_check_decimal(char c);
int	ft_check_hexa(char c);
int	ft_check_hash(const char *format, char c, int arg);
int	ft_check_plus(const char *format, int arg);
int	ft_check_width(const char *format);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long long n);
int	ft_puthex(unsigned long n, char c);
int	ft_putaddress(unsigned long n);

#endif