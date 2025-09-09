/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:05:49 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/01 11:17:43 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		found;
	int		count;
	char	x;

	i = 0;
	found = 0;
	count = 0;
	x = (char)c;
	while (s[i])
	{
		if (s[i] == x)
		{
			found = 1;
			count = i;
		}
		i++;
	}
	if (x == '\0')
		return ((char *)&s[i]);
	if (found > 0)
		return ((char *)&s[count]);
	return (NULL);
}
