/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/24 15:48:11 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_ids	*id)
{
	id->child1 = 0;
	id->child2 = 0;
	id->tmp = 0;
}

void	open_files(t_ids *id, char **argv)
{
	init(id);
	if (access(argv[1], F_OK) != 0)
	{
		perror(NULL);
		id->tmp = 1;
	}
	id->fd[0] = open(argv[1], O_CREAT | O_RDONLY);
	if (id->fd[0] < 0)
		exit_error(1);
	id->fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (id->fd[1] < 0)
	{
		close(id->fd[0]);
		if (id->tmp == 1)
			unlink(argv[1]);
		exit_error(1);
	}
}

int	parent(t_ids *id)
{
	int		status1;
	int		status2;

	waitpid(id->child1, &status1, 0);
	waitpid(id->child2, &status2, 0);
	if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
		return(WEXITSTATUS(status2));
	return(0);
}

int	main(int argc, char **argv, char **envp)
{
	t_ids	id;

	if (argc != 5)
		return (ft_putstr_fd("Wrong nb of arguments\n", 2), 1);
	if (!envp)
		return (ft_putstr_fd("No environment\n", 2), 1);
	open_files(&id, argv);
	pipe(id.end);
	id.child1 = fork();
	id.child2 = 0;
	if (id.child1 < 0)
		return (exit_close(&id, argv));
	else if (id.child1 == 0)
		child_one(argv, envp, &id);
	else
	{
		id.child2 = fork();
		if (id.child2 < 0)
			exit_close(&id, argv);
	 	else if (id.child2 == 0)
	 		child_two(argv, envp, &id);
		if (id.tmp == 1)
			unlink(argv[1]);
		close_all(&id);
		return (parent(&id));
	}
}

/* to do 
- no environment
- wrong command in right part of the pipe -> wrong exit code
- wrong flag -> wrong exit code
- infile without permissions
- add another fork : ./pipex Makefile "sleep 5" "sleep 2" outfile
*/
