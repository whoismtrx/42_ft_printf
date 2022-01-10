/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:26:12 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/10 04:39:23 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar(char c, t_flags flags)
{
	int	size;

	size = 0;
	flags.width = flags.width - 1;
	if (!flags.minus)
	{
		while (flags.width--)
			size += ft_putchar(' ');
	}
	size += ft_putchar(c);
	if (flags.minus)
	{
		while (flags.width--)
			size += ft_putchar(' ');
	}
	return (size);
}