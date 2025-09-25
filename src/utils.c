/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:25:33 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/25 15:26:28 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_ids	*id)
{
	id->child1 = 0;
	id->child2 = 0;
	id->infile = 1;
	id->outfile = 1;
	id->fd[0] = -1;
	id->fd[1] = -1;
	id->end[0] = -1;
	id->end[1] = -1;
	id->path = 1;
}

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
