#include "cliente.h"
#include "utils.h"

int fd_w = -1, fd_r = -1, fd_arb = -1;
bool continuar;
char pipe_w[STR_SIZE] = {'\0'}, pipe_r[STR_SIZE] = {'\0'};

void sig_handler(int signal, siginfo_t *info, void * extra) {
    putchar('\n');
    if (signal == SIGINT)
        sair(EXIT_QUIT, NULL);
    else if (signal == SIGUSR1)
        sair(EXIT_TRNMT_OVER, NULL);
}

void sair(int exitValue, char* error) {
    char c;
    if (exitValue == EXIT_QUIT)
        write(fd_w, "#QUIT", strlen("#QUIT"));

    if (fd_arb != -1)
        close(fd_arb);

    if (fd_w != -1) {
        close(fd_w);
        unlink(pipe_w);
    }

    if (fd_r != -1) {
        close(fd_r);
        unlink(pipe_r);
    }

    if (exitValue == EXIT_TRNMT_OVER) {
        printf("[CLI] Pretende continuar a jogar (Y/N)? ");
        c = toupper(getchar());

        if (c == 'Y') {
            continuar = true;
            return;
        } else {
            printf("[CLI] Terminado com sucesso.\n");
            exit(0);
        }
    }

    if (exitValue == EXIT_OK || exitValue == EXIT_QUIT) {
        printf("[CLI] Terminado com sucesso.\n");
        exit(0);
    } else if (exitValue == EXIT_TRNMT_OVER) {
        fprintf(stderr, "[CLI] Campeonato terminou.\n");
        exit(EXIT_TRNMT_OVER);
    } else {
        fprintf(stderr, "[CLI] %s\n", error);
        exit(exitValue);
    }
}

int main(int argc, char *argv[]) {
    int pid = getpid(), n;
    int maxFD;
    size_t i;
    struct sigaction action;
    char str[STR_SIZE], buff[BUFF_SIZE], tempBuff[BUFF_SIZE], c;
    char *token;
    fd_set rfds;

    INICIO:
    continuar = false;

    setbuf(stdout, NULL);

    action.sa_flags = SA_RESTART | SA_SIGINFO; // Inicializar as flags
    action.sa_sigaction = sig_handler; //Registar função

    if (sigaction(SIGINT, &action, NULL) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Impossível colocar a função ao serviço do sinal SIGNINT.\n");

    if (sigaction(SIGUSR1, &action, NULL) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Impossível colocar a função ao serviço do sinal SIGUSR1.\n");

    // ABRIR PIPE DO ÁRBITRO
    if ((fd_arb = open(ARB_PIPE, O_WRONLY)) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Impossível de abrir pipe do árbitro. Talvez o árbitro esteja fechado?\n");

    // CRIAR E ABRIR PIPE PARA ESCRITA
    sprintf(pipe_w, "cli%d_r", pid);
    if (mkfifo(pipe_w, 0777) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Impossível de criar o meu pipe para escrita!\n");

    if ((fd_w = open(pipe_w, O_RDWR)) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Impossível de abrir o meu pipe para escrita!\n");


    // CRIAR E ABRIR PIPE PARA LEITURA
    sprintf(pipe_r, "cli%d_w", pid);
    if (mkfifo(pipe_r, 0777) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Impossível de criar o meu pipe para leitura!\n");

    if ((fd_r = open(pipe_r, O_RDWR)) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Impossível de abrir o meu pipe para leitura!\n");
    
    // PEDIR UM NOME ENQUANTO ESTE É INVÁLIDO
    while(1) {
        while (1) {
            printf("[CLI] Qual é o seu nome? ");
            scanf(" %[^\n]s", str);
            __fpurge(stdin);

            for (i = 0; i < strlen(str); i++)
                if (str[i] == ' ') {
                    printf("[CLI] Por favor insira um nome sem espaços!\n");
                    break;
                }

            if (i == strlen(str))
                break;
        }

        // ENVIAR PID AO ÁRBITRO
        sprintf(buff, "%s %d", str, pid);
        if ((n = write(fd_arb, buff, strlen(buff))) == -1)
            sair(EXIT_ERR_MSG, "ERRO: Não foi possível escrever no pipe do árbitro!\n");
        
        limpar(buff, BUFF_SIZE);

        // RECEBER CONFIRMAÇÃO DO ÁRBITRO
        if ((n = read(fd_r, buff, sizeof(buff) - sizeof(char))) == -1)
            sair(EXIT_ERR_MSG, "ERRO: Não foi possível receber resposta do árbitro!\n");

        if (strcmp(buff, OK_STR) == 0)
            break;
        else if (strcmp(buff, EXISTE_STR) == 0) {
            printf("[CLI] Nome já existe! Por favor introduza outro.\n");
            continue;
        } else if (strcmp(buff, ARBITRO_CAMPEONATO_CHEIO) == 0) {
            printf("[CLI] O campeonato já está cheio. Tente novamente mais tarde.\n");
            continue;
        }
    }

    printf("[CLI] Comunicação com o árbitro garantida!\n");
    while (1) {
        if (continuar)
            goto INICIO;

        limpar(buff, sizeof(buff));

        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds); // Adicionar pipe ao conjunto de entradas do select
        FD_SET(fd_r, &rfds);

        maxFD = STDIN_FILENO;
        if (fd_r > maxFD)
            maxFD = fd_r;

        printf("[CLI] Introduz uma palavra (#quit para terminar): ");
        if ((n = select(maxFD + 1, &rfds, NULL, NULL, NULL)) == -1)
            sair(EXIT_ERR_MSG, "ERRO: Falha no select!\n");

        if (FD_ISSET(STDIN_FILENO, &rfds)) { // DADOS VINDOS DO STDIN
            if ((n = read(STDIN_FILENO, buff, sizeof(buff) - sizeof(char))) == -1)
                sair(EXIT_ERR_MSG, "ERRO: Leitura do stdin falhou!\n");

            buff[n - 1] = '\0';
            __fpurge(stdin);

            strcpy(tempBuff, buff);
            toupperString(tempBuff);

            if (strcmp(tempBuff, "#QUIT") == 0)
                sair(EXIT_QUIT, NULL);

            if ((n = write(fd_w, buff, strlen(buff))) == -1)
                sair(EXIT_ERR_MSG, "ERRO: Não foi possível escrever no meu pipe de escrita!\n");

            if ((n = read(fd_r, buff, sizeof(buff) - sizeof(char))) == -1) {
                printf("ERRO: Não foi possível obter resposta do servidor.\n");
            } else {
                buff[n] = '\0';
                printf("[CLI] %s\n", buff);
            }

            buff[0] = '\0';
            continue;
        }

        if (FD_ISSET(fd_r, &rfds)) { // DADOS VINDOS DO PIPE DE LEITURA
            if ((n = read(fd_r, buff, sizeof(buff) - sizeof(char))) == -1)
                sair(EXIT_ERR_MSG, "\n[CLI] Erro a ler do meu pipe de leitura!\n");
            buff[n] = '\0';

            if (buff[0] != '#') { // MOSTRA O RECEBIDO AO CLIENTE
                printf("\n[CLI] %s\n", buff);
            } else { // INTERPRETA O RECEBIDO COMO UM COMANDO
                strcpy(tempBuff, buff);
                token = strtok(tempBuff, " ");

                if (strcmp(tempBuff, ARBITRO_SAIU_STR) == 0) {
                    printf("\n[CLI] O árbitro saiu. Escreva algo para sair.\n");
                    scanf("%*d");
                    sair(EXIT_OK, NULL);
                } else if (strcmp(tempBuff, ARBITRO_MATOU_STR) == 0) {
                    printf("\n[CLI] O árbitro removeu-o do campeonato. Escreva algo para sair.\n");
                    scanf("%*d");
                    sair(EXIT_OK, NULL);
                } else if (strcmp(tempBuff, ARBITRO_SUSPENDEU_STR) == 0) {
                    printf("\n[CLI] O árbitro suspendeu a sua interação com o jogo.\n");
                } else if (strcmp(tempBuff, ARBITRO_RETOMOU_STR) == 0) {
                    printf("\n[CLI] O árbitro retomou a sua interação com o jogo.\n");
                } else if (strcmp(tempBuff, CAMPEONATO_TERMINOU_STR) == 0) {
                    printf("\n[CLI] %s\n", buff + strlen(CAMPEONATO_TERMINOU_STR) + 1);

                    limpar(buff, sizeof(buff));

                    if ((n = read(fd_r, buff, sizeof(buff) - sizeof(char))) == -1)
                        sair(EXIT_ERR_MSG, "\n[CLI] Erro a ler do meu pipe de leitura!\n");
                    
                    buff[n] = '\0';
                    printf("[CLI] %s\n", buff);

                    sleep(10); // ESPERAR RECEÇÃO DO SINAL

                    if (continuar)
                        goto INICIO;
                    else
                        fprintf(stderr, "[CLI] ERRO: Não recebi sinal esperado de fim de campeonato.\n");
                }
            }

            continue;
        }
    }

    sair(EXIT_OK, NULL);
}