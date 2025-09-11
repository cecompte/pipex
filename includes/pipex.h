/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:15:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/11 15:29:13 by cecompte         ###   ########.fr       */
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
char	*find_path(char **cmd, char **envp);
char	*build_path(char *src, char **cmd);
char	**build_cmd(char *str);

//errors
void	free_tab(char **tab);
int		exit_error(int nb);

//processes
int		child(int fd, int *end, char **cmd, char **envp);
int		parent(int fd, int *end, char **cmd, char **envp);

void	print_tab(char **tab);

#endif