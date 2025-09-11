/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:54:45 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/11 17:53:38 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*build_path(char *src, char **cmd)
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

static char	**split_dir(char **envp)
{
	char	**dir;
	char	*path_all;
	int		i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break;
		i++;
	}
	path_all = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	dir = ft_split(path_all, ':');
	free(path_all);
	return (dir);
}

char	*find_path(char **cmd, char **envp, int *fd, int *end)
{
	char	**dir;
	char	*path_cmd;
	int		i;

	dir = split_dir(envp);
	if (!dir)
		exit_close(fd, end);
	i = 0;
	while (dir[i])
	{
		path_cmd = build_path(dir[i], cmd);
		if (!path_cmd)
			return (free_tab(dir), exit_close(fd, end), NULL);
		if (access(path_cmd, X_OK) == 0)
			return (free_tab(dir), path_cmd);
		free(path_cmd);
		i++;
	}
	return (free_tab(dir), NULL);
}
