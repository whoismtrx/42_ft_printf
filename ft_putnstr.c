/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 04:55:09 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/12 00:18:51 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_get_width_s(t_flags flags, const char *str)
{
	if (flags.dot)
	{
		if (flags.precision < ft_strlen(str))
			flags.width = flags.width - flags.precision;
		else
			flags.width = flags.width - ft_strlen(str);
	}
	else
	{
		if (flags.width < ft_strlen(str))
			flags.width = 0;
		else
			flags.width = flags.width - ft_strlen(str);
	}
	return (flags);
}

static int	ft_putlenstr(const char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && len)
	{
		ft_putchar(str[i]);
		i++;
		len--;
	}
	return (i);
}

int	ft_putnstr(const char *str, t_flags flags)
{
	int	size;

	size = 0;
	flags = ft_get_width_s(flags, str);
	if (!flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	if (!str && !flags.dot)
		size += write(1, "(null)", 6);
	else if (!str && flags.dot && flags.precision <= 6)
		size += write(1, "(null)", flags.precision);
	else if (!str && flags.dot && flags.precision > 6)
		size += write(1, "(null)", 6);
	else if (flags.dot)
		size += ft_putlenstr(str, flags.precision);
	else
		size += ft_putstr(str);
	if (flags.minus)
	{
		while (flags.width-- > 0)
			size += ft_putchar(' ');
	}
	return (size);
}
