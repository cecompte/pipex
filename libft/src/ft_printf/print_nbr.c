/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:53:52 by cecompte          #+#    #+#             */
/*   Updated: 2025/06/21 17:20:43 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(va_list arg)
{
	int				n;
	int				count;
	unsigned int	u;

	count = 0;
	n = va_arg(arg, int);
	u = (unsigned int)n;
	if (n < 0)
	{
		count += ft_putchar('-');
		u = -u;
	}
	return (count + putnbr_base(u, "0123456789"));
}

int	print_nbr_hex(va_list arg)
{
	unsigned int	nbr;

	nbr = va_arg(arg, unsigned int);
	return (putnbr_base(nbr, "0123456789abcdef"));
}

int	print_nbr_hexup(va_list arg)
{
	unsigned int	nbr;

	nbr = va_arg(arg, unsigned int);
	return (putnbr_base(nbr, "0123456789ABCDEF"));
}

int	print_nbr_un(va_list arg)
{
	unsigned int	nbr;

	nbr = va_arg(arg, unsigned int);
	return (putnbr_base(nbr, "0123456789"));
}
