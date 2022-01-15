/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:28:15 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/15 04:11:18 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print2(const char *format, va_list ptr)
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
