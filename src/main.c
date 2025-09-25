/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/25 15:38:09 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_ids *id, char **argv)
{
	init(id);
	if (access(argv[1], R_OK) != 0)
	{
		id->infile = 0;
		error(argv[1]);
		id->fd[0] = open("/dev/null", O_RDONLY);
	}
	else
		id->fd[0] = open(argv[1], O_RDONLY);
	if (id->fd[0] < 0)
		exit_close(id, 0, 1);
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) != 0)
	{
		id->outfile = 0;
		error(argv[4]);
		if (!id->infile)
			return (close(id->fd[0]), exit(1));
	}
	else
	{
		id->fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (id->fd[1] < 0)
			exit_close(id, 0, 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_ids	id;

	if (argc != 5)
		return (ft_putstr_fd("Wrong nb of arguments\n", 2), 1);
	open_files(&id, argv);
	pipe(id.end);
	id.child1 = fork();
	if (id.child1 < 0)
		return (exit_close(&id, 0, 1));
	else if (id.child1 == 0)
		child_one(argv, envp, &id);
	else
	{
		id.child2 = fork();
		if (id.child2 < 0)
			exit_close(&id, 0, 1);
		else if (id.child2 == 0)
			child_two(argv, envp, &id);
		return (parent(&id));
	}
}

// int	main(int argc, char **argv, char **envp)
// {
// 	char	*cmd[] = {"cat", NULL};
// 	if (argc == 0 && !argv[1])
// 		return (0);
// 	execve("cat", cmd, envp);
// 	perror("execve failed");
// 	exit(0);
// }
/* to do 
- wrong command in right part of the pipe -> wrong exit code
- wrong flag -> wrong exit code
- add another fork : ./pipex Makefile "sleep 5" "sleep 2" outfile
- command in this form /bin/cat
*/
