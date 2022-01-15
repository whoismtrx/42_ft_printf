/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:47:45 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/14 20:08:32 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_get_width_u(t_flags flags, long long n)
{
	if (flags.width < flags.precision || flags.width < ft_count_len(n, 10))
		flags.width = 0;
	if (flags.width > flags.precision && flags.precision > ft_count_len(n, 10)
		&& n < 0)
		flags.width -= 1;
	return (flags);
}

int	ft_putunbr(long long n, t_flags flags)
{
	int			size;
	long long	nbr;

	size = 0;
	nbr = n;
	flags = ft_get_width_u(flags, n);
	if (!flags.minus && flags.precision)
		size += ft_fill_width(flags, nbr, 10);
	if (n < 0 && (flags.dot || flags.zero))
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (!flags.minus && !flags.precision)
		size += ft_fill_width(flags, nbr, 10);
	size += ft_fill_prec(flags, n, 10);
	if (flags.dot && n == 0 && !flags.precision)
		size = size + 1 - 1;
	else
		size += ft_putnbr(n);
	if (flags.minus)
		size += ft_fill_width(flags, nbr, 10);
	return (size);
}
