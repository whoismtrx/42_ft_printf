/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:37:22 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/13 03:40:10 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_len(long long n)
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
		n /= 10;
		len++;
		if (n >= -9 && n <= 9)
		{
			len++;
			return (len);
		}
	}
	return (len);
}