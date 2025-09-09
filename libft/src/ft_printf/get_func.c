/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:45:39 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/15 11:33:18 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	(*get_func(char specifier))(va_list arg)
{
	if (specifier == 'c')
		return (print_char);
	else if (specifier == 's')
		return (print_str);
	else if (specifier == 'd' || specifier == 'i')
		return (print_nbr);
	else if (specifier == 'x')
		return (print_nbr_hex);
	else if (specifier == 'X')
		return (print_nbr_hexup);
	else if (specifier == 'u')
		return (print_nbr_un);
	else if (specifier == 'p')
		return (print_memory);
	return (NULL);
}
