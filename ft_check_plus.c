/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:45:01 by orekabe           #+#    #+#             */
/*   Updated: 2021/12/22 02:56:39 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_plus(const char *format, int arg)
{
	int	i;
	int	boool;
	int	size;

	i = 0;
	boool = 0;
	size = 0;
	while (format[i] != '%')
	{
		if (format[i] == '+' && arg >= 0)
		{
			size += ft_putchar('+');
			return (size);
		}
		else if (format[i] == ' ' && arg >= 0)
			boool = 1;
		i--;
	}
	if (boool)
		size += ft_putchar(' ');
	return (size);
}
