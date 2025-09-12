/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:58 by user              #+#    #+#             */
/*   Updated: 2025/09/12 13:01:34 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(int *fd, int *end, char **argv, char **envp)
{
	int		success;
	char	**cmd;

	if (dup2(fd[0], 0) < 0)
		return (exit_close(fd, end));
	if (dup2(end[1], 1) < 0)
		return (exit_close(fd, end));
	close(fd[0]);
	close(end[0]);
	cmd = build_cmd(argv[2]);
	if (!cmd)
		return (exit_close(fd, end));
	success = try_path(cmd, envp, fd, end);
	if (!success)
		return (not_found(fd, end, cmd));
	return (free_tab(cmd), free(fd), exit_error());
}

int	parent(int *fd, int *end, char **argv, char **envp)
{
	int		found;
	char	**cmd;
	
	if (dup2(fd[1], 1) < 0)
		return (exit_close(fd, end));
	if (dup2(end[0], 0) < 0)
		return (exit_close(fd, end));
	close(fd[1]);
	close(end[1]);
	cmd = build_cmd(argv[3]);
	if (!cmd)
		return (exit_close(fd, end));
	found = try_path(cmd, envp, fd, end);
	if (!found)
		return (not_found(fd, end, cmd));
	return (free_tab(cmd), free(fd), exit_error());
}
