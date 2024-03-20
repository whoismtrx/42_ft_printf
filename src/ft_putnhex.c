/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:39:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/14 20:07:16 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_get_width_h(t_flags flags, long long n)
{
	if (flags.width < flags.precision || flags.width < ft_count_len(n, 16))
		flags.width = 0;
	if (flags.width > flags.precision && flags.precision > ft_count_len(n, 16)
		&& n < 0)
		flags.width -= 1;
	return (flags);
}

int	ft_putnhex(unsigned long n, char c, t_flags flags)
{
	int			size;
	long long	nbr;

	size = 0;
	nbr = n;
	flags = ft_get_width_h(flags, n);
	if (!flags.minus && flags.precision)
		size += ft_fill_width(flags, nbr, 16);
	if (n < 0 && (flags.dot || flags.zero))
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (!flags.minus && !flags.precision)
		size += ft_fill_width(flags, nbr, 16);
	size += ft_fill_prec(flags, n, 16);
	if (flags.dot && n == 0 && !flags.precision)
		size = size + 1 - 1;
	else
		size += ft_puthex(n, c);
	if (flags.minus)
		size += ft_fill_width(flags, nbr, 16);
	return (size);
}
