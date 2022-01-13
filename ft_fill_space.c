/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:52:27 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/13 05:56:16 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_space(t_flags flags, long long n)
{
	int	size;

	size = 0;
	if (!flags.minus)
	{
		printf("%d\n", flags.width);
		if (flags.zero)
		{
			while (flags.width-- > 0 && n != 0)
				size += ft_putchar('0');
		}
		while (flags.width-- > 0)
				size += ft_putchar(' ');
	}
	else if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}
