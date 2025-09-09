/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:39:43 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/12 11:39:39 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char x, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (x == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_to_trim(char const *s1, char const *set)
{
	int	count;
	int	i;
	int	k;

	i = 0;
	count = 0;
	while (is_in_set(s1[i], set))
	{
		count++;
		i++;
	}
	k = 0;
	while (s1[i])
	{
		if (is_in_set(s1[i], set) && !k)
			k = i;
		else if (!is_in_set(s1[i], set))
			k = 0;
		i++;
	}
	if (!k)
		k = ft_strlen(s1);
	return (count + ft_strlen(s1) - k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		k;

	if (!ft_strlen(set) || !count_to_trim(s1, set))
		return (ft_strdup(s1));
	ptr = malloc(ft_strlen(s1) - count_to_trim(s1, set) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (is_in_set(s1[i++], set))
		k++;
	ft_strlcpy(ptr, s1 + k, ft_strlen(s1 + k) - count_to_trim(s1 + k, set) + 1);
	return (ptr);
}
