/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:22 by jergashe          #+#    #+#             */
/*   Updated: 2022/11/20 14:49:51 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// The function reads BUFFER_SIZE length string from file with fd
// Until the string doesn't have a '\n' 
// Or Until there is something to read()
// And saves what was read to static char "*buff".
// If there is a problem the function frees "buff" and return NULL
char	*ft_read(t_file_obj *file, char *buff)
{
	char	tmp_buffer[BUFFER_SIZE + 1];
	int		read_size;

	read_size = 1;
	while (containts_new_line(buff) == -1 && read_size > 0)
	{
		read_size = read(file->fd, tmp_buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (free(buff), NULL);
		tmp_buffer[read_size] = '\0';
		buff = ft_strjoin(buff, tmp_buffer);
		if (buff == NULL || ft_strlen(buff) == 0)
			return (free(buff), NULL);
	}
	return (buff);
}

// The function returns the part of "buff" until '\n' or '\0'
char	*ft_get_line(t_file_obj *file, char *buff)
{
	char	*tmp;

	if (buff == NULL || ft_strlen(buff) == 0)
		return (NULL);
	file->new_line_index = containts_new_line(buff);
	if (file->new_line_index >= 0)
		return (ft_strndup(buff, 0, file->new_line_index + 1));
	tmp = ft_strndup(buff, 0, ft_strlen(buff));
	return (tmp);
}

// The function returns part after '\n' if it exists
char	*ft_get_rest(t_file_obj *file, char *buff)
{
	char	*tmp;

	tmp = NULL;
	if (buff == NULL || ft_strlen(buff) == 0)
		return (free(buff), NULL);
	if (file->new_line_index != -1)
		tmp = ft_strndup(buff, file->new_line_index + 1, ft_strlen(buff));
	free(buff);
	return (tmp);
}

// The function gets part of file until \n or \0
// under the file descriptor fd
char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	t_file_obj	*file;
	char		*result;

	if (read(fd, NULL, 0) == -1)
		return (free(buff[fd]), buff[fd] = NULL, NULL);
	file = get_t_file_obj(fd);
	buff[fd] = ft_read(file, buff[fd]);
	result = ft_get_line(file, buff[fd]);
	buff[fd] = ft_get_rest(file, buff[fd]);
	free(file);
	return (result);
}
