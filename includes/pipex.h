/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:15:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/11 18:44:11 by cecompte         ###   ########.fr       */
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
int		*open_files(char **argv);

//find_path
char	*find_path(char **cmd, char **envp, int *fd, int *end);
char	**build_cmd(char *str);

//errors
void	free_tab(char **tab);
int		exit_close(int *fd, int *end);
int		exit_error(void);
void	not_found(int *fd, int *end, char *s);
int		close_all(int *fd, int *end);

//processes
int		child(int *fd, int *end, char **cmd, char **envp);
int		parent(int *fd, int *end, char **cmd, char **envp);

void	print_tab(char **tab);

#endif