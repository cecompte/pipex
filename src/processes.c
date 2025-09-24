/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:58 by user              #+#    #+#             */
/*   Updated: 2025/09/24 17:14:38 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_one(char **argv, char **envp, t_ids *id)
{
	int		found;
	char	**cmd;

	if (dup2(id->fd[0], 0) < 0)
		return (exit_close(id));
	if (dup2(id->end[1], 1) < 0)
		return (exit_close(id));
	close_all(id);
	cmd = build_cmd(argv[2]);
	if (!cmd)
		return (exit_close(id));
	found = try_path(cmd, envp, id);
	if (!found)
		return (not_found(cmd, id));
	return (free_tab(cmd), exit_error(1));
}

int	child_two(char **argv, char **envp, t_ids *id)
{
	int		found;
	char	**cmd;

	if (dup2(id->fd[1], 1) < 0)
		return (exit_close(id));
	if (dup2(id->end[0], 0) < 0)
		return (exit_close(id));
	close_all(id);
	cmd = build_cmd(argv[3]);
	if (!cmd)
		return (exit_close(id));
	found = try_path(cmd, envp, id);
	if (!found)
		return (not_found(cmd, id));
	return (free_tab(cmd), exit_error(1));
}
