/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_after_percentage.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:36:25 by orekabe           #+#    #+#             */
/*   Updated: 2021/12/22 02:55:48 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_after_percentage(const char *format, va_list temp)
{
	int		i;
	int		size;
	int		boool;
	int		arg;

	i = 0;
	size = 0;
	boool = 0;
	arg = va_arg(temp, int);
	if (ft_check_decimal(format[i]) && format[i - 1] != '%')
	{
		i--;
		size += ft_check_plus(&format[i], arg);
	}
	else if (ft_check_hexa(format[i]) && format[i - 1] != '%')
	{
		i--;
		size += ft_check_hash(&format[i], format[i + 1], arg);
	}
	return (size);
}
