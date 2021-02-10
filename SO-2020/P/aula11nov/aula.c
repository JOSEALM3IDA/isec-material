#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

static int r = 20;

void sig_handler(int signal) {
    if (signal != SIGALRM)
        return;

    printf("\nPassaram %i segundos.", r);
    alarm(r--);
}

int main (void) {
    char a = 0;

    if (signal(SIGALRM, sig_handler) == SIG_ERR)
        printf("\nErro ao colocar a função ao serviço do sinal.");
    
    printf("\nIndique o tempo de espera: ");
    fflush(stdout);
    scanf("%i", &r);

    alarm(r--);

    do {
        printf("\nVou aguardar aqui! Pode pressionar uma tecla para acelerar o timer.");
        scanf("%c", &a);

        printf("\nVou chamar o timer!");
        alarm(n--);//sig_handler(SIGALRM);
    } while(1);

    return 0;
}
