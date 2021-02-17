#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "utils.h"

#define DEFAULT_RUNS 10

#define SA_TEMPERATURA_MAXIMA 50
#define SA_TEMPERATURA_MINIMA 1 // // Quanto menor, melhores resultados. Define o numero de iteracoes
#define SA_FATOR_ATUALIZACAO 0.99 // Quanto maior, melhores resultados. Nunca pode ser maior ou igual a 1. Define o numero de iteracoes
#define SA_N_VIZINHOS 10 // Quanto maior, melhores resultados

int main(int argc, char *argv[])
{
    char    nome_fich[100];
    int     vert, num_iter, k, runs, custo, best_custo;
    int     *grafo, *sol, *best;
	float   mbf = 0.0;

	if(argc == 3)
	{
		runs = atoi(argv[2]);
		strcpy(nome_fich, argv[1]);
	}
	else
        if(argc == 2)
        {
            runs = DEFAULT_RUNS;
            strcpy(nome_fich, argv[1]);
        }
        else
        {
            runs = DEFAULT_RUNS;
            printf("Nome do Ficheiro: ");
            gets(nome_fich);
        }
	if(runs <= 0)
		return 0;
	init_rand();
    // Preenche matriz de adjacencias
    grafo = init_dados(nome_fich, &vert, &num_iter);
	sol = malloc(sizeof(int)*vert);
	best = malloc(sizeof(int)*vert);
	if(sol == NULL || best == NULL)
	{
		printf("Erro na alocacao de memoria");
		exit(1);
	}
	for(k=0; k<runs; k++)
	{
		// Gerar solucao inicial
		gera_sol_inicial(sol, vert);
		escreve_sol(sol, vert);
		// Simmulated annealing
		custo = simulated_annealing(sol, grafo, vert, SA_TEMPERATURA_MAXIMA, SA_TEMPERATURA_MINIMA, SA_FATOR_ATUALIZACAO, SA_N_VIZINHOS);
		// Escreve resultados da repeticao k
		printf("\nRepeticao %d:", k);
		escreve_sol(sol, vert);
		printf("Custo final: %2d\n", custo);
		mbf += custo;
		if(k==0 || best_custo > custo)
		{
			best_custo = custo;
			substitui(best, sol, vert);
		}
    }
	// Escreve eresultados globais
	printf("\n\nMBF: %f\n", mbf/k);
	printf("\nMelhor solucao encontrada");
	escreve_sol(best, vert);
	printf("Custo final: %2d\n", best_custo);
	free(grafo);
    free(sol);
	free(best);
    return 0;
}
