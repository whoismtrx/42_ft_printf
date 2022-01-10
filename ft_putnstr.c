/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:55:09 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/10 16:47:16 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlenstr(const char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		i += write(1, "(null)", 6);
	else
	{
		while (str[i] && len)
		{
			ft_putchar(str[i]);
			i++;
			len--;
		}
	}
	return (i);
}
int	ft_putnstr(const char *str, t_flags flags)
{
	int	size;

	size = 0;
	if (!str)
		size += write(1, "(null)", 6);
	else
	{
		if (flags.dot)
			flags.width = flags.width - flags.precision;
		if (!flags.minus)
		{
			while (flags.width--)
				size += ft_putchar(' ');
		}
		if (flags.precision)
			size += ft_putlenstr(str, flags.precision);
		else
			size += ft_putstr(str);
		if (flags.minus)
		{
			while (flags.width--)
				size += ft_putchar(' ');
		}
	}
	return (size);
}