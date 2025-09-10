/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:15:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/10 12:46:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

//find_path
char	*find_path(char *cmd, char **envp);
char	*build_path(char *src, char *cmd);

//errors
void	free_tab(char **tab);
int		exit_error(void);

//processes
int		child(int fd, int *end, char **cmd, char **envp);
int		parent(int fd, int *end, char **cmd, char **envp);

void	print_tab(char **tab);

#endif