/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:58 by user              #+#    #+#             */
/*   Updated: 2025/09/11 17:55:13 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(int *fd, int *end, char **argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = build_cmd(argv[2]);
	if (!cmd)
		return (exit_close(fd, end)); // close
	path = find_path(cmd, envp, fd, end);
	if (!path)
		return (not_found(fd, end, cmd[0]), free_tab(cmd), exit(127), 1);
	if (dup2(fd[0], 0) < 0)
		return (free_tab(cmd), free(path), exit_close(fd, end));
	if (dup2(end[1], 1) < 0)
		return (free_tab(cmd), free(path), exit_close(fd, end));
	close(end[0]);
	close(fd[0]);
	execve(path, cmd, envp);
	return (free_tab(cmd), free(path), exit_error());
}

int	parent(int *fd, int *end, char **argv, char **envp)
{
	char	*path;
	char	**cmd;
	
	cmd = build_cmd(argv[3]);
	if (!cmd)
		return (exit_close(fd, end));
	path = find_path(cmd, envp, fd, end);
	if (!path)
		return (not_found(fd, end, cmd[0]), free_tab(cmd), exit(127), 1);
	if (dup2(fd[1], 1) < 0)
		return (free_tab(cmd), free(path), exit_close(fd, end));
	if (dup2(end[0], 0) < 0)
		return (free_tab(cmd), free(path), exit_close(fd, end));
	close(end[1]);
	close(fd[1]);
	execve(path, cmd, envp);
	return (free_tab(cmd), free(path), exit_error());
}
