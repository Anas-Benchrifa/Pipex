/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:46:14 by mac               #+#    #+#             */
/*   Updated: 2025/02/23 14:46:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_first_child_process(char **argv, char **envp, int *fd)
{
	int	input_file;

	close(fd[0]);
	input_file = open(argv[1], O_RDONLY);
	if (input_file == -1)
		_perror();
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(input_file, STDIN_FILENO);
	close(input_file);
	e_xecute(argv[2], envp);
}

void	handle_second_child_process(char **argv, char **envp, int *fd)
{
	int	output_file;

	close(fd[1]);
	output_file = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!output_file)
		_perror();
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(output_file, STDOUT_FILENO);
	close(output_file);
	e_xecute(argv[3], envp);
}

void	close_files(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid_1;
	pid_t	pid_2;

	if (argc != 5)
		mistake();
	if (pipe(fd) == -1)
		_perror();
	pid_1 = fork();
	if (pid_1 == -1)
		_perror();
	if (pid_1 == 0)
		handle_first_child_process(argv, envp, fd);
	pid_2 = fork();
	if (pid_2 == -1)
		_perror();
	if (pid_2 == 0)
		handle_second_child_process(argv, envp, fd);
	close_files(fd);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
	return (EXIT_SUCCESS);
}
