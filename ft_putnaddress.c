/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnaddress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:01:48 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/12 02:20:13 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_count_lenadd(unsigned long n)
{
	int		len;
	unsigned long	nbr;
	
	len = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		if (nbr >= 16)
		{
			nbr /= 16;
			len++;
		}
		if (nbr >= 0 && nbr < 16)
		{
			len++;
			return (len);
		}
	}
	return (0);
}

static t_flags	ft_get_width_add(t_flags flags, int len)
{
	if (flags.dot)
	{
		if (flags.precision < len)
			flags.width = flags.width - (len + 2);
		else
			flags.width = flags.width - (flags.precision + 2);
	}
	else
	{
		if (flags.width < len)
			flags.width = 0;
		else
			flags.width = flags.width - (len + 2);
	}
	return (flags);
}

static int ft_putlenadd(int precision, int len)
{
	int	size;
	int	zero;

	size = 0;
	if (precision > len)
	{
		zero = precision - len;
		while (zero--)
			size += ft_putchar('0');
	}
	return (size);
}
int	ft_putnadd(unsigned long n, char c, t_flags flags)
{
	int				size;
	unsigned int	len;

	size = 0;
	len = ft_count_lenadd(n);
	flags = ft_get_width_add(flags, len);
	if (!flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	size += ft_putstr("0x");
	if (flags.dot)
		size += ft_putlenadd(flags.precision, len);
	size += ft_puthex(n, c);
	if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}
