#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <string.h>

#define BUFFSIZE 16

int fd;

void sig_handler(int signal, siginfo_t *info, void *extra) {
    if (signal == SIGINT) {
        printf("Recebido SIGINT! A fechar ordeiramente...\n");
        close(fd);
        exit(0);
    }
}

void main(int argc, char **argv) {
    int num;
    char str[BUFFSIZE];
    char buff[BUFFSIZE*2];
    struct sigaction action;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./%s <dir/esq>\n", argv[0]);
        exit(-1);
    }

    action.sa_flags = SA_RESTART | SA_SIGINFO; // Inicializar as flags
    action.sa_sigaction = sig_handler; //Registar função

    if (sigaction(SIGINT, &action, NULL) == -1) {
        printf("Erro ao colocar a função ao serviço do sinal.\n");
        exit(0);
    }
    
    printf("A abrir o pipe...\n");
    if ((fd = open(argv[1], O_WRONLY)) == -1) {
        fprintf(stderr, "Erro a abrir pipe!\n");
        exit(-1);
    }

    printf("Nome: ");
    scanf(" %s", str);

    while (1) {
        printf("Numero: ");
        scanf("%d", &num);

        sprintf(buff, "%s %d", str, num);
        if (write(fd, buff, strlen(buff)) == -1) {
            fprintf(stderr, "Erro na escrita no pipe!\n");
            exit(-1);
        }
    }

    exit(0);
}