/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:21:34 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/13 11:28:20 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_next_line(int fd);
static char	*ft_line(char *line);
static char	*ft_upfile(char *file);

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, file);
	if (!file)
		return (NULL);
	line = ft_line(file);
	file = ft_upfile(file);
	return (line);
}
