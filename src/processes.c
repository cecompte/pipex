/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:58 by user              #+#    #+#             */
/*   Updated: 2025/09/12 15:54:18 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_one(char **argv, char **envp, t_ids id)
{
	int		success;
	char	**cmd;

	if (dup2(id.fd[0], 0) < 0)
		return (exit_close(id));
	if (dup2(id.end[1], 1) < 0)
		return (exit_close(id));
	close_all(id);
	cmd = build_cmd(argv[2]);
	if (!cmd)
		return (exit_close(id));
	success = try_path(cmd, envp, id);
	if (!success)
		return (not_found(cmd, id));
	return (free_tab(cmd), exit_error());
}

int	child_two(char **argv, char **envp, t_ids id)
{
	int		found;
	char	**cmd;

	if (id.child2 < 0)
		return (exit_close(id));
	else if (id.child2 == 0)
	{
		if (dup2(id.fd[1], 1) < 0)
			return (exit_close(id));
		if (dup2(id.end[0], 0) < 0)
			return (exit_close(id));
		close_all(id);
		cmd = build_cmd(argv[3]);
		if (!cmd)
			return (exit_close(id));
		found = try_path(cmd, envp, id);
		if (!found)
			return (not_found(cmd, id));
		return (free_tab(cmd), exit_error());
	}
	return (1);
}
