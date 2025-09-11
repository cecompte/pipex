/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/11 18:03:28 by cecompte         ###   ########.fr       */
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
int		*open_files(char **argv)
{
	int *fd;

	fd = malloc(2 *sizeof(int));
	if (!fd)
		exit_error();
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		exit_error();
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[1] < 0)
		exit_close(fd, 0);
	return (fd);
}

int main(int argc, char **argv, char **envp)
{
	int		status;
	int		*fd;
	pid_t	pid;
	int		end[2];
	
	if (argc != 5)
		return (ft_printf("Wrong nb of arguments\n"));
	fd = open_files(argv);
	pipe(end);
	pid = fork();
	if (pid < 0)
		return (exit_close(fd, end));
	if (pid == 0)
		child(fd, end, argv, envp);
	else
	{
		waitpid(pid, &status, 0);
		parent(fd, end, argv, envp);
	}
}

/* to do 
- command : infile "  " cat outfile returns Success
- check if all fds close properly : valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all 
- add another fork : ./pipex Makefile "sleep 5" "sleep 2" outfile
*/
