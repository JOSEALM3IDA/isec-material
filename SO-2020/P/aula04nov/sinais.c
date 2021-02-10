#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo) {
    printf("Olá\n");
}

//fez-se o 1, o 2 e o 3 e o 4 e o 5

int main (void) {
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\nErro ao colocar a função de serviço ao SIGINT\n");

    do {
        sleep(1);
    } while(1);

    return 0;
}

/*

*/