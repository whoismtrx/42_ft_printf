/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_prec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:35:40 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/13 23:30:05 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_prec(t_flags flags, long long n)
{
	int	size;

	size = 0;
	// printf("prec2=%d\n", flags.precision);
	while (flags.precision-- > ft_count_len(n))
		size += ft_putchar('0');
	return (size);
}
