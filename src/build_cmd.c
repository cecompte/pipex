/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:38:59 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/11 18:48:20 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*with_quote(char *sub)
{
	char	quote_char;
	int		i;

	quote_char = sub[0];
	i = 1;
	while (sub[i] != quote_char && sub[i] != '\0')
		i++;
	return (ft_strndup(&sub[1], i - 1));
}

static char	*without_quote(char *sub, char *str)
{
	int	i;

	i = 0;
	if (!sub[i])
		return (ft_strdup(str));
	while (sub[i] != ' ' && sub[i] != '\0')
		i++;
	return (ft_strndup(sub, i));
}

char	**build_cmd(char *str)
{
	char	**cmd;
	int		i;
	int		j;

	cmd = ft_calloc(100, sizeof(char *));
	if (!cmd)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 39 || str[i] == 34)
		{
			cmd[j] = with_quote(&str[i]);
			i += 2;
		}
		else
			cmd[j] = without_quote(&str[i], str);
		if (!cmd[j])
			return (free_tab(cmd), NULL);
		i += ft_strlen(cmd[j++]);
	}
	return (cmd);
}
