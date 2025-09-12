/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/12 14:45:53 by cecompte         ###   ########.fr       */
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
void	open_files(int *fd, char **argv)
{
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		exit_error();
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[1] < 0)
		exit_close(fd, 0);
}

int main(int argc, char **argv, char **envp)
{
	int		status;
	int		fd[2];
	pid_t	child1;
	pid_t	child2;
	int		end[2];
	
	if (argc != 5)
		return (ft_printf("Wrong nb of arguments\n"));
	open_files(fd, argv);
	pipe(end);
	child1 = fork();
	child2 = 0;
	if (child1 < 0)
		return (exit_close(fd, end));
	if (child1 == 0)
	{
		child2 = fork();
		child_two(fd, end, argv, envp, child2);
		child_one(fd, end, argv, envp);
	}
	close_all(fd, end);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	int		success;
// 	char	**cmd;
// 	int		fd;

// 	if (argc < 2)
// 		return (1);
// 	fd = open(argv[1], O_RDONLY);
// 	dup2(fd, 0);
// 	close(fd);
// 	cmd = build_cmd(argv[2]);
// 	if (!cmd)
// 		return (exit_error());
// 	success = try_path(cmd, envp);
// 	if (!success)
// 		return (ft_printf("not found"));
// 	return (free_tab(cmd), exit_error());
// }

/* to do 
- no environment
- check if all fds close properly : valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all 
- add another fork : ./pipex Makefile "sleep 5" "sleep 2" outfile
*/
