/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:18:21 by user              #+#    #+#             */
/*   Updated: 2025/09/12 17:49:06 by cecompte         ###   ########.fr       */
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

int	exit_error(int code)
{
	perror(NULL);
	exit(code);
	return (1);
}

int	close_all(t_ids id)
{
	close(id.fd[0]);
	close(id.fd[1]);
	close(id.end[0]);
	close(id.end[1]);
	return (1);
}

int	exit_close(t_ids id, char **argv)
{
	perror(NULL);
	close_all(id);
	if (id.tmp == 1)
		unlink(argv[1]);
	exit(1);
	return (1);
}

int	not_found(char **argv, char **cmd, t_ids id)
{
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	close_all(id);
	if (id.tmp == 1)
		unlink(argv[1]);
	free_tab(cmd);
	exit (127);
	return (1);
}
