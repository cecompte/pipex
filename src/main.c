/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:28 by cecompte          #+#    #+#             */
/*   Updated: 2025/09/09 12:49:35 by cecompte         ###   ########.fr       */
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

char	*build_path(char *src, char *cmd)
{
	char	*path;
	int		len_src;
	int		len_cmd;

	len_src = ft_strlen(src);
	len_cmd = ft_strlen(cmd); // cmd = NULL ?
	path = malloc(len_src + len_cmd + 2);
	if (!path)
		return (NULL);
	ft_strlcpy(path, src, len_src + 1);
	ft_strlcat(path, "/", len_src + 2);
	ft_strlcat(path, cmd, len_src + len_cmd + 2);
	return (path);
}

char	*find_path(char *cmd, char **envp)
{
	char	**dir;
	char	*path_all;
	char	*path_cmd;
	int		i;

	// loop through envp to find PATH
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break;
		i++;
	}
	// trim "PATH"
	path_all = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	
	// split into directories using : separator
	dir = ft_split(path_all, ':');
	free(path_all);

	// check if file exists and is executable
	i = 0;
	while (dir[i])
	{
		path_cmd = build_path(dir[i], cmd);
		if (access(path_cmd, X_OK) == 0 || !path_cmd)
			return (free_tab(dir), path_cmd);
		free(path_cmd);
		i++;
	}
	return (free_tab(dir), NULL);
}

int main(int argc, char **argv, char **envp)
{
	char	*path;
    char 	*file;
    char 	**args;
	
	if (argc < 3) {
        return 1;
    }

	path = find_path(argv[1], envp);
	file = argv[2];
	args = malloc(argc * sizeof(char *));
	args[0] = path;
	args[1] = file;  // e.g., "infile"
	args[2] = NULL;

    // Try to execute
    execve(path, args, envp);

    // If execve returns, there was an error
    perror("execve");
	free_tab(args);
	free (path); // wait 
    return 1;
}

