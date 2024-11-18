#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    char file[256];

    printf("File name: ");
    scanf("%255s", file);
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open the file!");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
