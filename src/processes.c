/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:58 by user              #+#    #+#             */
/*   Updated: 2025/09/10 16:51:27 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(int fd, int *end, char **argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv[2], ' ');
	if (!cmd)
		return (exit_error());
	path = find_path(cmd[0], envp);
	if (!path)
		return (free_tab(cmd), exit_error());
	if (dup2(fd, 0) < 0)
		return (free_tab(cmd), free(path), exit_error());
	if (dup2(end[1], 1) < 0)
		return (free_tab(cmd), free(path), exit_error());
	close(end[0]);
	close(fd);
	execve(path, cmd, envp);
	return (free_tab(cmd), free(path), exit_error());
}

int	parent(int fd, int *end, char **argv, char **envp)
{
	char	*path;
	char	**cmd;
	
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
		return (exit_error());
	path = find_path(cmd[0], envp);
	if (!path)
		return (free_tab(cmd), exit_error()); // path null could be several reasons
	if (dup2(fd, 1) < 0)
		return (free_tab(cmd), free(path), exit_error()); //pb because I dont free the other path ?
	if (dup2(end[0], 0) < 0)
		return (free_tab(cmd), free(path), exit_error());
	close(end[1]);
	close(fd);
	execve(path, cmd, envp);
	return (free_tab(cmd), free(path), exit_error());
}
