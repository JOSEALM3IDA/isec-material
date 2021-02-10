#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "simulatedAnnealing.h"

#define DEFAULT_RUNS 50

#define SA_TEMPERATURA_MAXIMA 100
#define SA_TEMPERATURA_MINIMA 1
#define SA_FATOR_ATUALIZACAO 0.99
#define SA_N_VIZINHOS 100

int main (int argc, char* argv[]) {
    char nomeFich[100];
    int runs, M, G, i, fitness, bestFitness;
    int *dist = NULL;
    //int* pop[POP_SIZE];
    float MBF;
    int *sol = NULL, *best = NULL;

    // Argumentos de entrada
    if (argc == 3) {
        strcpy(nomeFich, argv[1]);
        runs = atoi(argv[2]);
    } else if (argc == 2) { // Se o número de execuções não for colocado nos argumentos, assume o valor default
        strcpy(nomeFich, argv[1]);
        runs = DEFAULT_RUNS;   
    } else { // Se o nome do ficheiro de informações não for colocado nos argumentos, termina o programa
        fprintf(stderr, "<ERRO> Usage: %s <nome-fich> || <nome-fich> <runs>\n", argv[0]);
        exit(-1);
    }

    // Se o número de execuções do processo for menor ou igual a 0, termina o programa
    if (runs <= 0) {
        fprintf(stderr, "<ERRO> O numero de execucoes deve ser maior que 0.\n");
        exit(-1);
    }

    // Inicializa a geração dos números aleatórios
    initRand();

    // Preencher matriz das distancias
    lerFicheiro(nomeFich, &dist, &M, &G);

    MBF = 0;
    best = malloc(sizeof(int) * M);
    sol = malloc(sizeof(int) * M);
    for (i = 0; i < runs; i++) {
        // Gera solucao inicial (local search)
        initSol(sol, M, G);

        // Mostra a solucao inicial (local search)
        //printf("\n\n-- Solucao Inicial --");
        //escreveSol(sol, dist, M, G);

		// Simulated annealing
		fitness = simulatedAnnealing(sol, dist, M, G, SA_N_VIZINHOS, SA_TEMPERATURA_MAXIMA, SA_TEMPERATURA_MINIMA, SA_FATOR_ATUALIZACAO);

		// Escreve resultados da repeticao i
		//printf("\nRepeticao %d:", i);
		//escreveSol(sol, dist, M, G);
        //scanf(" ");

		MBF += fitness;
		if (i == 0 || fitness > bestFitness) {
			bestFitness = fitness;

			substitui(best, sol, M);
		}
    }

    // Escreve resultados globais
	printf("\n\nMBF: %.2f\n", MBF / i);
	printf("\n-- Melhor solucao encontrada --");
	escreveSol(best, dist, M, G);
    
    free(dist);
    free(sol);
    free(best);
    return 0;
}