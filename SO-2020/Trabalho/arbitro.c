#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <time.h>
#include <linux/limits.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <dirent.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <pthread.h>

#include "arbitro.h"

int fd_arb, nJogos;
int MAXPLAYERS;
char **listaJogos, *GAMEDIR;
jogador* listaJogadores;
espera *argEspera;

void sig_handler(int signal, siginfo_t *info, void *extra) {
    if (signal == SIGINT)
        sair(EXIT_OK, NULL);
    else if (signal == SIGUSR2) {
        //printf("[ARB-CRON] Tão-me a bater!\n");
        pthread_exit(NULL);
    }
}

void sair(int exitValue, char* error) {
    jogador *temp, *temp2;
    int n, i;
    pthread_t threadCronTemp;

    if (exitValue == EXIT_EARLY) {
        fprintf(stderr, "[ARB] %s", error);
        exit(exitValue);
    }

    // PEDIR PARA AS THREADS TERMINAREM, ESPERAR QUE TERMINEM E LIBERTAR A MEMÓRIA ASSOCIADA
    temp = listaJogadores;
    while (temp != NULL) {
        strcpy(temp->info, ARBITRO_SAIU_STR);
        pthread_mutex_lock(temp->lock);
        temp->sair = true;
        pthread_mutex_unlock(temp->lock);
        pthread_join(temp->th, NULL);
        temp2 = temp;
        temp = temp->prox;
        free(temp2);
    }

    pthread_mutex_lock(argEspera->lock);
    threadCronTemp = argEspera->threadCron;
    if (threadCronTemp != 0) {
        pthread_kill(threadCronTemp, SIGUSR2);
        pthread_mutex_unlock(argEspera->lock);
        pthread_join(threadCronTemp, NULL);
    } else
        pthread_mutex_unlock(argEspera->lock);

    // LIBERTAR MATRIZ DOS JOGOS
    for (i = 0; i < nJogos; i++)
        free(listaJogos[i]);
    free(listaJogos);

    // FECHAR E DESTRUIR PIPE DO ÁRBITRO
    if (fd_arb != -1)
        close(fd_arb);

    unlink(ARB_PIPE);

    if (exitValue == EXIT_OK) {
        printf("[ARB] Terminado com sucesso.\n");
        exit(0);
    } else {
        fprintf(stderr, "[ARB] %s", error);
        exit(exitValue);
    }
}

void sairThread(int errcode, jogador* jog, char* str) {
    jogador* temp = listaJogadores;
    if (errcode != EXIT_EARLY) {
        pthread_mutex_lock(jog->lock);
        // REMOVER JOGADOR DA LISTA LIGADA
        if (jog == listaJogadores) {
            listaJogadores = jog->prox;
        } else {
            while (temp != NULL && temp->prox != jog)
                temp = temp->prox;

            if (temp != NULL)
                temp->prox = jog->prox;
        }
        pthread_mutex_unlock(jog->lock);
    }

    // FECHAR PIPES DO JOGO E SINALIZAR AO JOGO, CASO ABERTO
    if (jog->jogoIO[0] != -1)
        close(jog->jogoIO[0]);
    if (jog->jogoIO[1] != -1)
        close(jog->jogoIO[1]);

    if (errcode != EXIT_EARLY && jog->jogoPID != -1) {
        pthread_mutex_lock(jog->lock);
        jog->score = resultadoJogo(jog);
        sprintf(jog->info, "%s Score final: %d", jog->info, jog->score);
        pthread_mutex_unlock(jog->lock);
    }

    pthread_mutex_lock(jog->lock);
    if (jog->info[0] != '\0') {
        if (write(jog->fd[1], jog->info, strlen(jog->info)) == -1)
            fprintf(stderr, "[ARB-%i] ERRO: Não foi possível avisar o jogador -%s- da saída!\n", (int)syscall(SYS_gettid), jog->nome);
        jog->info[0] = '\0';
    }
    pthread_mutex_unlock(jog->lock);

    // FECHAR PIPES DO JOGADOR, CASO ABERTOS
    if (jog->fd[0] != -1)
        close(jog->fd[0]);

    if (jog->fd[1] != -1)
        close(jog->fd[1]);

    if (errcode == EXIT_TRNMT_OVER) {
        sleep(1); // PARA O CLIENTE TER TEMPO DE LER A INFORMAÇÃO ENVIADA
        kill(jog->PID, SIGUSR1);
    }

    // APRESENTAR AVISO DE SAÍDA
    if (errcode == EXIT_OK || errcode == EXIT_TRNMT_OVER || errcode == EXIT_MEM_FIX)
        printf("[ARB] Jogador -%s- removido com sucesso.\n", jog->nome);
    else
        fprintf(stderr, "[ARB] %s\n", str);

    if (errcode != EXIT_MEM_FIX && errcode != EXIT_TRNMT_OVER)   
        free(jog);

    pthread_exit(NULL);
}

int resultadoJogo(jogador* jog) {
    int wstatus;
    kill(jog->jogoPID, SIGUSR1);
    waitpid(jog->jogoPID, &wstatus, 0);
    jog->jogoPID = -1;
    return WIFSIGNALED(wstatus) || WIFEXITED(wstatus) ? WEXITSTATUS(wstatus) : -10;
}

jogador* existeJogador(char* nome) {
    jogador* temp;
    char nomeU1[STR_SIZE], nomeU2[STR_SIZE];

    strcpy(nomeU1, nome);
    toupperString(nomeU1);

    temp = listaJogadores;
    while (temp != NULL) {
        strcpy(nomeU2, temp->nome);
        toupperString(nomeU2);
        if (strcmp(nomeU2, nomeU1) == 0)
            return temp;

        temp = temp->prox;
    }
    
    return NULL;
}

void interpretaComandoCli(char* str, jogador* j) {
    int n;
    jogador *temp;
    char buff[BUFF_SIZE];
    toupperString(str);

    if (strcmp(str, "#QUIT") == 0) { // COMANDO #QUIT
        printf("[ARB] Jogador -%s- pediu para se desconectar.\n", j->nome);
        sairThread(EXIT_OK, j, NULL);
    } else if (strcmp(str, "#MYGAME") == 0) { // COMANDO #MYGAME
        strcpy(buff, j->jogo);
        if ((n = write(j->fd[1], buff, strlen(buff))) == -1) // ENVIA O NOME DO JOGO
            sairThread(EXIT_ERR_MSG, j, "ERRO: Não foi possível escrever no pipe de um cliente!\n");
    } else {
        strcpy(buff, "ERRO: Comando desconhecido");
        if ((n = write(j->fd[1], buff, strlen(buff))) == -1)
            sairThread(EXIT_ERR_MSG, j, "ERRO: Não foi possível escrever no pipe de um cliente!\n");
    }
}

void interpretaComandoArb(char* str, pthread_mutex_t *lock, int* currState, bool* isTimeCounting) {
    jogador* j;
    int n, i;

    toupperString(str);
    if (strcmp(str, "EXIT") == 0) // COMANDO EXIT: FECHAR ÁRBITRO
        sair(EXIT_OK, NULL);
    else if (strcmp(str, "PLAYERS") == 0) { // COMANDO PLAYERS: LISTAR JOGADORES LIGADOS
        if (listaJogadores != NULL) {
            printf("[ARB] Lista de jogadores ligados: %s", listaJogadores->nome);
            if (listaJogadores->jogoPID != -1)
                printf(" (%s)", listaJogadores->jogo);

            j = listaJogadores->prox;
            while (j != NULL) {
                printf(", %s", j->nome);
                if (j->jogoPID != -1)
                    printf(" (%s)", j->jogo);
                j = j->prox;
            }
        } else
            printf("[ARB] Não existem jogadores ligados.");

        putchar('\n');
    } else if (strcmp(str, "GAMES") == 0) { // COMANDO GAMES - LISTAR TODOS OS JOGOS DISPONÍVEIS
        printf("[ARB] Lista de jogos disponíveis (%i): %s", nJogos, listaJogos[0]);
        for (i = 1; i < nJogos; i++)
            printf(", %s", listaJogos[i]);
        putchar('\n');
    } else if (strcmp(str, "END") == 0) { // COMANDO END - ACABAR CAMPEONATO, SE ESTIVER EM EXECUÇÃO
        if (*currState == 1) {
            terminaCampeonato(lock);
            *currState = 0;
            *isTimeCounting = false;
        } else
            printf("[ARB] O campeonato não se encontra em curso.\n");
    } else if (str[0] == 'K') { // COMANDO K - REMOVER JOGADOR DO CAMPEONATO
        if ((j = existeJogador(str + 1)) != NULL) {
            strcpy(j->info, ARBITRO_MATOU_STR);
            j->sair = true;
            printf("[ARB] A remover jogador -%s-...\n", j->nome);
            pthread_join(j->th, NULL);
            free(j);
        } else {
            printf("[ARB] Jogador -%s- não existe!\n", str + 1);
        }
    } else if (str[0] == 'S') { // COMANDO S - SUSPENDER COMUNICAÇÕES JOGADOR-JOGO
        if ((j = existeJogador(str + 1)) != NULL) {
            strcpy(j->info, ARBITRO_SUSPENDEU_STR);
            if (j->hasComms == true) {
                j->hasComms = false;
                printf("[ARB] Comunicação do jogador -%s- suspendida!\n", str + 1);
            } else
                printf("[ARB] Comunicação do jogador -%s- já está suspendida!\n", str + 1);
        } else {
            printf("[ARB] Jogador -%s- não existe!\n", str + 1);
        }
    } else if (str[0] == 'R') { // COMANDO R - RETOMAR COMUNICAÇÕES JOGADOR-JOGO
        if ((j = existeJogador(str + 1)) != NULL) {
            if (j->hasComms == false) {
                j->hasComms = true;
                printf("[ARB] Comunicação do jogador -%s- retomada!\n", str + 1);
            } else
                printf("[ARB] Comunicação do jogador -%s- já está estabelecida!\n", str + 1);
        } else {
            printf("[ARB] Jogador -%s- não existe!\n", str + 1);
        }
    } else // COMANDO DESCONHECIDO
        printf("[ARB] ERRO: Comando desconhecido!\n");
}

void atribuirJogo(jogador* jog) {
	int i = rand() % nJogos ; // ESCOLHER UM INDEX DA MATRIZ ALEATORIO
    int writepipe[2] = {-1, -1}; // arbitro -> jogo
    int readpipe[2] = {-1, -1}; // jogo -> arbitro
    pid_t fpid;
    char gamePath[BUFF_SIZE];

	strcpy(jog->jogo, listaJogos[i]);
    sprintf(gamePath, "%s/%s", GAMEDIR, jog->jogo);

    // CRIAR PIPES ANÓNIMOS DE COMUNICAÇÃO COM O JOGO
    if (pipe(readpipe) < 0 || pipe(writepipe) < 0)
        sairThread(EXIT_ERR_MSG, jog, "ERRO: Impossível de criar pipes anónimos.");

    fpid = fork();
    if (fpid == -1) { // FORK FALHOU
        sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha no fork!");
    } else if (fpid == 0) { // FILHO: TROCAR STDIN E STDOUT POR PIPES ANONIMOS
        close(readpipe[0]);
        close(STDOUT_FILENO);
        if (dup(readpipe[1]) == -1)
            sairThread(EXIT_ERR_MSG, jog, "ERRO: Impossível redirecionar output do jogo.");
        close(readpipe[1]);

        close(writepipe[1]);
        close(STDIN_FILENO);
        if (dup(writepipe[0]) == -1)
            sairThread(EXIT_ERR_MSG, jog, "ERRO: Impossível redirecionar input do jogo.");
        close(writepipe[0]);
        execl(gamePath, jog->jogo, NULL);

        sairThread(EXIT_ERR_MSG, jog, "ERRO: Programa do jogo não encontrado.");
    }
    // FECHAR FDS INUTILIZADOS NO PAI
    close(readpipe[1]);
    close(writepipe[0]);

    jog->jogoPID = fpid;
    jog->jogoIO[0] = readpipe[0];
    jog->jogoIO[1] = writepipe[1];
}

int countJogadores(pthread_mutex_t* lock) {
    jogador* temp;
    int count = 0;

    pthread_mutex_lock(lock);
    temp = listaJogadores;
    while (temp != NULL) {
        count++;
        temp = temp->prox;
    }
    pthread_mutex_unlock(lock);
    return count;
}

void* threadEsperar(void *arg) {
    sigset_t set;

    sigemptyset(&set);
    sigaddset(&set, SIGINT); // PROIBIR A THREAD DE APANHAR SIGINTS
    if (pthread_sigmask(SIG_BLOCK, &set, NULL) != 0) {
        fprintf(stderr, "ERRO: Não foi possível colocar o SIGMASK numa thread.\n");

        pthread_mutex_lock(argEspera->lock);
        argEspera->isFinished = true;
        argEspera->threadCron = 0;
        pthread_mutex_unlock(argEspera->lock);

        pthread_exit(NULL);
    }
    
    sleep(argEspera->duracao);

    pthread_mutex_lock(argEspera->lock);
    argEspera->isFinished = true;
    argEspera->threadCron = 0;
    pthread_mutex_unlock(argEspera->lock);
}

void* threadJogador(void *arg) {
    jogador* jog = (jogador*)arg, *temp;
    fd_set rfds;
	char pipeName[STR_SIZE];
    struct timeval timeout;
    char buff[BUFF_SIZE], megaBuff[BUFF_SIZE * 2];
	int maxFD, i, n, nJogadores, currState;
    bool isFull = false;
    bool tempBool;
    char *token, *bestNome;
    int bestScore;
    int oldState;
    sigset_t set;

    sigemptyset(&set);
    sigaddset(&set, SIGINT); // PROIBIR A THREAD DE APANHAR SIGINTS
    if (pthread_sigmask(SIG_BLOCK, &set, NULL) != 0)
        sairThread(EXIT_ERR_MSG, jog, "ERRO: Não foi possível colocar o SIGMASK numa thread.\n");

    // INICIALIZAÇÃO DE CAMPOS
    jog->fd[0] = jog->fd[1] = jog->jogoIO[0] = jog->jogoIO[1] = jog->jogoPID = -1;

    // ABRIR PIPE DE LEITURA
    sprintf(pipeName, "cli%d_r", jog->PID);
    if ((jog->fd[0] = open(pipeName, O_RDONLY)) == -1)
        sairThread(EXIT_ERR_MSG, jog, "ERRO: Não foi possível abrir pipe de leitura de um cliente!");

    // ABRIR PIPE DE ESCRITA
    sprintf(pipeName, "cli%d_w", jog->PID);
    if ((jog->fd[1] = open(pipeName, O_WRONLY)) == -1)
        sairThread(EXIT_ERR_MSG, jog, "ERRO: Não foi possível abrir pipe de escrita para um cliente!");
	
    // VERIFICAR SE JÁ EXISTE JOGADOR COM ESSE NOME
	if (existeJogador(jog->nome) != NULL) { // SE EXISTIR, AVISAR O CLIENTE
        if ((n = write(jog->fd[1], EXISTE_STR, strlen(EXISTE_STR))) == -1)
                sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha a escrever no pipe de um cliente!");

        sprintf(buff, "ERRO: Jogador -%s- tentou-se conectar mas já está conectado.", jog->nome);
        
        if (n == -1)
            sairThread(EXIT_ERR_MSG, jog, "ERRO: Não foi possível avisar o cliente!");
        else
            sairThread(EXIT_EARLY, jog, buff);
    }
    
    // VERIFICAR SE O CAMPEONATO ESTÁ CHEIO
    if (countJogadores(jog->lock) == MAXPLAYERS) { // SE ESTIVER CHEIO, AVISAR O CLIENTE
        if ((n = write(jog->fd[1], ARBITRO_CAMPEONATO_CHEIO, strlen(ARBITRO_CAMPEONATO_CHEIO))) == -1)
                sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha a escrever no pipe de um cliente!");

        sprintf(buff, "ERRO: Jogador -%s- tentou-se conectar mas o campeonato está cheio.", jog->nome);
        
        if (n == -1)
            sairThread(EXIT_ERR_MSG, jog, "ERRO: Não foi possível avisar o cliente!");
        else
            sairThread(EXIT_EARLY, jog, buff);
    }

    if (write(jog->fd[1], OK_STR, strlen(OK_STR)) == -1)
        sairThread(EXIT_ERR_MSG, jog, "ERRO: Não foi possível escrever no pipe de um cliente!");
    
    jog->score = jog->jogoPID = -1;
	jog->hasComms = true;
	jog->prox = NULL;

    pthread_mutex_lock(jog->lock);
    jog->sair = false;
    // INSERIR NOVO JOGADOR NA LISTA LIGADA
    if (listaJogadores == NULL)
        listaJogadores = jog;
    else {
        temp = listaJogadores;
        while (temp->prox != NULL)
            temp = temp->prox;
        
        temp->prox = jog;
    }
    pthread_mutex_unlock(jog->lock);

    printf("[ARB] Jogador -%s- juntou-se.\n", jog->nome);

    while (1) {
        pthread_mutex_lock(jog->lock);
        if (jog->sair == 1) {
            pthread_mutex_unlock(jog->lock);
            break;
        }  
        pthread_mutex_unlock(jog->lock);   
        
        // SET TIMEOUT DE 2 SEGUNDOS
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;

        FD_ZERO(&rfds);
        FD_SET(jog->fd[0], &rfds);
        maxFD = jog->fd[0];

        pthread_mutex_lock(jog->lock);
        currState = jog->stateCampeonato;
        pthread_mutex_unlock(jog->lock);

        if (currState == 1) { // SE O CAMPEONATO TIVER COMEÇADO
            atribuirJogo(jog);

            pthread_mutex_lock(jog->lock);
            jog->stateCampeonato = 2;
            pthread_mutex_unlock(jog->lock);

            currState = 2;
        }

        if (currState == 2) { // JOGO A EXECUTAR
            FD_SET(jog->jogoIO[0], &rfds);

            if (jog->jogoIO[0] > maxFD)
                maxFD = jog->jogoIO[0];
        }

        if (select(maxFD + 1, &rfds, NULL, NULL, &timeout) == -1)
            sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha no select!");


        oldState = currState;
        pthread_mutex_lock(jog->lock);
        currState = jog->stateCampeonato;
        tempBool = jog->sair;
        pthread_mutex_unlock(jog->lock);
        
        if (oldState != currState && currState == 3) { // FIM DO CAMPEONATO
            oldState = currState;
            strcpy(buff, "Campeonato chegou ao fim.");
            // FECHAR PIPES DO JOGO E SINALIZAR AO JOGO, CASO ABERTO
            if (jog->jogoIO[0] != -1)
                close(jog->jogoIO[0]);

            if (jog->jogoIO[1] != -1)
                close(jog->jogoIO[1]);

            if (jog->jogoPID != -1) {
                pthread_mutex_lock(jog->lock);
                jog->score = resultadoJogo(jog);
                sprintf(megaBuff, "%s %s Score final: %d", CAMPEONATO_TERMINOU_STR, buff, jog->score);
                pthread_mutex_unlock(jog->lock);
                n = write(jog->fd[1], megaBuff, strlen(megaBuff));
                if (n == -1)
                    sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha ao escrever no pipe do cliente!");

                limpar(buff, sizeof(buff));
                limpar(megaBuff, sizeof(megaBuff));
            }

            while (1) {
                pthread_mutex_lock(jog->lock);
                strcpy(megaBuff, jog->info);
                currState = jog->stateCampeonato;
                jog->info[0] = '\0';
                pthread_mutex_unlock(jog->lock);

                if (currState == 4) { // SE JÁ PUDER CONSULTAR O MELHOR JOGADOR E O SCORE DELE
                    bestNome = strtok(megaBuff, " ");
                    token = strtok(NULL, " ");

                    bestScore = atoi(token);

                    limpar(buff, BUFF_SIZE);
                    sprintf(buff, "Melhor jogador foi -%s-, com pontuação %d", bestNome, bestScore);
                    n = write(jog->fd[1], buff, strlen(buff));
                    if (n == -1)
                        sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha ao escrever no pipe do cliente!");
                    
                    limpar(megaBuff, BUFF_SIZE * 2);
                    sairThread(EXIT_TRNMT_OVER, jog, NULL);
                }
                sleep(1);
            }
        }

        if (tempBool) // jog->sair
            break;

        if (FD_ISSET(jog->fd[0], &rfds)) { // SE O CLIENTE ESCREVEU ALGO NO PIPE
            if ((n = read(jog->fd[0], buff, sizeof(buff) - 2*sizeof(char))) == -1)
                sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha a ler o pipe de um cliente!");

            buff[n + 1] = '\0';

            pthread_mutex_lock(jog->lock);
            tempBool = jog->hasComms;
            pthread_mutex_unlock(jog->lock);

            if (buff[0] == '#') {
                buff[n] = '\0';
                interpretaComandoCli(buff, jog);
            } else {
                if (tempBool) { // COMUNICAÇÕES ATIVAS
                    buff[n] = '\n';
                    n = write(jog->jogoIO[1], buff, strlen(buff));
                    if (n == -1)
                        sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha ao escrever no pipe do jogo!");
                } else { // COMUNICAÇÕES SUSPENSAS
                    strcpy(buff, "Tem as comunicações suspensas, logo a mensagem não foi enviada ao jogo.");
                    n = write(jog->fd[1], buff, strlen(buff));
                    if (n == -1)
                        sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha ao escrever no pipe do cliente!");
                }
            }

            limpar(buff, sizeof(buff));
        } else if (currState == 2 && FD_ISSET(jog->jogoIO[0], &rfds)) { // SE O CAMPEONATO JÁ TIVER COMEÇADO E O JOGO TENHA ESCRITO ALGO NO PIPE
            pthread_mutex_lock(jog->lock);
            tempBool = jog->hasComms;
            pthread_mutex_unlock(jog->lock);
            
            if (tempBool) { // COMUNICAÇÕES ATIVAS
                n = read(jog->jogoIO[0], buff, sizeof(buff) - sizeof(char));
                if (n == -1)
                    sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha a ler do pipe do jogo!");

                buff[n] = '\0';

                n = write(jog->fd[1], buff, sizeof(buff) - sizeof(char));
                if (n == -1)
                    sairThread(EXIT_ERR_MSG, jog, "ERRO: Falha a escrever no pipe do cliente!");
            }

            limpar(buff, BUFF_SIZE);
        }
    }

    sairThread(EXIT_MEM_FIX, jog, NULL);
}

void terminaCampeonato(pthread_mutex_t* lock) {
    pthread_t threadCronTemp;
    jogador *tempJog, *tempJog2;
    char bestPlayer[STR_SIZE] = "ERROR 404";
    int bestScore = -1;
    pthread_mutex_t* lockEspera = argEspera->lock;

    printf("[ARB] O campeonato chegou ao fim.\n");

    pthread_mutex_lock(lockEspera);
    threadCronTemp = argEspera->threadCron;
    pthread_mutex_unlock(lockEspera);

    if (threadCronTemp != 0) { // SE O CRONÓMETRO ESTIVER A CORRER, MATÁ-LO
        pthread_kill(threadCronTemp, SIGUSR2);
        pthread_join(threadCronTemp, NULL);
    }

    pthread_mutex_lock(lock);
    // AVISAR AS THREADS QUE O CAMPEONATO VAI TERMINAR E QUE DEVEM FECHAR O JOGO E RECOLHER O SCORE
    tempJog = listaJogadores;
    while (tempJog != NULL) {
        tempJog->stateCampeonato = 3;
        tempJog = tempJog->prox;
    }
    pthread_mutex_unlock(lock);

    // IR VERIFICANDO SE TODOS OS SCORES ESTÃO DIFERENTES DE -1. SE ALGUM ESTIVER A -1, VOLTAR AO INICIO DA LISTA
    // IR ATUALIZANDO O BESTSCORE E BESTPLAYER E, QUANDO TODOS OS SCORES ESTIVEREM CORRETOS, ENVIAR A TODOS ESSA INFORMAÇÃO
    bestScore = -1;
    pthread_mutex_lock(lock);
    tempJog = listaJogadores;
    pthread_mutex_unlock(lock);
    while (tempJog != NULL) {
        pthread_mutex_lock(lock);
        if (tempJog->score == -1) {
            tempJog = listaJogadores;
            pthread_mutex_unlock(lock);
            sleep(1);
            continue;  
        } else if (tempJog->score > bestScore || bestScore == -1) {
            bestScore = tempJog->score;
            strcpy(bestPlayer, tempJog->nome);
        }

        pthread_mutex_unlock(lock);
        tempJog = tempJog->prox;
        sleep(1);
    }

    pthread_mutex_lock(lock);
    tempJog = listaJogadores;
    pthread_mutex_unlock(lock);
    while (tempJog != NULL) {
        pthread_mutex_lock(lock);
        sprintf(tempJog->info, "%s %d", bestPlayer, bestScore);
        tempJog->stateCampeonato = 4; // AVISAR QUE O CAMPO INFO JÁ ESTÁ CORRETAMENTE PREENCHIDO
        pthread_mutex_unlock(lock);

        pthread_join(tempJog->th, NULL); // ESPERAR QUE AS THREADS ACABEM
        tempJog2 = tempJog;
        tempJog = tempJog->prox;
        free(tempJog2);
    }
}

char** lerDiretorio(char* dir, int* tam) { 
    int i;
    char **temp, **arr = NULL;
    struct dirent *de; 
  
    // opendir RETORNA UM PONTEIRO DO TIPO DIR  
    DIR *dr = opendir(dir); 
  
    if (dr == NULL) // opendir DEVOLVE NULL SE NÃO FOI POSSÍVEL ABRIR O DIRETÓRIO
        sair(EXIT_ERR_MSG, "ERRO: Impossível abrir diretório dos jogos!\n");

    *tam = 0;

    while ((de = readdir(dr)) != NULL)
        if (de->d_type == DT_REG && de->d_name[0] == 'g' && de->d_name[1] == '_') { // VERIFICA SE É UM FICHEIRO REGULAR E SE O SEU NOME COMEÇA POR "g_"
            for (i = strlen(de->d_name) - 1; i >= 0; i--) // SE HOUVER PELO MENOS UM '.' NO NOME, ESTE FICHEIRO JÁ NÃO É CONSIDERADO VÁLIDO
                if (de->d_name[i] == '.')
                    break;

            if (i != -1)
                continue;

            temp = realloc(arr, sizeof(char*) * ((*tam) + 1));
            if (temp == NULL) {
                for(i = 0; i < *tam; i++)
                    free(arr[i]);
                free(arr);
                return NULL;
            }

            arr = temp;

            arr[*tam] = malloc(sizeof(de->d_name));
            strcpy(arr[*tam], de->d_name);

            (*tam)++;
        }
  
    closedir(dr);
    return arr;
}

bool existeDir(char* dir) {
    struct dirent *de;
  
    // opendir RETORNA UM PONTEIRO DO TIPO DIR  
    DIR *dr = opendir(dir); 
  
    if (dr == NULL) // opendir DEVOLVE NULL SE NÃO FOI POSSÍVEL ABRIR O DIRETÓRIO
        return false; // DIRETÓRIO NÃO EXISTE

    return true; // DIRETÓRIO EXISTE
}

int main(int argc, char **argv) {
    char test;
    int i, n, maxFD, currFD;
    pid_t pid;
    jogador *tempJog, *tempJog2;
    struct sigaction action;
    int duracao = 5, tempoEspera = 60;
    char *temp, buff[BUFF_SIZE] = {'\0'}, *token, *nome;
    fd_set rfds;
    pthread_mutex_t lock, lockEspera;
    jogador *novoJog;
    struct timeval timeout;
    int currState = 0;
    bool isFinished = false, isTimeCounting = false;
    pthread_t threadCronTemp;

    srand(time(NULL));

    setbuf(stdout, NULL);

    action.sa_flags = SA_RESTART | SA_SIGINFO; // Inicializar as flags
    action.sa_sigaction = sig_handler; // Registar função

    // CRIAÇÃO DOS LOCKS
    pthread_mutex_init(&lock, NULL);
    pthread_mutex_init(&lockEspera, NULL);

    argEspera = malloc(sizeof(espera));
    argEspera->lock = &lockEspera;
    argEspera->isFinished = false;
    argEspera->threadCron = 0;

    if (sigaction(SIGINT, &action, NULL) == -1)
        sair(EXIT_EARLY, "ERRO: Impossível colocar a função ao serviço do sinal SIGINT.\n");

    if (mkfifo(ARB_PIPE, 0777) == -1)
        sair(EXIT_EARLY, "ERRO: Não foi possível criar pipe do árbitro! Talvez o árbitro já esteja aberto?\n");

    if ((fd_arb = open(ARB_PIPE, O_RDWR)) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Não foi possível abrir pipe do árbitro!\n");

    if ((GAMEDIR = getenv("GAMEDIR")) == NULL)
        GAMEDIR = "./";
    else if (strlen(GAMEDIR) > PATH_MAX || !existeDir(GAMEDIR))
        sair(EXIT_ERR_MSG, "ERRO: O diretório especificado pela variável de ambiente GAMEDIR não existe!\n");
        

    if ((temp = getenv("MAXPLAYERS")) != NULL)
        if (isAbsoluteNumber(temp))
            MAXPLAYERS = atoi(temp);
        else
            sair(EXIT_ERR_MSG, "ERRO: O valor de MAXPLAYERS fornecido não é um inteiro não negativo!\n");
    else
        MAXPLAYERS = MAXPLAYERS_DEFAULT;

    while((test = getopt(argc, argv, "d:t:")) != -1) {
        switch(test) {
            case 'd':
                if (isAbsoluteNumber(optarg))
                    duracao = atoi(optarg);
                else
                    sair(EXIT_ERR_MSG, "ERRO: Argumento de -d não é um número inteiro positivo.\n");
                
                if (*(optarg) == '-')
                    sair(EXIT_ERR_MSG, "ERRO: Argumento de -d desconhecido ou não introduzido.\n");
                break;
            case 't':
                if (isAbsoluteNumber(optarg))
                    tempoEspera = atoi(optarg);
                else
                    sair(EXIT_ERR_MSG, "ERRO: Argumento de -t não é um número inteiro positivo.\n");
                
                if (*(optarg) == '-')
                    sair(EXIT_ERR_MSG, "ERRO: Argumento de -t desconhecido ou não introduzido.\n");
                break;
            case '?':
                if (optopt == 'd' || optopt == 't') {
                    sprintf(buff, "A opção -%c precisa de um argumento.\n", optopt);
                    sair(EXIT_ERR_MSG, buff);
                } else if (isprint(optopt)) {
                    sprintf(buff, "Opção desconhecida '-%c'.\n", optopt);
                    sair(EXIT_ERR_MSG, buff);
                } else {
                    sprintf(buff, "Desconhecido carater de opção '\\x%x'.\n", optopt);
                    sair(EXIT_ERR_MSG, buff);
                }
                break;

            default:
                sair(EXIT_ERR_MSG, "ERRO: DESCONHECIDO\n");
        }
    }

    printf("[ARB] GAMEDIR: %s\tMAXPLAYERS: %d\n", GAMEDIR, MAXPLAYERS);
    printf("[ARB] Duração: %dm\tTempo de Espera: %ds\n", duracao, tempoEspera);

    for (i = optind; i < argc; i++)
        printf("[ARB] Restantes argumentos: %s\n", argv[i]);

    listaJogos = lerDiretorio(GAMEDIR, &nJogos);
    if (nJogos == 0)
        sair(EXIT_ERR_MSG, "ERRO: Não existem jogos!\n");
    
    if (MAXPLAYERS < 2)
        sair(EXIT_ERR_MSG, "ERRO: O valor de MAXPLAYERS fornecido deve ser maior que 2!\n");

    if (sigaction(SIGUSR2, &action, NULL) == -1)
        sair(EXIT_ERR_MSG, "ERRO: Impossível colocar a função ao serviço do sinal SIGUSR2.\n");

    printf("[ARB] Estou à cuca...\n");
	while (1) {
        // INICIALIZAR TIMEOUT PARA 3 SEGUNDOS
        timeout.tv_sec = 3;
        timeout.tv_usec = 0;

        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);
        FD_SET(fd_arb, &rfds);
        
        maxFD = STDIN_FILENO;
        
        if (fd_arb > maxFD)
            maxFD = fd_arb;

        if ((n = select(maxFD + 1, &rfds, NULL, NULL, &timeout)) == -1)
            sair(EXIT_ERR_MSG, "ERRO: Falha no select!\n");

        if (FD_ISSET(STDIN_FILENO, &rfds)) { // DADOS NO STDIN
            if ((n = read(STDIN_FILENO, buff, sizeof(buff) - sizeof(char))) == -1)
                sair(EXIT_ERR_MSG, "ERRO: Falha a ler do stdin!\n");

            buff[n - 1] = '\0';
            interpretaComandoArb(buff, &lock, &currState, &isTimeCounting);
            continue;
        }

        if (FD_ISSET(fd_arb, &rfds)) { // DADOS NO PIPE DO ÁRBITRO
            if ((n = read(fd_arb, buff, sizeof(buff) - sizeof(char))) == -1)
                sair(EXIT_ERR_MSG, "ERRO: Falha a ler do meu pipe!\n");
            
            buff[n] = '\0';

            nome = strtok(buff, " ");
            temp = strtok(NULL, " ");

            if (isAbsoluteNumber(temp)) {
                pid = atoi(temp);

                novoJog = malloc(sizeof(jogador));
                if (novoJog == NULL)
                    sair(EXIT_ERR_MSG, "ERRO: Impossivel de alocar memoria para a nova thread!\n");

                strcpy(novoJog->nome, nome);
                novoJog->PID = pid;
                novoJog->lock = &lock;
                novoJog->stateCampeonato = currState;

                pthread_create(&(novoJog->th), NULL, &threadJogador, novoJog);
            }

            continue;
        }

        pthread_mutex_lock(&lockEspera);
        isFinished = argEspera->isFinished;
        pthread_mutex_unlock(&lockEspera);

        // MATAR CRONOMETRO SE ESTE ESTIVER A CORRER E NAO HOUVEREM PLAYERS SUFICIENTES
        if (currState == 0 && isTimeCounting && countJogadores(&lock) < 2) {
            pthread_mutex_lock(&lockEspera);
            threadCronTemp = argEspera->threadCron;
            pthread_mutex_unlock(&lockEspera);

            if (threadCronTemp != 0) {
                pthread_kill(threadCronTemp, SIGUSR2);
                pthread_join(threadCronTemp, NULL);
            }

            printf("[ARB] Não há jogadores suficientes. Temporizador de início de campeonato desativado.\n");
            
            argEspera->isFinished = false;
            isTimeCounting = false;
        }


        // SE ESTIVEREM JOGADORES SUFICIENTES LIGADOS, COMEÇAR CRONÓMETRO
        if (currState == 0 && !isTimeCounting && countJogadores(&lock) > 1) {
            argEspera->duracao = tempoEspera;
            argEspera->isFinished = false;
            if (pthread_create(&(argEspera->threadCron), NULL, &threadEsperar, NULL) != 0)
                sair(EXIT_ERR_MSG, "ERRO: Impossível criar a thread de cronómetro.");

            printf("[ARB] O campeonato começará dentro de %d segundos.\n", tempoEspera);
            isTimeCounting = true;
        }

        if (currState == 0 && isFinished && isTimeCounting && countJogadores(&lock) > 1) { // TEMPO DE ESPERA POR JOGADORES ACABOU
            printf("[ARB] O tempo de espera por jogadores acabou. O campeonato vai começar.\n");
            currState = 1;

            pthread_mutex_lock(&lock);
            tempJog = listaJogadores;
            while (tempJog != NULL) {
                tempJog->stateCampeonato = 1;
                tempJog = tempJog->prox;
            }
            pthread_mutex_unlock(&lock);

            pthread_mutex_lock(&lockEspera);
            threadCronTemp = argEspera->threadCron;
            pthread_mutex_unlock(&lockEspera);

            if (threadCronTemp != 0) // SE O CRONÓMETRO ESTIVER A CORRER, ESPERAR QUE ACABE, EMBORA ISTO NUNCA DEVA ACONTECER
                pthread_join(threadCronTemp, NULL);

            argEspera->duracao = duracao * 60; // SEGUNDO PARA MINUTOS
            argEspera->isFinished = false;
            if (pthread_create(&(argEspera->threadCron), NULL, &threadEsperar, NULL) != 0) // CRONÓMETRO DO CAMPEONATO
                sair(EXIT_ERR_MSG, "ERRO: Impossível criar a thread de cronómetro.");

        // CRONÓMETRO DO CAMPEONATO TERMINOU OU JÁ NÃO HÁ JOGADORES SUFICIENTES
        } else if (currState == 1 && (isFinished || countJogadores(&lock) < 2)) {
            terminaCampeonato(&lock);
            
            // VOLTAR À FASE DE ESPERA
            currState = 0;
            isTimeCounting = false;
        }
    }
}