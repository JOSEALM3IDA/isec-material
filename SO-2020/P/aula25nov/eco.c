#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MYPIPE "pipeSO"

void sig_handler(int signal, siginfo_t *info, void *extra) {
    if (signal == SIGINT) {
        exit(0);
    }
}

int main (void) {
    int fd1, n;
    char str[256];
    struct sigaction action;
    // fd_set rfds; // para select

    setbuf(stdout, NULL);

    mkfifo(MYPIPE, 0777);

    action.sa_flags = SA_RESTART | SA_SIGINFO; // Inicializar as flags
    action.sa_sigaction = sig_handler; // Registar função

    if (sigaction(SIGINT, &action, NULL) == -1) {
        printf("\nErro ao colocar a função ao serviço do sinal.");
        exit(0);
    }
    
    do {
        fd1 = open(MYPIPE, O_RDONLY); // Abrir pipe com permissões de leitura
        n = read(fd1, str, sizeof(str) - 1); // Ler do pipe
        str[n - 1] = '\0';
        printf("[ECO] Lido %i bytes do pipe: -%s-.\n", n, str);

        close(fd1);
    } while (strcmp(str, "sair"));

    unlink(MYPIPE);
    return 0;
}