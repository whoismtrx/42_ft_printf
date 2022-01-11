/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:16:53 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/11 03:15:41 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_count_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
		if (n >= -9 && n <= 9)
		{
			len++;
			return (len);
		}
	}
	return (0);
}

static t_flags	ft_get_width_n(t_flags flags, int n)
{
	if (flags.dot)
	{
		if (flags.precision < ft_count_len(n))
			flags.width = flags.width - ft_count_len(n);
		else
			flags.width = flags.width - flags.precision;
	}
	else
	{
		if (flags.width < ft_count_len(n))
			flags.width = 0;
		else
			flags.width = flags.width - ft_count_len(n);
	}
	return (flags);
}

static int	ft_putlennbr(long long n, int precision)
{
	int	size;
	int	zero;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size += ft_putchar('-');
	}
	if (precision > ft_count_len(n))
	{
		zero = precision - ft_count_len(n);
		while (zero--)
			size += ft_putchar('0');
	}
	if (n == 0)
		return (size);
	if (n > 9)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	else
		size += ft_putchar(n + 48);
	return (size);
}

int	ft_putnnbr(long long n, t_flags flags)
{
	int	size;

	size = 0;
	flags = ft_get_width_n(flags, n);
	if (!flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	if (flags.dot)
		size += ft_putlennbr(n, flags.precision);
	else
		size += ft_putnbr(n);
	if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}
