#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "fitness.h"
#include "geneticAlgorithm.h"
#include "simulatedAnnealing.h"

int main (int argc, char* argv[]) {
    char nomeFich[100];
    int runs, M, G, i, j, bestRunFitness, bestEverFitness;
    int *dist = NULL;
    int* pop[POP_SIZE], qualidade[POP_SIZE];
    int* parents[POP_SIZE];
    float MBF;
    int *bestRun = NULL, *bestEver = NULL;
    int genAtual;

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
    bestRun = malloc(sizeof(int) * M);
    bestEver = malloc(sizeof(int) * M);
    bestEverFitness = -1;
    bestRunFitness = -1;

    for (i = 0; i < runs; i++) {
        printf("\n-> Repeticao %d", i);

        // Gera população inicial (algoritmo genetico)
        initPop(pop, dist, M, G);
        
        for (j = 0; j < POP_SIZE; j++) {
            parents[j] = malloc(sizeof(int) * M);
            if (parents[j] == NULL) {
                fprintf(stderr, "<ERRO> Alocacao de memoria para os pais falhou.\n");
                exit(-1);
            }
        }

        // Avalia a população inicial
        qualidadePop(pop, qualidade, dist, M, G);

        // Mostra populacao inicial (algoritmo genetico)
        // printf("\n\n---- POPULACAO INICIAL ----\n");
        // escrevePop(pop, qualidade, M, G);

        // Como ainda não existe, escolhe-se como melhor solução a primeira da população (poderia ser outra qualquer)
		memcpy(bestRun, pop[0], sizeof(int) * M);

        genAtual = 1;
        while (genAtual <= GER_NUM) {
            // printf("Gen: %d ", genAtual);
            tournament(pop, parents, qualidade, M);

            geneticOperators(parents, pop, qualidade, dist, M, G);
            
            // Reparação
            repararPop(pop, dist, M, G);

            // S.A. 3
            for (j = 0; j < POP_SIZE; j++)
                if (rand_01() < SA_CHANCE)
                    simulatedAnnealing(pop[j], dist, M, G, SA_N_VIZINHOS, SA_TEMPERATURA_MAXIMA, SA_TEMPERATURA_MINIMA, SA_FATOR_ATUALIZACAO);

            qualidadePop(pop, qualidade, dist, M, G);

            //printf("\n\n---- POPULACAO ----\n");
            //escrevePop(stdout, pop, qualidade, M, G);

            //scanf(" ");
            for (j = 0; j < POP_SIZE; j++)
                if (qualidade[j] > bestRunFitness) {
                    memcpy(bestRun, pop[j], sizeof(int) * M);
                    bestRunFitness = qualidade[j];
                }
            
            genAtual++;
        }

		// Escreve resultados da repeticao i
		//escreveSol(sol, dist, M, G);

        // S.A. 2
        simulatedAnnealing(bestRun, dist, M, G, SA_N_VIZINHOS, SA_TEMPERATURA_MAXIMA, SA_TEMPERATURA_MINIMA, SA_FATOR_ATUALIZACAO);
        
		MBF += bestRunFitness;
		if (i == 0 || bestRunFitness > bestEverFitness) {
            memcpy(bestEver, bestRun, sizeof(int) * M);
            bestEverFitness = bestRunFitness;
        }
			
        for (j = 0; j < POP_SIZE; j++) {
            free(pop[j]);
            free(parents[j]);
        }
    }

    // Escreve resultados globais
	printf("\n\nMBF: %.2f\n", MBF / i);
	printf("\n-- Melhor solucao encontrada --");
	escreveSol(stdout, bestEver, bestEverFitness, M, G);
    //escreverFicheiro(argv[1], MBF / i, bestEver, bestEverFitness, M, G);
    
    putchar('\n');
    free(dist);
    free(bestEver);
    return 0;
}