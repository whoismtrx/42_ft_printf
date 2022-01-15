/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:26:12 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/15 03:22:10 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar(char c, t_flags flags)
{
	int	size;

	size = 0;
	flags.width = flags.width - 1;
	if (!flags.minus)
	{
		if (c == '%' && flags.zero)
		{
			while (flags.width-- > 0)
				size += ft_putchar('0');
		}
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	if (c == '%')
		size += ft_putchar('%');
	else
		size += ft_putchar(c);
	if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}
