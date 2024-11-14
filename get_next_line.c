/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:40:39 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/14 16:15:38 by gde-la-r         ###   ########.fr       */
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
	ssize_t	r_content;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	r_content = 1;
	while (file[i] != '\n' && r_content > 0)
	{
		r_content = read(fd, file, BUFFER_SIZE);
		if (r_content  = -1)
			return (free(buffer), NULL);
		buffer[r_content] = '\0';
		file = ft_strjoin(file, buffer);
		if (!file)
			return (free(file), free(buffer), NULL);
	}
	free(buffer);
	return (file);
}

static char	*ft_get_line(char *buffer)
{
}

static char	*ft_update_line(char *buffer)
{
}
