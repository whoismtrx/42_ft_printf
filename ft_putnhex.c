/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:39:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/12 05:17:50 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_count_lenhex(unsigned long n)
{
	int		len;
	long	nbr;
	
	len = 0;
	nbr = n;
	if (n >= 0 && n <= 16)
	{
		len++;
		return (len);
	}
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
		if (nbr >= 0 && nbr < 16)
		{
			len++;
			return (len);
		}
	}
	return (0);
}

static t_flags	ft_get_width_h(t_flags flags, unsigned long n)
{
	int	old_width;
	
	old_width = flags.width;
	if (flags.dot)
	{
		if (flags.precision < ft_count_lenhex(n) && flags.precision > 0)
			flags.width = flags.width - ft_count_lenhex(n);
		else
			flags.width = flags.width - flags.precision;
	}
	if (flags.width < ft_count_lenhex(n) && old_width < ft_count_lenhex(n))
		flags.width = 0;
	else if (flags.width >= ft_count_lenhex(n) && n == 0 && flags.dot && flags.precision >= ft_count_lenhex(n))
		flags.width -= 1;
	else if (flags.width >= ft_count_lenhex(n) && n == 0 && !flags.dot)
		flags.width -= 1;
	else if (!flags.dot && n != 0)
		flags.width = flags.width - ft_count_lenhex(n);
	else if (flags.width == ft_count_lenhex(n))
		flags.width = 0;
	return (flags);
}

static int	ft_putlenhex(unsigned long n, char c, int precision)
{
	int		size;
	int		zero;
	char	*hex;

	size = 0;
	hex = "0123456789abcdef";
	if (precision > ft_count_lenhex(n))
	{
		zero = precision - ft_count_lenhex(n);
		while (zero--)
			size += ft_putchar('0');
	}
	if (n < 16)
	{
		if (c == 'X' && n > 9)
			size += ft_putchar(hex[n] - 32);
		else
			size += ft_putchar(hex[n]);
	}
	else
	{
		size += ft_puthex(n / 16, c);
		size += ft_puthex(n % 16, c);
	}
	return (size);
}

int	ft_putnhex(unsigned long n, char c, t_flags flags)
{
	int				size;
	unsigned int	len;

	size = 0;
	len = ft_count_lenhex(n);
	flags = ft_get_width_h(flags, n);
	if (!flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	if (flags.dot && flags.precision > 0)
		size += ft_putlenhex(n, c, flags.precision);
	else if (flags.dot && flags.precision == 0 && n == 0 && !flags.width && !flags.minus)
		return (0);
	else if (n != 0)
		size += ft_puthex(n, c);
	else if (!flags.dot && n == 0)
		size += ft_puthex(n, c);
	if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}
