/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/09 17:44:48 by cecompte         ###   ########.fr       */
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
	char	*path;
    char 	**cmd1_args;
	pid_t	parent;
	
	if (argc < 1) {
        return 1;
    } //change that part
	
	//
	fd1 = open(argv[1], O_RDONLY); // + open error
	fd2 = open(argv[3], O_CREAT | O_RDWR | O_TRUNC, 0644); // + open error
	
	// make a pipe + fds go in pipefd[0] and pipefd[1]

	parent = fork();
	
	if (parent < 0)
		return (write(2, strerror(errno), ft_strlen(strerror(errno))), 1);

	cmd1_args = ft_split(argv[2], ' '); // + malloc error
	path = find_path(cmd1_args[0], envp); // + malloc error
	if (!parent)
	{
		dup2(fd1, 0); // + protect if dup2 < 0
		dup2(fd2, 1); // protect
		close(fd1);
		close(fd2);
		execve(path, cmd1_args, envp);
		perror("execve");
	}
	else
	{
		close(fd1);
		close(fd2);
		waitpid(parent, &status, 0);
	}
	free(path);
	free_tab(cmd1_args);
    return 1;
}

