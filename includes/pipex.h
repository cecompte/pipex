/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:15:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/12 14:44:21 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

//open file
void	open_files(int *fd, char **argv);

//find_path
int		try_path(char **cmd, char **envp, int *fd, int *end);
char	**build_cmd(char *str);

//errors
void	free_tab(char **tab);
int		exit_close(int *fd, int *end);
int		exit_error(void);
int		not_found(int *fd, int *end, char **cmd);
int		close_all(int *fd, int *end);

//processes
int		child_one(int *fd, int *end, char **cmd, char **envp);
int		child_two(int *fd, int *end, char **cmd, char **envp, int pid);

void	print_tab(char **tab);

#endif