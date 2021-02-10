#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

FILE* fd;
int a;

void sig_handler(int signal, siginfo_t *info, void *extra) {
    int valor = info->si_value.sival_int;
    int pid = info->si_pid;
    union sigval value;
    int num;

    if (signal == SIGUSR2) {
        fclose(fd);
        remove("temp");
        exit(0);
    }
    
    printf("Recebi signal: %d, número [%d], do processo com o pid %i.\n", signal, valor, pid);
    if (signal == SIGUSR1) {
        if(valor < a)
            num = -1;
        else if (valor > a)
            num = 1;
        else {
            num = 0;
            a = rand()%101;
            printf("Novo número: %i\n", a);
        }

        value.sival_int = num;

        sigqueue(pid, SIGUSR1, value);
    }
}

int main (void) {
    if (fork() != 0)
        exit(0);
    int pid = getpid();
    struct sigaction action;

    fd = fopen("temp", "r");
    if (fd != NULL) {
        printf("O servidor já existe!\n");
        exit(0);
    } else
        fd = fopen("temp", "w");

    setbuf(stdout, NULL);

    action.sa_flags = SA_RESTART | SA_SIGINFO; // Inicializar as flags
    action.sa_sigaction = sig_handler; //Registar função

    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        printf("\nErro ao colocar a função ao serviço do sinal.");
        fclose(fd);
        remove("temp");
        exit(0);
    }

    if (sigaction(SIGUSR2, &action, NULL) == -1) {
        printf("\nErro ao colocar a função ao serviço do sinal.");
        fclose(fd);
        remove("temp");
        exit(0);
    }

    srand(time(NULL));

    a = rand()%101;

    printf("\nPID: %i\nNUM: %i\n", pid, a);
    
    while (1) {
        sleep(2);
    }

    return 0;
}