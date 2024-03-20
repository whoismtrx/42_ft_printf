/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:44:02 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/11 04:15:31 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char c)
{
	int		size;
	char	*hex;

	size = 0;
	hex = "0123456789abcdef";
	if (n < 16)
	{
		if (c == 'X' && n > 9)
			size += ft_putchar(hex[n] - 32);
		else
			size += ft_putchar(hex[n]);
	}
	else
	{
		size += ft_puthex(n / 16, c);
		size += ft_puthex(n % 16, c);
	}
	return (size);
}
