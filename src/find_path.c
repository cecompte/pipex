/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:54:45 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/11 16:38:35 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*build_path(char *src, char **cmd)
{
	char	*path;
	int		len_src;
	int		len_cmd;

	len_src = ft_strlen(src);
	len_cmd = ft_strlen(cmd[0]); // cmd = NULL ?
	path = malloc(len_src + len_cmd + 2);
	if (!path)
		return (NULL);
	ft_strlcpy(path, src, len_src + 1);
	ft_strlcat(path, "/", len_src + 2);
	ft_strlcat(path, cmd[0], len_src + len_cmd + 2);
	return (path);
}

char	*find_path(char **cmd, char **envp)
{
	char	**dir;
	char	*path_all;
	char	*path_cmd;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break;
	}
	path_all = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	dir = ft_split(path_all, ':'); // malloc error
	free(path_all);
	i = -1;
	while (dir[++i])
	{
		path_cmd = build_path(dir[i], cmd);
		if (!path_cmd)
			return (free_tab(dir), exit_error(1), NULL);
		if (access(path_cmd, X_OK) == 0)
			return (free_tab(dir), path_cmd);
		free(path_cmd);
	}
	return (free_tab(dir), NULL);
}

static char	*with_quote(char *str)
{
	char	quote_char;
	int		i;

	quote_char = str[0];
	i = 1;
	while (str[i] != quote_char && str[i] != '\0')
		i++;
	return (ft_strndup(&str[1], i - 1));
}

static char	*without_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (ft_strndup(str, i));
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
			cmd[j] = without_quote(&str[i]);
		if (!cmd[j])
			return (free_tab(cmd), NULL);
		i += ft_strlen(cmd[j++]);
	}
	return (cmd);
}
