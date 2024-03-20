/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:37:22 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/14 23:46:00 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_lennbr(long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	if (n >= -9 && n <= 9)
	{
		len++;
		return (len);
	}
	while (n != 0)
	{
		n /= base;
		len++;
		if (n >= -9 && n <= 9)
		{
			len++;
			return (len);
		}
	}
	return (len);
}

static	int	ft_count_lenhex(unsigned long n, int base)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = n;
	if (n >= 0 && n < 16)
	{
		len++;
		return (len);
	}
	while (nbr > 0)
	{
		nbr /= base;
		len++;
		if (nbr >= 0 && nbr < 16)
		{
			len++;
			return (len);
		}
	}
	return (0);
}

int	ft_count_len(long long n, int base)
{
	int	len;

	len = 0;
	if (base == 10)
		len = ft_count_lennbr(n, base);
	else if (base == 16)
		len = ft_count_lenhex(n, base);
	return (len);
}
