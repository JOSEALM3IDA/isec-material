#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MYPIPE1 "pipe1"
#define MYPIPE2 "pipe2"

int main (void) {
    int fd1, fd2, n;
    char str[256];
    fd_set rfds; // para select

    setbuf(stdout, NULL);

    mkfifo(MYPIPE1, 0777);
    
    do {
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);

        fd1 = open(MYPIPE1, O_RDONLY | O_NONBLOCK); // Abrir pipe
        FD_SET(fd1, &rfds); // Adicionar pipe ao conjunto de entradas

        fd2 = open(MYPIPE2, O_RDONLY | O_NONBLOCK); // Abrir pipe
        FD_SET(fd2, &rfds); // Adicionar pipe ao conjunto de entradas

        n = select(max(fd1, fd2)+1, &rfds, NULL, NULL, NULL);

        if (FD_ISSET(fd1, &rfds)) { // Se há dados no pipe, ler pipe
            n = read(fd1, str, sizeof(str) - 1); // Ler do pipe fd1
            str[n - 1] = '\0';
            printf("[ECO2] Lido %i bytes do pipe: -%s-.\n", n, str);
        }

        if (FD_ISSET(fd2, &rfds)) { // Se há dados no pipe, ler pipe
            n = read(fd2, str, sizeof(str) - 1); // Ler do pipe fd1
            str[n - 1] = '\0';
            printf("[ECO2] Lido %i bytes do pipe: -%s-.\n", n, str);
        }

        if (FD_ISSET(STDIN_FILENO, &rfds)) { // Se há dados no pipe, ler pipe
            n = read(fd1, str, sizeof(str) - 1); // Ler do stdin
            str[n - 1] = '\0';
            printf("[ECO2] Lido %i bytes do stdin: -%s-.\n", n, str);
        }

        close(fd1);
    } while (strcmp(str, "sair"));

    unlink(MYPIPE1);
    unline(MYPIPE2);
    return 0;
}
