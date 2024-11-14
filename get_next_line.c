/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:40:39 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/14 17:36:47 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *buffer);
static char	*ft_get_line(char *buffer);
static char	*ft_update_line(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_update_line(buffer);
	return (line);
}

static char	*ft_read(int fd, char *file)
{
	int		i;
	char	*buffer;
	int		r_content;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	r_content = 1;
	while (r_content > 0)
	{
		r_content = read(fd, file, BUFFER_SIZE);
		if (r_content == -1)
			return (free(buffer), NULL);
		buffer[r_content] = '\0';
		file = ft_strjoin(file, buffer);
		if (!file)
			return (free(file), free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (file);
}

static char	*ft_get_line(char *file)
{
	char	*buffer;
	int		len;
}

static char	*ft_update_line(char *file)
{
	char	*line;
	int		i;

	i = 0;
	if (!file[i])
		return (NULL);
	while (file[i] || file[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (file[i] || file[i] != '\n')
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
