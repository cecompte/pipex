/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:18:21 by user              #+#    #+#             */
/*   Updated: 2025/09/25 11:54:42 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	error(char *error_msg)
{
	ft_putstr_fd("pipex: ", 2);
	perror(error_msg);
}

int	close_all(t_ids *id)
{
	if (id->fd[0] >= 0)
		close(id->fd[0]);
	if (id->fd[1] >= 0)
		close(id->fd[1]);
	if (id->end[0] >= 0)
		close(id->end[0]);
	if (id->end[1] >= 0)
		close(id->end[1]);
	return (1);
}

int	exit_close(t_ids *id)
{
	error(NULL);
	close_all(id);
	exit(1);
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
