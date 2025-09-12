/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:18:21 by user              #+#    #+#             */
/*   Updated: 2025/09/12 12:58:19 by cecompte         ###   ########.fr       */
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

int	exit_error(void)
{
	perror(NULL);
	exit(1);
	return (1);
}
int	close_all(int *fd, int *end)
{
	if (fd)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (end)
	{
		close(end[0]);
		close(end[1]);
	}
	return (1);
}

int	exit_close(int *fd, int *end)
{
	perror(NULL);
	close_all(fd, end);
	free(fd);
	exit(1);
	return (1);
}

int	not_found(int *fd, int *end, char **cmd)
{
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	close_all(fd, end);
	free_tab(cmd);
	free(fd);
	exit(127);
	return(1);
}