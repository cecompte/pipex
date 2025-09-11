/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:58 by user              #+#    #+#             */
/*   Updated: 2025/09/11 16:22:32 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(int fd, int *end, char **argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = build_cmd(argv[2]);
	if (!cmd)
		return (exit_error(1)); // close
	path = find_path(cmd, envp);
	if (!path)
		return (ft_printf("%s: Command not found\n", cmd[0]), // putstr_fd ?
			free_tab(cmd), exit(127), 1);
	if (dup2(fd, 0) < 0)
		return (free_tab(cmd), free(path), exit_error(1));
	if (dup2(end[1], 1) < 0)
		return (free_tab(cmd), free(path), exit_error(1));
	close(end[0]);
	close(fd);
	execve(path, cmd, envp);
	return (free_tab(cmd), free(path), exit_error(1));
}

int	parent(int fd, int *end, char **argv, char **envp)
{
	char	*path;
	char	**cmd;
	
	cmd = build_cmd(argv[3]);
	if (!cmd)
		return (exit_error(1));
	path = find_path(cmd, envp);
	if (!path)
		return (ft_printf("%s: Command not found\n", cmd[0]), 
			free_tab(cmd), exit(127), 1);
	if (dup2(fd, 1) < 0)
		return (free_tab(cmd), free(path), exit_error(1)); //pb because I dont free the other path ?
	if (dup2(end[0], 0) < 0)
		return (free_tab(cmd), free(path), exit_error(1));
	close(end[1]);
	close(fd);
	execve(path, cmd, envp);
	return (free_tab(cmd), free(path), exit_error(1));
}
