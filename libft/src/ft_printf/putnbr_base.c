/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:54:25 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/15 15:31:33 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (-1);
	while (base[i])
	{
		j = 1 + i;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[i] < 33 || base[i] > 126)
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

int	putnbr_base(unsigned long nbr, char *base)
{
	int				count;
	unsigned long	b;

	count = 0;
	if (is_base(base) == -1)
		return (-1);
	b = ft_strlen(base);
	if (nbr >= b)
		count += putnbr_base(nbr / b, base);
	count += ft_putchar(base[nbr % b]);
	return (count);
}
