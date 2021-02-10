#ifndef ARBITRO_H
#define ARBITRO_H

#define MAXPLAYERS_DEFAULT 30

#define EXIT_EARLY -3
#define EXIT_MEM_FIX -4

#include "utils.h"

typedef struct player jogador;
typedef struct wait espera;

struct wait {
    pthread_t threadCron;   // ID da própria thread
    int duracao;            // Duração do cronómetro
    bool isFinished;        // Se já terminou a contagem ou não
    pthread_mutex_t* lock;  // Lock de exclusão mútua
};

struct player {
    pthread_t th; 
    char nome[STR_SIZE];    // Nome do jogador
    char jogo[STR_SIZE];    // Nome do jogo
    pid_t PID;              // PID do processo do cliente
    int score;              // Pontuacao
    int fd[2];              // Pipes de leitura (fd[0]) e escrita (fd[1]), da perspetiva do servidor
    bool hasComms;          // Se a comunicacao entre jogador-jogo esta ativa
    bool sair;              // Se a thread do jogador deve sair (true para sair, false para continuar)
    int stateCampeonato;    // 0 -> à espera de clientes; 1 -> campeonato começou, cliente sem jogo atribuido; 2 -> jogo a executar; 3 -> fim do campeonato

    int jogoIO[2];          // Pipes de leitura (jogoIO[0]) e escrita (jogoIO[1]), da perspetiva do servidor
    pid_t jogoPID;          // PID do processo do jogo

    char info[BUFF_SIZE];   // Mensagem com informação sobre o que aconteceu, a ser enviada ao cliente

    pthread_mutex_t* lock;  // Lock de exclusão mútua
    jogador* prox;          // Ligacao a lista ligada
};

// Invocada na receção de sinais
void sig_handler(int signal, siginfo_t *info, void *extra);

// Responsável por terminar o árbitro, garantindo o seu fecho correto
void sair(int exitValue, char* error);

// Responsável por fechar a thread do jogador jog
void sairThread(int errcode, jogador* jog, char* str);

// Termina o jogo do jogador e devolve o score
int resultadoJogo(jogador* jog);

// Verifica se existe jogador com o nome dado. Se sim, devolve o ponteiro para ele. Se não, devolve NULL
jogador* existeJogador(char* nome);

// Função usada para interpretar o comando str enviado pelo jogador j
void interpretaComandoCli(char* str, jogador* j);

// Função usada para interpretar o comando str enviado pelo admin
void interpretaComandoArb(char* str, pthread_mutex_t *lock, int* currState, bool* isTimeCounting);

// Atribui e garante o começo da comunicação com o jogo
void atribuirJogo(jogador* jog);

// Função usada para contar o número de jogadores existentes no campeonato
int countJogadores(pthread_mutex_t* lock);

// Função usada por todas as threads cronómetro
void* threadEsperar(void *arg);

// Função usada por todas as threads jogado
void* threadJogador(void *arg);

// Termina o campeonato. Avisa todas as threads do sucedido e espera que os scores individuais fiquem atualizados. 
// Depois, avisa as threads do melhor jogador e do respetivo score, de modo a poderem avisar os clientes
void terminaCampeonato(pthread_mutex_t* lock);

// Lê um diretório, retornando um array com o nome dos ficheiros executaveis na pasta dada
char** lerDiretorio(char* dir, int* tam);

// Verifica se existe ou não um diretório
bool existeDir(char* dir);

#endif /* ARBITRO_H  */