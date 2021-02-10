#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 16

#define P_ESQ "esq"
#define P_DIR "dir"

typedef struct {
    int fd;
    int cancel;
    char nomePipe[BUFFSIZE];
} ARGSTRUCT;

int fd_esq, fd_dir;
ARGSTRUCT as[2];
pthread_t th[2];

void sig_handler(int signal, siginfo_t *info, void *extra) {
    if (signal == SIGINT) {
        printf("Recebido SIGINT! A fechar ordeiramente...\n");

        as[0].cancel = as[1].cancel = 1; // pedir as threads para sair
        pthread_join(th[0], NULL); // esperar que a thread 0 acabe
        pthread_join(th[1], NULL); // esperar que a thread 1 acabe

        close(fd_esq);
        close(fd_dir);
        unlink(P_ESQ);
        unlink(P_DIR);
        exit(0);
    }
}

void *atender(void *arg) {
    ARGSTRUCT *as = (ARGSTRUCT *)arg;
    int n;
    char buff[BUFFSIZE];

    while (!as->cancel) {
        if ((n = read(as->fd, buff, BUFFSIZE - 1)) == -1) {
            fprintf(stderr, "Impossivel ler do pipe %s!\n", as->nomePipe);
            return NULL;
        }

        buff[n] = '\0';

        printf("%s - %s\n", as->nomePipe, buff);
    }

    return NULL;
}

void main() {
    char str[BUFFSIZE];
    struct sigaction action;

    action.sa_flags = SA_RESTART | SA_SIGINFO; // Inicializar as flags
    action.sa_sigaction = sig_handler; //Registar função

    if (sigaction(SIGINT, &action, NULL) == -1) {
        printf("Erro ao colocar a função ao serviço do sinal.\n");
        exit(0);
    }

    setbuf(stdout, NULL);

    if (mkfifo(P_ESQ, 0777) == -1) {
        fprintf(stderr, "Erro a criar o pipe esquerdo.\n");
        exit(-1);
    }

    if (mkfifo(P_DIR, 0777) == -1) {
        fprintf(stderr, "Erro a criar o pipe direito.\n");
        unlink(P_ESQ);
        exit(-1);
    }

    if ((fd_esq = open(P_ESQ, O_RDWR)) == -1) {
        fprintf(stderr, "Erro a abrir o pipe esquerdo.\n");
        unlink(P_ESQ);
        unlink(P_DIR);
        exit(-1);
    }

    if ((fd_dir = open(P_DIR, O_RDWR)) == -1) {
        fprintf(stderr, "Erro a abrir o pipe direito.\n");
        close(fd_esq);
        unlink(P_ESQ);
        unlink(P_DIR);
        exit(-1);
    }

    as[0].fd = fd_esq;
    strcpy(as[0].nomePipe, P_ESQ);

    as[0].cancel = as[1].cancel = 0;

    as[1].fd = fd_dir;
    strcpy(as[1].nomePipe, P_DIR);

    pthread_create(&th[0], NULL, &atender, &as[0]);
    pthread_create(&th[1], NULL, &atender, &as[1]);
    
    as[0].cancel = 1; // pedir à thread A para sair
    pthread_join(th[0], NULL); // esperar que a thread A acabe

    as[1].cancel = 1; // pedir à thread B para sair
    pthread_join(th[1], NULL); // esperar que a thread B acabe

    unlink(P_ESQ);
    unlink(P_DIR);
    exit(0);
}