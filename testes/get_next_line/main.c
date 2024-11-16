#include <fcntl.h>  // Para a função open()
#include <stdio.h>  // Para printf()
#include "get_next_line.h"

int main(int ac, char **av)
{
    int fd;
    char *line;
	(void)ac;

    // Abre o arquivo em modo leitura
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

    // Lê e imprime cada linha
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Fecha o arquivo
    close(fd);
    return (0);
}

