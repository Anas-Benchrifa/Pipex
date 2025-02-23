/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:47:10 by mac               #+#    #+#             */
/*   Updated: 2025/02/23 14:49:39 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

// 			***** Mandatory Part ******
void	ft_strreplace(char *str, char find, char replace);
char	*t_check_path(char **envp, char *cmd_line);
void	e_xecute(char *cmd_line, char **envp);
char	**ft_split(const char *s, char c);
void	no_leaks(char **_free);
void	close_files(int *fd);
void	mistake(void);
void	_perror(void);

#endif