/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:58 by user              #+#    #+#             */
/*   Updated: 2025/09/25 15:29:24 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_one(char **argv, char **envp, t_ids *id)
{
	int		found;
	char	**cmd;

	if (dup2(id->fd[0], 0) < 0)
		return (exit_close(id, 0, 1));
	if (dup2(id->end[1], 1) < 0)
		return (exit_close(id, 0, 1));
	close_all(id);
	cmd = build_cmd(argv[2]);
	if (!cmd)
		return (exit_close(id, 0, 1));
	found = try_path(cmd, envp, id);
	if (!found)
		return (not_found(cmd, id));
	return (free_tab(cmd), exit_close(id, 0, 1));
}

int	child_two(char **argv, char **envp, t_ids *id)
{
	int		found;
	char	**cmd;

	if (!id->outfile)
		return (close_all(id), exit(1), 1);
	if (dup2(id->fd[1], 1) < 0)
		return (exit_close(id, 0, 1));
	if (dup2(id->end[0], 0) < 0)
		return (exit_close(id, 0, 1));
	close_all(id);
	cmd = build_cmd(argv[3]);
	if (!cmd)
		return (exit_close(id, 0, 1));
	found = try_path(cmd, envp, id);
	if (!found)
		return (not_found(cmd, id));
	return (free_tab(cmd), exit_close(id, 0, 1));
}

int	parent(t_ids *id)
{
	int		status1;
	int		status2;

	close_all(id);
	if (waitpid(id->child1, &status1, 0) < 0)
		return (exit_close(id, 0, 1));
	if (waitpid(id->child2, &status2, 0) < 0)
		return (exit_close(id, 0, 1));
	if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
		return (WEXITSTATUS(status2));
	return (0);
}
