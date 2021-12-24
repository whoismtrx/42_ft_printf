/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:30:18 by orekabe           #+#    #+#             */
/*   Updated: 2021/12/16 21:11:24 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char *format, va_list ptr)
{
	int		i;
	int		size;
	char	c;

	i = 0;
	size = 0;
	if (format[i] == 'c')
		size += ft_putchar(va_arg(ptr, int));
	else if (format[i] == 's')
		size += ft_putstr(va_arg(ptr, char *));
	else if (format[i] == 'p')
		size += ft_putaddress(va_arg(ptr, unsigned long));
	else if (format[i] == 'd' || format[i] == 'i')
		size += ft_putnbr(va_arg(ptr, int));
	else if (format[i] == 'u')
		size += ft_putnbr(va_arg(ptr, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
	{
		c = format[i];
		size += ft_puthex(va_arg(ptr, unsigned int), c);
	}
	else if (format[i] == '%')
		size += ft_putchar('%');
	return (size);
}
