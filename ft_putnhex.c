/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:39:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/11 04:58:15 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_count_lenhex(unsigned long n)
{
	int		len;
	long	nbr;
	
	len = 0;
	nbr = n;
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
		if (nbr >= 0 && nbr <= 9)
		{
			len++;
			return (len);
		}
	}
	return (0);
}

static t_flags	ft_get_width_h(t_flags flags, int len)
{
	if (flags.dot)
	{
		if (flags.precision < len)
			flags.width = flags.width - len;
		else
			flags.width = flags.width - flags.precision;
	}
	else
	{
		if (flags.width < len)
			flags.width = 0;
		else
			flags.width = flags.width - len;
	}
	return (flags);
}

static int	ft_get_len_hex(unsigned long n)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789abcdef";
	if (n < 16)
		len++;
	else
	{
		n += ft_get_len_hex(n / 16);
		n += ft_get_len_hex(n % 16);
	}
	return (len);
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
		zero = precision - ft_get_len_hex(n);
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
	len = ft_get_len_hex(n);
	flags = ft_get_width_h(flags, len);
	if (!flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	if (flags.dot)
		size += ft_putlenhex(n, c, flags.precision);
	else
		size += ft_puthex(n, c);
	if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}
