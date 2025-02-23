/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:48:01 by mac               #+#    #+#             */
/*   Updated: 2025/02/23 14:48:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	_perror(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	mistake(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", 2);
	ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	exit(EXIT_FAILURE);
}

void	no_leaks(char **_free)
{
	int	index;

	index = -1;
	while (_free[++index])
		free(_free[index]);
	free(_free);
}

char	*t_check_path(char **envp, char *cmd_line)
{
	char	**found_path;
	char	*_path;
	char	*path;
	int		index;

	index = 0;
	while (ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	if (!envp[index])
		return (NULL);
	found_path = ft_split(envp[index] + 5, ':');
	if (!found_path)
		return (NULL);
	index = -1;
	while (found_path[++index])
	{
		_path = ft_strjoin(found_path[index], "/");
		path = ft_strjoin(_path, cmd_line);
		free(_path);
		if (access(path, F_OK) == 0)
			return (free(found_path), path);
		free(path);
	}
	no_leaks(found_path);
	return (NULL);
}

void	e_xecute(char *cmd_line, char **envp)
{
	char	**cmd;
	char	*path;

	printf("all line = %s\n", cmd_line);
	// exit(0);
	cmd = ft_split(cmd_line, ' ');
	if (!cmd)
		_perror();
	if (access(cmd[0], X_OK) == 0)
		path = ft_strdup(cmd[0]);
	else
		path = t_check_path(envp, cmd[0]);
	if (!path)
	{
		ft_putstr_fd("Pipex: Command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		no_leaks(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		no_leaks(cmd);
		_perror();
	}
	
}
