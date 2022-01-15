/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:17:23 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/15 04:05:40 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_get_flags1(const char *format, t_flags flags)
{
	int	i;

	i = 0;
	if ((format[i] == '0') && !(ft_isdigit(format[i - 1])))
		flags.zero = 1;
	if (format[i] == '-')
	{
		flags.minus = 1;
		flags.zero = 0;
	}
	if (format[i] == '.')
		flags.dot = 1;
	if ((format[i] >= '0' && format[i] <= '9') && format[i - 1] != '.'
		&& !flags.width && format[i - 1] != '0')
		flags.width = ft_atoi(&format[i]);
	if ((format[i] >= '0' && format[i] <= '9') && format[i - 1] == '.')
		flags.precision = ft_atoi(&format[i]);
	if (flags.precision)
		flags.zero = 0;
	if (flags.dot || flags.minus || flags.precision
		|| flags.width || flags.zero)
		flags.flags1 = 1;
	return (flags);
}
