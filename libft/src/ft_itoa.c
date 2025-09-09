/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:31:12 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/06 11:34:43 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
	{
		n = INT_MIN / 10;
		len++;
	}
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;

	len = count_len(n);
	ptr = malloc (((len + 1) * sizeof(char)));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == INT_MIN)
	{
		ptr[--len] = '8';
		n = n / 10;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n >= 1 || (n == 0 && len == 1 && ptr[0] != '-'))
	{
		ptr[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}
