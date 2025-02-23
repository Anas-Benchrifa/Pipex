/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:17:04 by mac               #+#    #+#             */
/*   Updated: 2025/02/22 18:34:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../Libft/libft.h"

char	*alloc_free(char *buffer, char *_buffer)
{
	char	*_return;

	_return = ft_strjoin(buffer, _buffer);
	free(buffer);
	return (_return);
}

char	*current_line(char *buffer)
{
	size_t	len_of_line;
	int		index_of_buffer;
	int		index_of_line;
	char	*line;

	if (!buffer)
		return (NULL);
	index_of_buffer = 0;
	len_of_line = ft_strlen(buffer);
	while (buffer[index_of_buffer] && buffer[index_of_buffer] != '\n')
		index_of_buffer++;
	if (!buffer[index_of_buffer])
		return (free(buffer), NULL);
	line = ft_calloc(len_of_line - index_of_buffer, sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	index_of_line = 0;
	index_of_buffer += 1;
	while (buffer[index_of_buffer])
		line[index_of_line++] = buffer[index_of_buffer++];
	free(buffer);
	return (line);
}

char	*rest_of_the_line(char *buffer)
{
	int		_index;
	int		index;
	char	*line;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	line = ft_calloc(index + 2, sizeof(char));
	if (!line)
		return (NULL);
	_index = 0;
	while (_index < index)
	{
		line[_index] = buffer[_index];
		index++;
	}
	if (buffer[index] == '\n')
		line[index++] = '\n';
	free(buffer);
	return (line);
}

char	*_read(char *string, int fd)
{
	char	*buffer;
	int		r_ead;

	if (!string)
		string = ft_calloc(1, sizeof(char));
	if (!string)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(string), NULL);
	r_ead = 1;
	while (r_ead > 0)
	{
		r_ead = read(fd, buffer, BUFFER_SIZE);
		if (r_ead == -1)
			return (free(buffer), free(string), NULL);
		buffer[r_ead] = 0;
		string = alloc_free(string, buffer);
		if (!string)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*_current_line;

	ft_putstr_fd("heredoc> ", 1);
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	buffer[fd] = _read(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	_current_line = current_line(buffer[fd]);
	buffer[fd] = rest_of_the_line(buffer[fd]);
	return (_current_line);
}