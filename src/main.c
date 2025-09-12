/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/12 15:55:32 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(int *fd, char **argv)
{
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		exit_error();
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[1] < 0)
	{
		close (fd[0]);
		exit_error();
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_ids	id;
	int		status;

	if (argc != 5)
		return (ft_putstr_fd("Wrong nb of arguments\n", 2), 1);
	if (!envp)
		return (ft_putstr_fd("No environment\n", 2), 1);
	open_files(id.fd, argv);
	pipe(id.end);
	id.child1 = fork();
	id.child2 = 0;
	if (id.child1 < 0)
		return (exit_close(id));
	if (id.child1 == 0)
	{
		id.child2 = fork();
		child_two(argv, envp, id);
		child_one(argv, envp, id);
	}
	close_all(id);
	waitpid(id.child1, &status, 0);
	waitpid(id.child2, &status, 0);
}

/* to do 
- no environment
- check if all fds close properly : valgrind --trace-children=yes 
--track-fds=yes --leak-check=full --show-leak-kinds=all 
- add another fork : ./pipex Makefile "sleep 5" "sleep 2" outfile
*/
