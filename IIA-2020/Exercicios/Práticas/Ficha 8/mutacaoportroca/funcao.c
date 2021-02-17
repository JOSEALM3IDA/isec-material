#define _CRT_SECURE_NO_WARNINGS 1
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#include <stdio.h>

void reparacao3(int sol[], struct info d, int mat[][2], int *v) {
	int i, x;
	float sumWeights;

	*v = 0;
	while (1) {
		sumWeights = 0;
		for (i = 0; i < d.numGenes; i++)
			sumWeights += sol[i] * mat[i][0];
		
		if (sumWeights > d.capacity) {
			// Escolher o objeto com menor racio entre o valor e o peso presente na mochila
			x = -1;
			for (i = 0; i < d.numGenes; i++)
				if (sol[i] == 1 && ( x == -1 || mat[i][1] / (float)mat[i][0] < mat[x][1] / (float)mat[x][0] ))
					x = i;
			
			// Retirar o objeto da mochila
			sol[x] = 0;

		} else {
			*v = 1;
			break;
		}
	}
}

// Calcula a qualidade de uma solução
// Parâmetros de entrada: solução (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parâmetros de saída: qualidade da solução
float eval_individual(int sol[], struct info d, int mat[][2], int v) {
	int     i;
	float   sum_weight = 0, fitness = 0;

	// Percorre todos os objectos
	for (i = 0; i < d.numGenes; i++) {
		sum_weight += sol[i] * mat[i][0];
		fitness += sol[i] * mat[i][1];
	}

	return fitness;
}

// Avaliacao da população
// Parâmetros de entrada: populacao (pop), estrutura com parametros (d) e matriz com dados do problema (mat)
// Parâmetros de saída: Preenche pop com os valores de fitness e de validade para cada solução
void evaluate(pchrom pop, struct info d, int mat[][2]) {
	int i;

	for (i = 0; i < d.popsize; i++)
		pop[i].fitness = eval_individual(pop[i].p, d, mat, pop[i].valido);
}
