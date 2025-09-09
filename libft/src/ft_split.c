/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:31:40 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/06 16:24:17 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	if (!ft_strlen(s))
		return (0);
	count = 0;
	i = 1;
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**cleanup(char **tab, int count)
{
	int	i;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i] && i < count)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		start;
	int		count;
	int		i;

	tab = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (tab == NULL)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[start] != c && s[start] != '\0')
			start++;
		tab[count] = ft_substr(s, i, start - i);
		if (!tab[count++])
			return (cleanup(tab, count - 1));
		i = start;
	}
	return (tab);
}
