#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void sig_handler(int signal, siginfo_t *info, void * extra) {
    int valor = info->si_value.sival_int;
    int pid = info->si_pid;
    static count = 0;

    printf("Recebi signal: %d, número [%d], do processo com o pid %i.\n", signal, valor, pid);
    if (signal == SIGINT) {
        if(++count == 5) {
            printf("\nOk pronto");
            exit;
        } else {
            printf("[%i] Ai!\n", count);
        }
    }
}

int main (void) {
    if (signal(SIGALRM, sig_handler) == SIG_ERR)
        printf("\nErro ao colocar a função ao serviço do sinal.");
    

    return 0;
}