/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:59:42 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/01 10:58:24 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	x;
	size_t			i;

	i = 0;
	x = (unsigned char)c;
	tmp_s = (unsigned char *)s;
	while (i < n)
	{
		if (tmp_s[i] == x)
			return ((void *)&tmp_s[i]);
		i++;
	}
	return (NULL);
}
