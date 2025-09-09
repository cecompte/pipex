/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/09 17:08:15 by cecompte         ###   ########.fr       */
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
	char	*path;
    char 	**args;
	pid_t	child1;
	
	if (argc < 1) {
        return 1;
    } //change that part
	child1 = fork();
	if (child1 < 0)
		return (write(2, strerror(errno), ft_strlen(strerror(errno))), 1);
	args = ft_split(argv[2], ' '); // + malloc error
	path = find_path(args[0], envp); // + malloc error
	fd1 = open(argv[1], O_RDONLY);
	if (!child1)
	{
		dup2(fd1, 0);
		close(fd1);
		execve(path, args, envp);
		perror("execve");
	}
	else
	{
		close(fd1);
		waitpid(child1, &status, 0);
	}
	free(path);
	free_tab(args);
    return 1;
}

