/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:24:48 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/15 20:22:22 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_initialise_to_0(t_flags flags)
{
	flags.dot = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.flags1 = 0;
	return (flags);
}

static int	ft_pick_any_print(const char *format, va_list ptr, t_flags flags)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	if (flags.flags1 == 1)
		size += ft_print1(&format[i], ptr, flags);
	else
		size += ft_print2(&format[i], ptr);
	return (size);
}

static int	ft_print(const char *format, int i, int size, va_list ptr)
{
	t_flags	flags;

	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i++] == '%')
		{
			flags = ft_initialise_to_0(flags);
			while (ft_flags1(format[i]) && !ft_flags2(format[i - 1]))
			{
				flags = ft_get_flags1(&format[i], flags);
				i++;
			}
			while (!ft_check_specifier(format[i]) && ft_flags2_w(format[i]))
				i++;
			if (ft_check_specifier(format[i]))
				size += ft_pick_any_print(&format[i], ptr, flags);
			else
				size += ft_putchar(format[i]);
		}
		else
			size += ft_putchar(format[--i]);
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		size;
	va_list	ptr;

	i = -1;
	size = 0;
	va_start(ptr, format);
	size += ft_print(format, i, size, ptr);
	va_end(ptr);
	return (size);
}
