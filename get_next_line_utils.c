/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:46:46 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/17 09:25:20 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file_obj	*get_t_file_obj(int new_fd)
{
	t_file_obj	*file;

	file = malloc(sizeof(t_file_obj));
	if (!file)
		return (NULL);
	file->fd = new_fd;
	return (file);
}

size_t	gn_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*gn_strjoin_free_1(char *s1, char *s2)
{
	size_t	size;
	char	*res;
	size_t	tmp1;
	size_t	tmp2;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	size = gn_strlen(s1) + gn_strlen(s2) + 1;
	res = (char *) malloc(size * sizeof(char));
	if (!res)
		return (NULL);
	tmp1 = -1;
	tmp2 = -1;
	while (s1[++tmp1] != '\0')
		res[tmp1] = s1[tmp1];
	while (s2[++tmp2] != '\0')
		res[tmp1 + tmp2] = s2[tmp2];
	res[tmp1 + tmp2] = '\0';
	free(s1);
	return (res);
}

// The function allocates new str with copies of
// "str" from "start" to "end" indeces
char	*ft_strndup2(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while ((i + start) < end)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	containts_new_line(char *str)
{
	int	index;

	if (str == NULL)
		return (-1);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}
