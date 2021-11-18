/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:04:24 by ytaya             #+#    #+#             */
/*   Updated: 2021/11/19 00:11:07 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_get_line(char **rest, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*rest)[i] != '\n' && (*rest)[i] != '\0')
		i++;
	if ((*rest)[i] == '\n')
	{
		*line = ft_substr(*rest, 0, ++i);
		temp = *rest;
		*rest = ft_strdup(*rest + i);
		free(temp);
	}
	else
	{
		*line = ft_strdup(*rest);
		ft_free(rest);
	}
	if ((*line)[0] == '\0')
		ft_free(line);
}

void	ft_read(int fd, char **rest, char **line, char **buffer)
{
	ssize_t	r;
	char	*temp;

	r = 1;
	while (r && !ft_strchr(*rest, '\n'))
	{
		r = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[r] = '\0';
		temp = *rest;
		*rest = ft_strjoin(temp, *buffer);
		ft_free(&temp);
	}
	ft_free(buffer);
	ft_get_line(rest, line);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		ft_free(&buffer);
		return (NULL);
	}
	if (!rest[fd])
		rest[fd] = ft_strdup("");
	ft_read(fd, &rest[fd], &line, &buffer);
	return (line);
}
