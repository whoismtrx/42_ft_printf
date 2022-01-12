/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:52:27 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/12 06:22:54 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fill_before(t_flags flags)
{
	int	size;

	size = 0;
	if (!flags.minus && flags.zero)
	{
		while (flags.width-- > 0)
			size += ft_putchar('0');
	}
	else if (!flags.minus && !flags.zero)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}

static int	ft_fill_after(t_flags flags)
{
	int	size;

	size = 0;
	
	if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}

int	ft_fill(t_flags flags)
{
	int	size;

	size = 0;
	if (!flags.minus)
		size += ft_fill_before(flags);
	else
		size += ft_fill_after(flags);
	return (size);
}
