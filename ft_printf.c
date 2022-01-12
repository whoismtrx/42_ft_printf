/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:24:48 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/11 19:27:48 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags ft_initialise_to_0(t_flags flags)
{
	flags.dot = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.flags1 = 0;
	return (flags);
}

static int	ft_print1(const char *format, va_list ptr, t_flags flags)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (ft_check_specifier(format[i]))
		size += ft_conversion1(&format[i], size, ptr, flags);
	return (size);
}

static int	ft_print2(const char *format, va_list ptr)
{
	int		i;
	int		size;
	va_list	temp;

	i = 0;
	size = 0;
	if (ft_check_specifier(format[i]))
	{
		va_copy(temp, ptr);
		size += ft_check_after_percentage(&format[i], temp);
		size += ft_conversion2(&format[i], ptr);
	}
	else
		size += ft_putchar(format[i]);
	return (size);
}

static int	ft_print(const char *format, int i, int size, va_list ptr)
{
	t_flags	flags;

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i] == '%')
		{
			i++;
			flags = ft_initialise_to_0(flags);
			while (!ft_check_specifier(format[i]))
			{
				flags = ft_check_flags1(&format[i], flags);
				i++;
			}
			if (ft_check_specifier(format[i]))
			{
				if (flags.flags1 == 1)
					size += ft_print1(&format[i], ptr, flags);
				else
					size += ft_print2(&format[i], ptr);
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