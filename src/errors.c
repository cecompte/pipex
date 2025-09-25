/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:18:21 by user              #+#    #+#             */
/*   Updated: 2025/09/25 15:26:05 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	ft_putstr_fd("pipex: ", 2);
	perror(msg);
}

int	exit_close(t_ids *id, char *msg, int code)
{
	error(msg);
	close_all(id);
	exit(code);
	return (1);
}

int	exit_free(t_ids *id, char **cmd, int code)
{
	error(cmd[0]);
	free(cmd);
	close_all(id);
	exit(code);
	return (1);
}

int	not_found(char **cmd, t_ids *id)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	close_all(id);
	free_tab(cmd);
	exit(127);
	return (1);
}
