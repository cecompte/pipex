/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:15:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/25 13:11:16 by cecompte         ###   ########.fr       */
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
	int		infile;
	int		outfile;
}	t_ids;

//open file
void	open_files(t_ids *id, char **argv);

//find_path
int		try_path(char **cmd, char **envp, t_ids *id);
char	**build_cmd(char *str);

//errors
void	free_tab(char **tab);
int		exit_close(t_ids *id);
void	error(char *error_msg);
int		not_found(char **cmd, t_ids *id);
int		close_all(t_ids *id);

//processes
int		child_one(char **cmd, char **envp, t_ids *id);
int		child_two(char **cmd, char **envp, t_ids *id);

#endif