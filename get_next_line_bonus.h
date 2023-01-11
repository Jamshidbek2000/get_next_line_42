/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:52 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/11 10:02:59 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct t_file_obj
{
	int		new_line_index;
	int		fd;
}t_file_obj;

char		*get_next_line(int fd);

int			containts_new_line(char *str);;
t_file_obj	*get_t_file_obj(int new_fd);
size_t		gn_strlen(const char *s);
char		*ft_strjoin_free_1(char *s1, char *s2);
char		*ft_strndup2(char *str, int start, int end);

#endif