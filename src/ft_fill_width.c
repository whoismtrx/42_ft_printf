/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:52:27 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/15 22:10:29 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_fill_width1(t_flags flags, long long n, int base)
{
	int	size;

	size = 0;
	if (flags.zero && n != 0 && !flags.precision && !flags.dot)
	{
		while (flags.width-- > ft_count_len(n, base))
			size += ft_putchar('0');
	}
	if (flags.zero && !flags.dot)
	{
		while (flags.width-- > ft_count_len(n, base))
			size += ft_putchar('0');
	}
	else if (flags.zero && flags.dot && n == 0 && !flags.precision)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	while (flags.width-- > ft_count_len(n, base))
	{
		size += ft_putchar(' ');
		if (n == 0 && flags.width == ft_count_len(n, base) && flags.dot)
			size += ft_putchar(' ');
	}
	return (size);
}

static	int	ft_fill_width2(t_flags flags, long long n)
{
	int	size;

	size = 0;
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
	return (size);
}

static	int	ft_fill_width3(t_flags flags, long long n, int base)
{
	int	size;

	size = 0;
	if (n == 0 && flags.dot)
	{
		while (flags.width-- > flags.precision)
			size += ft_putchar(' ');
	}
	if (flags.precision == ft_count_len(n, base) && n < 1)
		flags.precision += 1;
	while (flags.width-- > ft_count_len(n, base)
		&& flags.width >= flags.precision)
		size += ft_putchar(' ');
	return (size);
}

int	ft_fill_width(t_flags flags, long long n, int base)
{
	int	size;

	size = 0;
	if (!flags.minus && ft_count_len(n, base) > flags.precision)
		size += ft_fill_width1(flags, n, base);
	else if (!flags.minus && ft_count_len(n, base) < flags.precision)
		size += ft_fill_width2(flags, n);
	else if (!flags.minus && ft_count_len(n, base) == flags.precision)
	{
		while (flags.width-- > flags.precision)
			size += ft_putchar(' ');
	}
	else if (flags.minus)
		size += ft_fill_width3(flags, n, base);
	return (size);
}
