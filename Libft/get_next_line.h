/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:13:46 by mac               #+#    #+#             */
/*   Updated: 2025/02/22 18:17:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include "../Libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <limits.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
//	*****  Main Function.  *******
char	*get_next_line(int fd);

#endif