#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MYPIPE "pipeSO"

int main (void) {
    int fd1, n;
    char str[256];

    do {
        fd1 = open(MYPIPE, O_WRONLY); // Abrir pipe com permissões de escrita

        printf("Introduz uma palavra (sair para terminar): ");
        scanf("%s", str);

        n = write(fd1, str, strlen(str) + 1); // Escrever no pipe, incluindo \0

        printf("Escritos %i bytes em %s: -%s-\n", n, MYPIPE, str);

        close(fd1);
    } while(strcmp(str, "sair"));

    return 0;
}