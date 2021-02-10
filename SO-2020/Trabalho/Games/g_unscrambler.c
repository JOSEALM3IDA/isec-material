#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#define WORD_COUNT 45
#define STR_SIZE 20

int score = 0;

void sig_handler(int signal, siginfo_t *info, void * extra) {
    if (signal == SIGUSR1)
        exit(score);
}

void swap (char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void randomize (char word[], int n) {
    for (int i = n-1; i > 0; i--) { 
        // Pick a random index from 0 to i 
        int j = rand() % (i+1); 

        swap(&word[i], &word[j]);
    } 
}

int main (int argc, char **argv) {
    struct sigaction action;
    char word[STR_SIZE];
    char guess[STR_SIZE];
    int i;
    char arr[WORD_COUNT][STR_SIZE] = {"presente", "indicativo", "omniopata",
                                      "helicoptero", "natal", "pascoa",
                                      "saia", "amor", "roma",
                                      "sistemas", "operativos", "pessoa",
                                      "bola", "computador", "cliente", 
                                      "quarentena", "dicionario", "trabalho",
                                      "estudar", "rezar", "dormir",
                                      "chorar", "estojo", "rato",
                                      "pneu", "telemovel", "loica",
                                      "disco", "parede", "muralha",
                                      "estado", "passe", "passaro",
                                      "pagina", "ano", "incorreto",
                                      "esmeralda", "ferro", "cobre",
                                      "copo", "mundo", "cebola",
                                      "tomate", "cubo", "candeeiro"};

    setbuf(stdout, NULL);

    action.sa_flags = SA_RESTART | SA_SIGINFO; // INICIALIZAR AS FLAGS
    action.sa_sigaction = sig_handler; // REGISTAR A FUNÇÃO

    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        fprintf(stderr, "Erro ao colocar a função ao serviço do sinal.\n");
        exit(-1);
    }

    srand(time(NULL));
    i = rand() % WORD_COUNT;

    strcpy(word, arr[i]);

    while (strcmp(word,arr[i]) == 0)
        randomize(word, strlen(word)); 

    printf("O jogo 'unscrambler' consiste em ordenar um conjunto de letras de modo a formar a palavra original!\n");
    printf("Exemplo: dado o conjunto de letras 'ovafr', a resposta correta seria 'favor'!\n\n");

    printf("Ordene a palavra: %s\n", word);

    while (1) {
        fgets(guess, STR_SIZE - 1, stdin);
        strtok(guess, "\n");

        if (strcmp(guess,arr[i]) == 0) {
            i = rand() % WORD_COUNT;
            strcpy(word, arr[i]);
            while (strcmp(word, arr[i]) == 0)
                randomize(word, strlen(word)); 
            score++;
            printf("Certo! Pontuação atual: %i\n\nNova palavra gerada: %s\n", score, word);
            
        } else
            printf("Errado, tente novamente!\n");
    }
    exit(score);
}