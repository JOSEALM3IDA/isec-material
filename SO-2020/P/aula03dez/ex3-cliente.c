#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SERV_PIPE "serv_pipe"

int fd_w, fd_r, fd_serv;

void sair(int rtn) {
    char buff[16];

    close(fd_serv);
    close(fd_w);
    close(fd_r);

    sprintf(buff, "%d_w", getpid());
    unlink(buff);
    sprintf(buff, "%d_r", getpid());
    unlink(buff);

    exit(rtn);
}


int main() {
    int n1, n2, n;
    char buff[256], op;

    setbuf(stdout, NULL);

    printf("[CLI] Vou abrir pipe do servidor...\n");
    fd_serv = open(SERV_PIPE, O_WRONLY); // Abrir pipe do servidor
    if (fd_serv == -1) {
        fprintf(stderr, "Erro a abrir o pipe do servidor! Talvez o servidor não esteja a correr?\n");
        sair(-1);
    }

    printf("[CLI] Pipe do servidor aberto, vou criar e abrir os meus pipes...\n");
    sprintf(buff, "%d_w", getpid());
    if (mkfifo(buff, 0777) == -1) {
        fprintf(stderr, "Erro a construir o meu pipe de escrita!\n");
        sair(-1);
    }

    fd_w = open(buff, O_RDWR);
    if (fd_w == -1) {
        fprintf(stderr, "Erro a abrir o meu pipe de escrita!\n");

        sair(-1);
    }

    sprintf(buff, "%d_r", getpid());
    if (mkfifo(buff, 0777) == -1) {
        fprintf(stderr, "Erro a construir o meu pipe de leitura!\n");

        sair(-1);
    }

    fd_r = open(buff, O_RDWR);
    if (fd_r == -1) {
        fprintf(stderr, "Erro a abrir o meu pipe de leitura!\n");

        sair(-1);
    }

    printf("[CLI] Pipes criados e abertos com sucesso. Vou enviar o meu PID -%d- ao servidor...\n", getpid());
    sprintf(buff, "%d", getpid());
    n = write(fd_serv, buff, strlen(buff) + 1);
    if (n == -1) {
        fprintf(stderr, "Erro a escrever no pipe do servidor!\n");
        sair(-1);
    }

    while (1) {
        printf("[CLI] Insira a operação: ");
        scanf(" %d %c %d", &n1, &op, &n2);

        if (n1 == 0 && n2 == 0)
            sair(0);

        // Verificações do input...

        sprintf(buff, "%d %c %d", n1, op, n2);
        printf("[CLI] Vou enviar ao servidor: -%s-\n", buff);
        n = write(fd_w, buff, strlen(buff) + 1);
        if (n == -1) {
            fprintf(stderr, "Erro a escrever no meu pipe de escrita!\n");
            sair(-1);
        }
        
        n = read(fd_r, buff, sizeof(buff) - 1); // Ler do pipe fd1
        buff[n - 1] = '\0';
        printf("[CLI] Lidos %i bytes do meu pipe de leitura: -%s-.\n", n, buff);
    }

    sair(0);
}
