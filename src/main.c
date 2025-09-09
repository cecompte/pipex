/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/09 16:02:57 by cecompte         ###   ########.fr       */
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

int main(int argc, char **argv, char **envp)
{
	int		status;
	char	*path;
    char 	*file;
    char 	**args;
	pid_t	parent;
	
	if (argc < 3) {
        return 1;
    }
	parent = fork();
	if (parent < 0)
		return (write(2, strerror(errno), ft_strlen(strerror(errno))), 1);
	path = find_path(argv[1], envp);
	if (!path)
		return (!ft_printf("Command not found"));
	file = argv[2];
	args = malloc(argc * sizeof(char *));
	args[0] = path;
	args[1] = file;  // e.g., "infile"
	args[2] = NULL;
	if (!parent)
	{
    	execve(path, args, envp);
		// If execve returns, there was an error
		perror("execve");
	}
	else
	{
		waitpid(parent, &status, 0);
	}
	free(path);
	free(args);
    return 1;
}

