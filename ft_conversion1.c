/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 03:29:17 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/15 03:15:38 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion1(const char *format, int size, va_list ptr, t_flags flags)
{
	int		i;

	i = 0;
	if (format[i] == 'c')
		size += ft_putnchar(va_arg(ptr, int), flags);
	else if (format[i] == 's')
		size += ft_putnstr(va_arg(ptr, char *), flags);
	else if (format[i] == 'p')
		size += ft_putnadd(va_arg(ptr, unsigned long), 'x', flags);
	else if (format[i] == 'd' || format[i] == 'i')
		size += ft_putnnbr(va_arg(ptr, int), flags);
	else if (format[i] == 'u')
		size += ft_putunbr(va_arg(ptr, unsigned int), flags);
	else if (format[i] == 'x' || format[i] == 'X')
		size += ft_putnhex(va_arg(ptr, unsigned int), format[i], flags);
	else if (format[i] == '%')
		size += ft_putnchar('%', flags);
	return (size);
}
