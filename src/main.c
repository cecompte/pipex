/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/10 12:49:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	int		status;
	int		fd1;
	int		fd2;
    char 	**cmd1;
	char	**cmd2;
	pid_t	pid;
	int		end[2];
	
	if (argc < 1)
		return (ft_printf("Wrong nb of arguments\n"));
	fd1 = open(argv[1], O_RDONLY); // + open error
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644); // + open error
	pipe(end);
	pid = fork();
	cmd1 = ft_split(argv[2], ' '); // + malloc error
	cmd2 = ft_split(argv[3], ' '); // + malloc error
	if (pid < 0)
		return (free_tab(cmd1), free_tab(cmd2), exit_error());
	if (pid == 0)
		child(fd1, end, cmd1, envp);
	else
	{
		waitpid(pid, &status, 0);
		parent(fd2, end, cmd2, envp);
	}
}

