/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:52:27 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/14 03:46:47 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_width(t_flags flags, long long n)
{
	int	size;

	size = 0;
	if (!flags.minus && ft_count_len(n) > flags.precision)
	{
		if (flags.zero && n != 0)
		{
			while (flags.width-- > ft_count_len(n))
				size += ft_putchar('0');
		}
		else if (flags.zero && flags.dot && n == 0 && !flags.precision)
		{
			while (flags.width-- > 0)
				size += ft_putchar(' ');
		}
		while (flags.width-- > ft_count_len(n))
			size += ft_putchar(' ');
	}
	else if (!flags.minus && ft_count_len(n) < flags.precision)
	{
		if (flags.zero && n != 0)
		{
			while (flags.width-- > flags.precision)
				size += ft_putchar('0');
		}
		else if (flags.zero && flags.dot && n == 0 && !flags.precision)
		{
			while (flags.width-- > 0)
				size += ft_putchar(' ');
		}
		while (flags.width-- > flags.precision)
			size += ft_putchar(' ');
	}
	else if (flags.minus)
	{
		if (n == 0 && flags.dot)
		{
			while (flags.width-- > flags.precision)
			size += ft_putchar(' ');
		}
		if (flags.precision == ft_count_len(n) && n < 1)
			flags.precision += 1;
		while (flags.width-- > ft_count_len(n) && flags.width >= flags.precision)
			size += ft_putchar(' ');
	}
	return (size);
}
