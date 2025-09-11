/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:58 by user              #+#    #+#             */
/*   Updated: 2025/09/11 12:13:00 by user             ###   ########.fr       */
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
	path = find_path(cmd, envp);
	if (!path)
		return (ft_printf("%s: Command not found\n", cmd[0]), free_tab(cmd), 1);
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
	path = find_path(cmd, envp);
	if (!path)
		return (ft_printf("%s: Command not found\n", cmd[0]), free_tab(cmd), 1);
	if (dup2(fd, 1) < 0)
		return (free_tab(cmd), free(path), exit_error()); //pb because I dont free the other path ?
	if (dup2(end[0], 0) < 0)
		return (free_tab(cmd), free(path), exit_error());
	close(end[1]);
	close(fd);
	execve(path, cmd, envp);
	return (free_tab(cmd), free(path), exit_error());
}
