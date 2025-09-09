/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:26 by cecompte          #+#    #+#             */
/*   Updated: 2025/04/30 14:37:23 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;
	size_t				i;

	if (src == NULL && dest == NULL)
		return (NULL);
	tmp_dest = dest;
	tmp_src = src;
	if (tmp_dest < tmp_src)
	{
		i = -1;
		while (++i < n)
			tmp_dest[i] = tmp_src[i];
	}
	else
	{
		i = n + 1;
		while (--i > 0)
			tmp_dest[i - 1] = tmp_src[i - 1];
	}
	return (dest);
}
