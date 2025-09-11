/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:54:45 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/11 12:05:03 by user             ###   ########.fr       */
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
	dir = ft_split(path_all, ':');
	free(path_all);
	i = -1;
	while (dir[++i])
	{
		path_cmd = build_path(dir[i], cmd);
		if (!path_cmd)
			return (free_tab(dir), exit_error(), NULL);
		if (access(path_cmd, X_OK) == 0)
			return (free_tab(dir), path_cmd);
		free(path_cmd);
	}
	return (free_tab(dir), NULL); // specific error when command does not exist
}

// char	*try_path(char **cmd, char **envp)
// {
// 	char	**dir;
// 	char	*path_all;
// 	char	*path_cmd;
// 	int		i;

// 	i = -1;
// 	while (envp[++i])
// 	{
// 		if (ft_strnstr(envp[i], "PATH", 4))
// 			break;
// 	}
// 	path_all = ft_substr(envp[i], 5, ft_strlen(envp[i]));
// 	dir = ft_split(path_all, ':');
// 	free(path_all);
// 	i = 0;
// 	while (dir[i])
// 	{
// 		path_cmd = build_path(dir[i], cmd[0]);
// 		if (!path_cmd)
// 			return (free_tab(dir), path_cmd);
// 		execve(path_cmd, cmd, envp);
// 		free(path_cmd);
// 		i++;
// 	}
// 	return (free_tab(dir), NULL); // specific error when command does not exist
// }
