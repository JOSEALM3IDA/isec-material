#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void sig_handler(int signal, siginfo_t *info, void * extra) {
    int valor = info->si_value.sival_int;

    if (signal == SIGUSR1)
        if(valor == 1)
            printf("Número é menor!\n");
        else if (valor == -1)
            printf("Número é maior!\n");
        else
            printf("Parabéns, não ganhou nada!\n");
}

int main (int argc, char *argv[]) {
    int num;
    union sigval value;
    struct sigaction action;

    setbuf(stdout, NULL);

    if (argc != 2) {
        printf("Falta PID!\n");
    }

    action.sa_flags = SA_RESTART | SA_SIGINFO; // Inicializar as flags
    action.sa_sigaction = sig_handler; //Registar função

    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        printf("Erro ao colocar a função ao serviço do sinal.\n");
        exit(0);
    }

    while (1) {
        printf("Tentativa: ");
        scanf("%d", &num);
        value.sival_int = num;
        sigqueue(atoi(argv[1]), SIGUSR1, value);
        sleep(5);
    }

    return 0;
}