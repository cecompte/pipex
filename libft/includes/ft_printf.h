/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:32:51 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/15 15:27:24 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_putchar(char x);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int		print_char(va_list arg);
int		print_str(va_list args);
int		putnbr_base(unsigned long nbr, char *base);
int		print_nbr(va_list arg);
int		print_nbr_hex(va_list arg);
int		print_nbr_hexup(va_list arg);
int		print_nbr_un(va_list arg);
int		print_memory(va_list arg);
int		(*get_func(char specifier))(va_list arg);
int		ft_printf(const char *format, ...);

#endif