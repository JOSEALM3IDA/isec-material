#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio_ext.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "ex4-utils.h"

int main() {
    char nome[STR_SIZE];
    char cmd[STR_SIZE];
    char buff[BUFF_SIZE];
    char fifo[STR_SIZE];
    char pid[STR_SIZE];
    int fd_serv, my_fd, n;

    sprintf(pid, "%d", getpid());

    if ((fd_serv = open(SERV_PIPE, O_WRONLY)) == -1) {
        fprintf(stderr, "ERRO: Impossível contactar com o servidor.\n");
        exit(-1);
    }

    if (mkfifo(pid, 0777) == -1) {
        fprintf(stderr, "ERRO ao criar o meu pipe.\n");
        close(fd_serv);
        exit(-1);
    }

    if ((my_fd = open(pid, O_RDWR)) == -1) {
        fprintf(stderr, "ERRO ao abrir o meu pipe.\n");
        close(fd_serv);
        unlink(pid);
        exit(-1);
    }

    printf("Insira o seu nome: ");
    scanf(" %s", nome);
    __fpurge(stdin);

    while (1) {
        printf("Insira comando: ");
        scanf("%[^\n]", cmd);
        __fpurge(stdin);

        sprintf(buff, "%s %s %s", nome, pid, cmd);

        if (strcmp(cmd, "sair") == 0)
            break;

        // ENVIA COMANDO AO SERVIDOR
        if ((n = write(fd_serv, buff, strlen(buff))) == -1) {
            fprintf(stderr, "ERRO ao falar com o servidor.\n");
            break;
        }

        // LIMPAR BUFFER
        for (n = 0; n < BUFF_SIZE; n++) buff[n] = '\0';

        // ESPERA PELA RESPOSTA DO SERVIDOR E APRESENTA-A
        if ((n = read(my_fd, buff, sizeof(buff) - 1)) == -1) {
            fprintf(stderr, "ERRO ao ouvir do servidor.\n");
            break;
        }
        buff[n] = '\0';

        printf("Servidor: %s\n\n", buff);
    }

    close(fd_serv);
    close(my_fd);
    unlink(pid);
    return 0;
}