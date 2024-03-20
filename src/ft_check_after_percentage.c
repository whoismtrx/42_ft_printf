/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_after_percentage.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:36:25 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/15 19:57:03 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_after_percentage(const char *format, va_list temp)
{
	int		i;
	int		size;
	int		width;
	char	*str;
	int		arg;

	i = 0;
	size = 0;
	width = 0;
	if (format[i] == 's')
		str = va_arg(temp, char *);
	else
		arg = va_arg(temp, int);
	if (ft_check_decimal(format[i]) && format[--i] != '%')
		size += ft_check_plus(&format[i], arg);
	else if (ft_check_hexa(format[i]) && format[--i] != '%')
		size += ft_check_hash(&format[i], format[i + 1], arg);
	else if (format[i--] == 's' && format[i - 1] != '%')
	{
		while (ft_isdigit(format[i--]))
			width = ft_atoi(&format[i]);
		while (width-- > ft_strlen(str))
			size += ft_putchar(' ');
	}
	return (size);
}
