/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:26:06 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/13 23:18:08 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_zero(t_flags flags, long long n)
{
	int	size;

	size = 0;
	if (!flags.minus && flags.zero && n != 0)
	{
		while (flags.precision-- > ft_count_len(n))
			size += ft_putchar('0');
	}
	return (size);
}