/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:16:53 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/14 05:25:33 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_get_width_n(t_flags flags, long long n)
{
	if (flags.width < flags.precision || flags.width < ft_count_len(n))
		flags.width = 0;
	if (flags.width > flags.precision && flags.precision > ft_count_len(n) && n < 0)
		flags.width -= 1;
	return (flags);
}

// static int	ft_filln(long long n, long long nbr, t_flags flags)
// {
// 	int	size;
// 	int	boool;

// 	size = 0;
// 	boool = 1;
// 	if (n < 0 && (flags.dot || flags.zero))
// 	{
// 		size += ft_putchar('-');
// 		n *= -1;
// 	}
// 	if (boool == 1 && !flags.minus && !flags.precision)
// 	{
// 		size += ft_fill_width(flags, nbr);
// 		boool = 0;
// 	}
// 	return (size);
// }

int	ft_putnnbr(long long n, t_flags flags)
{
	int			size;
	long long	nbr;
	
	size = 0;
	nbr	= n;
	flags = ft_get_width_n(flags, n);
	if (!flags.minus && flags.precision)
		size += ft_fill_width(flags, nbr);
	if (n < 0 && (flags.dot || flags.zero))
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (!flags.minus && !flags.precision)
		size += ft_fill_width(flags, nbr);
	size += ft_fill_prec(flags, n);
	if (flags.dot && n == 0 && !flags.precision)
		size = size + 1 - 1;
	else
		size += ft_putnbr(n);
	if (flags.minus)
		size += ft_fill_width(flags, nbr);
	return (size);
}
