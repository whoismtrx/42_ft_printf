/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:48:58 by orekabe           #+#    #+#             */
/*   Updated: 2021/12/16 18:36:31 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long n)
{
	char	c;
	int		size;

	c = 'x';
	size = 0;
	size += ft_putstr("0x");
	size += ft_puthex(n, c);
	return (size);
}
