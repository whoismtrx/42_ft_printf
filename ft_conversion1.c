/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 03:29:17 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/10 05:55:55 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion1(const char *format, va_list ptr, t_flags flags)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (format[i] == 'c')
		size += ft_putnchar(va_arg(ptr, int), flags);
	else if (format[i] == 's')
		size += ft_putnstr(va_arg(ptr, char *), flags);
	else if (format[i] == 'p')
		size += ft_putaddress(va_arg(ptr, unsigned long));
	else if (format[i] == 'd' || format[i] == 'i')
		size += ft_putnbr(va_arg(ptr, int));
	else if (format[i] == 'u')
		size += ft_putnbr(va_arg(ptr, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		size += ft_puthex(va_arg(ptr, unsigned int), format[i]);
	else if (format[i] == '%')
		size += ft_putchar('%');
	return (size);
}