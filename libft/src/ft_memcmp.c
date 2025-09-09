/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:21:19 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/12 19:29:08 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*tmp_s1;
	const char	*tmp_s2;
	size_t		i;

	tmp_s1 = s1;
	tmp_s2 = s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)tmp_s1[i] < (unsigned char)tmp_s2[i])
			return (-1);
		if ((unsigned char)tmp_s1[i] > (unsigned char)tmp_s2[i])
			return (1);
		i++;
	}
	return (0);
}
