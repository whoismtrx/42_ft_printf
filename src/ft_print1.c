/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:27:32 by orekabe           #+#    #+#             */
/*   Updated: 2022/01/14 20:28:04 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print1(const char *format, va_list ptr, t_flags flags)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (ft_check_specifier(format[i]))
		size += ft_conversion1(&format[i], size, ptr, flags);
	return (size);
}
