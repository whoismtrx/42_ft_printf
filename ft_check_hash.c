/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:44:14 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/15 22:00:42 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_hash(const char *format, char c, int arg)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (format[i] != '%' && arg != 0)
	{
		if (format[i] == '#' && c == 'x')
		{
			size += ft_putstr("0x");
			return (size);
		}
		else if (format[i] == '#' && c == 'X')
		{
			size += ft_putstr("0X");
			return (size);
		}
		else if (format[i] == ' ' || format[i] == '+' || ft_isdigit(format[i]))
			i--;
	}
	return (size);
}
