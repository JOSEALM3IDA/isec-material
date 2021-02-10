#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <math.h>

#define MAX_CLI 3
#define SERV_PIPE "serv_pipe"

int exeOp(char* str, float *rtn) {
    int n1, n2, i;
    char op;
    sscanf(str, "%d %c %d", &n1, &op, &n2);

    switch (op) {
        case '+':
            *rtn = n1 + n2;
            return 1;

        case '-':
            *rtn = n1 - n2;
            return 1;

        case '*':
            *rtn = n1 * n2;
            return 1;

        case '/':
            *rtn = (float)n1 / (float)n2;
            return 1;

        case '^':
            *rtn = 1;
            for (i = 0; i < n2; i++)
                *rtn *= n1;
            return 1;

        case '%':
            *rtn = n1 % n2;
            return 1;

        default:
            return 0;
    }
}

int main() {
    int fd_serv, fd_list_r[MAX_CLI], fd_list_w[MAX_CLI], nClientes = 0, i, n, maxFD = STDIN_FILENO;
    char str[254], temp[256];
    float resp;
    fd_set rfds; // para select

    setbuf(stdout, NULL);

    if (mkfifo(SERV_PIPE, 0777) == -1) {
        fprintf(stderr, "Erro a construir o pipe do servidor! Talvez o servidor já esteja aberto?\n");
        exit(-1);
    }

    fd_serv = open(SERV_PIPE, O_RDWR); // Abrir pipe
    if (fd_serv == -1) {
        fprintf(stderr, "Erro a abrir o pipe do servidor!\n");
        exit(-1);
    }

    printf("[SERV] Pipe aberto!\n");

    do {
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds); // Adicionar pipe ao conjunto de entradas do select
        FD_SET(fd_serv, &rfds);
        
        for (i = 0; i < nClientes; i++) {
            FD_SET(fd_list_w[i], &rfds); // Adicionar pipe ao conjunto de entradas do select
            if (fd_list_w[i] > maxFD)
                maxFD = fd_list_w[i];
        }
        if (STDIN_FILENO > maxFD)
            maxFD = STDIN_FILENO;
        else if (fd_serv > maxFD)
            maxFD = fd_serv;

        printf("[SERV] Estou à cuca...\n");
        n = select(maxFD + 1, &rfds, NULL, NULL, NULL);
        if (n == -1) {
            fprintf(stderr, "Erro no select!\n");
            exit(-1);
        }

        if (FD_ISSET(STDIN_FILENO, &rfds)) { // Se há dados no pipe, ler pipe
            n = read(STDIN_FILENO, str, sizeof(str) - 1); // Ler do stdin
            if (n == -1) {
                printf("[SERV] Erro a ler do stdin!\n");
                continue;
            }
            str[n - 1] = '\0';
            printf("[SERV] Lidos %i bytes do stdin: -%s-.\n", n, str);
        }

        for (i = 0; i < nClientes; i++) {
            if (FD_ISSET(fd_list_w[i], &rfds)) { // Se há dados no pipe, ler pipe
                n = read(fd_list_w[i], str, sizeof(str) - 1);
                if (n == -1) {
                    printf("[SERV] Erro a ler do pipe de um cliente!\n");
                    continue;
                }
                str[n - 1] = '\0';
                printf("[SERV] Lidos %i bytes do pipe de um cliente: -%s-.\n", n, str);

                if (exeOp(str, &resp))
                    sprintf(str, "%.2f", resp);
                else
                    sprintf(str, "OPERAÇÃO INVÁLIDA");
                
                n = write(fd_list_r[i], str, strlen(str) + 1);
                if (n == -1) {
                    printf("[SERV] Erro ao escrever no pipe de um cliente!\n");
                    continue;
                }
            }
        }

        if (FD_ISSET(fd_serv, &rfds)) { // Se há dados no pipe, ler pipe
            n = read(fd_serv, str, sizeof(str) - 1);
            if (n == -1) {
                printf("[SERV] Erro a ler do meu pipe!\n");
                continue;
            }
            
            str[n - 1] = '\0';
            printf("[SERV] Lidos %i bytes do pipe do servidor: -%s-.\n", n, str);

            sprintf(temp, "%s_w", str);
            fd_list_w[nClientes] = open(temp, O_RDONLY); // Abrir pipe
            if (fd_list_w[nClientes] == -1)
                printf("[SERV] Erro a abrir pipe de escrita do cliente! Vou continuar...\n");

            sprintf(temp, "%s_r", str);
            fd_list_r[nClientes] = open(temp, O_WRONLY); // Abrir pipe
            if (fd_list_r[nClientes] == -1)
                printf("[SERV] Erro a abrir pipe de leitura do cliente! Vou continuar...\n");

            nClientes++;
        }

    } while (strcmp(str, "sair"));

    for (i = 0; i < nClientes; i++) { // Fechar todos os pipes de cliente
        close(fd_list_w[i]);
        close(fd_list_r[i]);
    }

    close(fd_serv);
    unlink(SERV_PIPE);
    return 0;
}
