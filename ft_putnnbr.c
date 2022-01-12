/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:16:53 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/12 05:58:37 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_count_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	if (n >= -9 && n <= 9)
	{
		len++;
		return (len);
	}
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
	return (len);
}

static t_flags	ft_get_width_n(t_flags flags, long long n)
{
	int	old_width;
	
	old_width = flags.width;
	if (flags.dot)
	{
		if (flags.precision < ft_count_len(n) && flags.precision > 0)
			flags.width = flags.width - ft_count_len(n);
		else
			flags.width = flags.width - flags.precision;
	}
	if (flags.width < ft_count_len(n) && old_width < ft_count_len(n))
		flags.width = 0;
	else if (flags.width >= ft_count_len(n) && n < 0 && flags.dot && flags.precision >= ft_count_len(n))
		flags.width -= 1;
	else if (!flags.dot)
		flags.width = flags.width - ft_count_len(n);
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

static int	ft_putlennbr0(long long n, int precision, int len)
{
	int	size;
	int	zero;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size += ft_putchar('-');
	}
	if (precision > len)
	{
		zero = precision - len;
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
	int	len;
	
	size = 0;
	len = 0;
	flags = ft_get_width_n(flags, n);
	size += ft_fill_after(flags);
	if (flags.dot && n != 0)
		size += ft_putlennbr(n, flags.precision);
	else if (flags.dot && n == 0)
		size += ft_putlennbr0(n, flags.precision, len);
	else
		size += ft_putnbr(n);
	if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}
