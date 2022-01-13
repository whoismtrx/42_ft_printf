/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:26:06 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/13 02:41:23 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_zero(t_flags flags)
{
	int	size;

	size = 0;
	if (!flags.minus && flags.zero)
	{
		while (flags.precision-- > 0)
			size += ft_putchar('0');
	}
	return (size);
}