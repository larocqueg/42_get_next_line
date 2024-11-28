#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
    int fd;
    char *line;
	(void)ac;
    //char file[256];

    //printf("File name: ");
    //scanf("%255s", file);
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
