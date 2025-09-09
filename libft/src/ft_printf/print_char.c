/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:43:20 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/23 14:10:19 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list arg)
{
	char	x;

	x = va_arg(arg, int);
	return (ft_putchar(x));
}

int	print_str(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

int	print_memory(va_list arg)
{
	void			*ptr;
	unsigned long	nbr;
	int				count;

	ptr = va_arg(arg, void *);
	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	nbr = (unsigned long)ptr;
	count += putnbr_base(nbr, "0123456789abcdef");
	return (count);
}
