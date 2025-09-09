/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:34:25 by cecompte          #+#    #+#             */
/*   Updated: 2025/06/21 18:23:29 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		(*func)(va_list);
	va_list	args;

	va_start(args, format);
	if (!format)
		return (-1);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] != '%')
		{
			count += ft_putchar(format[i]);
			continue ;
		}
		func = get_func(format[++i]);
		if (func)
			count += func(args);
		else
			count += ft_putchar('%');
	}
	va_end(args);
	return (count);
}
