/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:56:36 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/28 16:56:38 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
    int fd;
    char *line;
    (void)ac;
	
    fd = open(av[1], O_RDONLY);
    if ((line = get_next_line(fd)) == NULL)
	{
		printf("%s\n", line);
		return (-1);
	}
    else
	printf("%s", line);
    free(line);
    line = NULL;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");
    return (0);
}
