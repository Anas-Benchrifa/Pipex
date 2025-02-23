/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:11:38 by mac               #+#    #+#             */
/*   Updated: 2025/02/23 14:53:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, char *src, int l)
{
	int	index;

	index = -1;
	while (++index < l && src[index])
		dst[index] = src[index];
	dst[index] = '\0';
	return (dst);
}

static int	count_word(char *s, char c)
{
	int	index;
	int	words;

	words = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
			words++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		index_s;
	int		t_check;
	int		index;
	int		start;

	if (!s)
		return (NULL);
	index = 0;
	index_s = 0;
	split = (char **)malloc(sizeof(char *) * (count_word((char *)s, c) + 1));
	if (!split)
		return (NULL);
	
	while (s[index])
	{
		while (s[index] == c)
			index++;
		start = index;
		t_check = 0;
		while (s[index] && s[index] != c)
		{
			if (s[index] == 39)
			{
				index++;
				start = index;
				while (s[index] && s[index] != 125)
					index++;
				if (s[index] == 125)
					index++;
				t_check = 1;
				break ;
			}
			index++;
		}
		if (t_check)
		{
			if (index > start)
			{
				split[index_s] = (char *)malloc(index - start + 1);
				if (!split[index_s])
					return (NULL);
				ft_strncpy(split[index_s++], (char *)&s[start], index - start);
			}
		}
		else if (index > start)
		{
			split[index_s] = (char *)malloc(index - start + 1);
			if (!split[index_s])
				return (NULL);
			ft_strncpy(split[index_s++], (char *)&s[start], index - start);
		}
	}
	split[index_s] = NULL;
	return (split);
}
