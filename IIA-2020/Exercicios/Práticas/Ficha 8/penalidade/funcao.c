#define _CRT_SECURE_NO_WARNINGS 1
#include "algoritmo.h"
#include "funcao.h"

#include <stdio.h>

float penalizacao(int sol[], struct info d, int mat[][2], int v) {
	float rho, temp, pen;
	int i;

	if (v == 1) return 0;

	rho = mat[0][1] / mat[0][0];
	pen = sol[0] * mat[0][0];
	for (i = 1; i < d.numGenes; i++) {
		temp = mat[i][1] / mat[i][0];
		if (temp > rho)
			rho = temp;

		pen += sol[i] * mat[i][0];
	}

	pen = rho * (pen - d.capacity);

	return pen;
}


// Calcula a qualidade de uma solução
// Parâmetros de entrada: solução (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parâmetros de saída: qualidade da solução
float eval_individual(int sol[], struct info d, int mat[][2], int *v) {
	int     i;
	float   sum_weight = 0, fitness = 0;

	// Percorre todos os objectos
	for (i = 0; i < d.numGenes; i++) {
		sum_weight += sol[i] * mat[i][0];
		fitness += sol[i] * mat[i][1];
	}

	*v = sum_weight > d.capacity ? 0 : 1;

	return fitness - penalizacao(sol, d, mat, *v);;
}

// Avaliacao da população
// Parâmetros de entrada: populacao (pop), estrutura com parametros (d) e matriz com dados do problema (mat)
// Parâmetros de saída: Preenche pop com os valores de fitness e de validade para cada solução
void evaluate(pchrom pop, struct info d, int mat[][2]) {
	int i;

	for (i = 0; i < d.popsize; i++)
		pop[i].fitness = eval_individual(pop[i].p, d, mat, &pop[i].valido);
}
