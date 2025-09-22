/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:15:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/22 17:52:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_ids
{
	int		fd[2];
	int		end[2];
	int		child1;
	int		child2;
	int		tmp;
}	t_ids;

//open file
void	open_files(t_ids *id, char **argv);

//find_path
int		try_path(char **argv, char **cmd, char **envp, t_ids id);
char	**build_cmd(char *str);

//errors
void	free_tab(char **tab);
int		exit_close(t_ids id, char **argv);
int		exit_error(int code);
int		not_found(char **argv, char **cmd, t_ids id);
int		close_all(t_ids id);

//processes
int		child_one(char **cmd, char **envp, t_ids id);
int		child_two(char **cmd, char **envp, t_ids id);

#endif