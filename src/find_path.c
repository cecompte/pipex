/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:54:45 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/25 15:27:48 by cecompte         ###   ########.fr       */
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

static char	**split_dir(char **envp, t_ids *id)
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
	if (!envp[i])
	{
		id->path = 0;
		return (NULL);
	}
	path_all = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	dir = ft_split(path_all, ':');
	free(path_all);
	return (dir);
}

int	try_path(char **cmd, char **envp, t_ids *id)
{
	char	**dir;
	char	*path_cmd;
	int		i;

	if (!cmd[0])
		return (execve("./", cmd, envp));
	if (ft_strchr(cmd[0], '/'))
		return (execve(cmd[0], cmd, envp), exit_free(id, cmd, 127));
	dir = split_dir(envp, id);
	if (!dir && !id->path)
		return (execve(cmd[0], cmd, envp), exit_free(id, cmd, 127));
	else if (!dir && id->path)
		return (free_tab(cmd), exit_close(id, 0, 1));
	i = 0;
	while (dir[i])
	{
		path_cmd = build_path(dir[i], cmd);
		if (!path_cmd)
			return (free_tab(dir), free_tab(cmd), exit_close(id, 0, 1));
		if (access(path_cmd, X_OK) == 0)
			return (free_tab(dir), execve(path_cmd, cmd, envp));
		free(path_cmd);
		i++;
	}
	return (free_tab(dir), 0);
}
