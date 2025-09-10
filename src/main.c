/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/10 16:49:49 by cecompte         ###   ########.fr       */
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
	pid_t	pid;
	int		end[2];
	
	if (argc != 5)
		return (ft_printf("Wrong nb of arguments\n"));
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		return (exit_error());
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0)
		return (exit_error());
	pipe(end);
	pid = fork();
	if (pid < 0)
		return (exit_error());
	if (pid == 0)
		child(fd1, end, argv, envp);
	else
	{
		waitpid(pid, &status, 0);
		parent(fd2, end, argv, envp);
	}
}
