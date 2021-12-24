/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:24:48 by orekabe           #+#    #+#             */
/*   Updated: 2021/12/22 03:03:18 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(const char *format, int i, int size, va_list ptr)
{
	va_list	temp;

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i] == '%')
		{
			i++;
			while (ft_check_flags2(format[i]))
				i++;
			if (ft_check_specifier(format[i]))
			{
				va_copy(temp, ptr);
				size += ft_check_after_percentage(&format[i], temp);
				size += ft_conversion(&format[i], ptr);
			}
			else
				size += ft_putchar(format[i]);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		size;
	va_list	ptr;

	i = 0;
	size = 0;
	va_start(ptr, format);
	size += ft_print(format, i, size, ptr);
	va_end(ptr);
	return (size);
}
