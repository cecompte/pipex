/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/09 18:39:50 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

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
	char	*path1;
	char	*path2;
    char 	**cmd1;
	char	**cmd2;
	pid_t	child1;
	int		end[2];
	
	if (argc < 1) {
        return 1;
    } //change that part
	
	//
	fd1 = open(argv[1], O_RDONLY); // + open error
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644); // + open error
	
	// make a pipe + fds go in pipefd[0] and pipefd[1]
	pipe(end);
	
	child1 = fork();
	
	cmd1 = ft_split(argv[2], ' '); // + malloc error
	cmd2 = ft_split(argv[3], ' '); // + malloc error
	path1 = find_path(cmd1[0], envp); // + malloc error
	path2 = find_path(cmd2[0], envp); // + malloc error
	
	if (child1 < 0)
		return (write(2, strerror(errno), ft_strlen(strerror(errno))), 1);
	if (!child1)
	{
		dup2(fd1, 0); // + protect if dup2 < 0
		dup2(end[1], 1); // protect
		close(end[0]);
		close(fd1);
		execve(path1, cmd1, envp);
		perror("execve");
	}
	else
	{
		waitpid(child1, &status, 0);
		dup2(fd2, 1);
		dup2(end[0], 0);
		close(end[1]);
		close(fd2);
		execve(path2, cmd2, envp);
		perror("execve");
	}
	// free(path1);
	// free(path2);
	// free_tab(cmd1);
	// free_tab(cmd2);
    return 1;
}

