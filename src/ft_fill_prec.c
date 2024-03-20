/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_prec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:35:40 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/14 19:23:34 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_prec(t_flags flags, long long n, int base)
{
	int	size;

	size = 0;
	while (flags.precision-- > ft_count_len(n, base))
		size += ft_putchar('0');
	return (size);
}
