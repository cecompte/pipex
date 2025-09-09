/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/09 12:01:04 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	char	**dir;
	char	*path;
	int		i;

	// loop through envp to find PATH
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break;
		i++;
	}
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	// split into directories using : separator
	dir = ft_split(path, ':');
	free(path);
	return (dir);
	// check if file exists and is executable
}
int main(int argc, char **argv, char **envp)
{
	// char	*cmd;
    // char 	*file;
    // char 	**args;
	int	i;
	char	**dir;
	
	if (argc < 3) {
        return 1;
    }

	// cmd = find_path(argv, envp);
	// file = argv[2];
	// args[0] = cmd;
	// args[1] = file;  // e.g., "infile"

    // // Try to execute
    // execve(cmd, args, envp);

    // // If execve returns, there was an error
    // perror("execve");
	ft_printf("%s\n", argv[1]);

	dir = find_path(envp);
	i = 0;
	while (dir[i])
	{
		ft_printf("%s\n", dir[i]);
		i++;
	}
    return 1;
}

