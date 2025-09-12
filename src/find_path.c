/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:54:45 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/12 15:50:40 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*build_path(char *src, char **cmd)
{
	char	*path;
	int		len_src;
	int		len_cmd;

	len_src = ft_strlen(src);
	len_cmd = ft_strlen(cmd[0]);
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

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break ;
		i++;
	}
	path_all = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	dir = ft_split(path_all, ':');
	free(path_all);
	return (dir);
}

int	try_path(char **cmd, char **envp, t_ids id)
{
	char	**dir;
	char	*path_cmd;
	int		i;

	if (!cmd[0])
		return (execve("./", cmd, envp));
	dir = split_dir(envp);
	if (!dir)
		return (free_tab(cmd), exit_close(id));
	i = 0;
	while (dir[i])
	{
		path_cmd = build_path(dir[i], cmd);
		if (!path_cmd)
			return (free_tab(dir), free_tab(cmd), exit_close(id));
		if (access(path_cmd, X_OK) == 0)
			return (free_tab(dir), execve(path_cmd, cmd, envp));
		free(path_cmd);
		i++;
	}
	return (free_tab(dir), 0);
}
