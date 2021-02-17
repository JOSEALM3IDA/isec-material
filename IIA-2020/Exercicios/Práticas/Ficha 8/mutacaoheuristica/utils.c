#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmo.h"
#include "utils.h"

// Inicialização do gerador de números aleatórios
void init_rand() {
	srand((unsigned)time(NULL));
}

// Leitura dos parâmetros e dos dados do problema
// Parâmetros de entrada: Nome do ficheiro e matriz a preencher com os dados dos objectos (peso e valor)
// Parâmetros de saída: Devolve a estrutura com os parâmetros
info init_data(char *filename, int mat[][2]) {
	info 	x;
	FILE    *f;
	int     i;

	if ((f = fopen(filename, "rt")) == NULL) {
		printf("File not found\n");
		exit(1);
	}

	// Leitura dos parâmetros do problema
	fscanf(f, " pop: %d", &x.popsize);
	fscanf(f, " pm: %f", &x.pm);
	fscanf(f, " pr: %f", &x.pr);
	fscanf(f, " tsize: %d", &x.tsize);
	fscanf(f, " max_gen: %d", &x.numGenerations);
	fscanf(f, " obj: %d", &x.numGenes);
	fscanf(f, " cap: %d", &x.capacity);
	if (x.numGenes > MAX_OBJ)
	{
		printf("Number of itens is superior to MAX_OBJ\n");
		exit(1);
	}
	x.ro = 0.0;

	// Leitura dos dados do KSP (peso e lucro)
	fscanf(f, " Weight Profit");
	for (i = 0; i < x.numGenes; i++)
		fscanf(f, " %d %d", &mat[i][0], &mat[i][1]);
	fclose(f);

	// Devolve a estrutura com os parâmetros
	return x;
}

// Simula o lançamento de uma moeda, retornando o valor 0 ou 1
int flip() {
	if ((((float)rand()) / RAND_MAX) < 0.5)
		return 0;
	else
		return 1;
}

// Criacao da populacao inicial. O vector e alocado dinamicamente
// Parâmetro de entrada: Estrutura com parâmetros do problema
// Parâmetro de saída: Preenche da estrutura da população apenas o vector binário com os elementos que estão dentro ou fora da mochila
pchrom init_pop(info d) {
	int     i, j;
	pchrom  indiv;

	if ((indiv = malloc(sizeof(chrom)*d.popsize)) == NULL) {
		printf("Erro na alocacao de memoria\n");
		exit(1);
	}

	for (i = 0; i < d.popsize; i++)
		for (j = 0; j < d.numGenes; j++)
			indiv[i].p[j] = flip();

	return indiv;
}

// Actualiza a melhor solução encontrada
// Parâmetro de entrada: populacao actual (pop), estrutura com parâmetros (d) e a melhor solucao encontrada até a geração imediatamente anterior (best)
// Parâmetro de saída: a melhor solucao encontrada até a geração actual
chrom get_best(pchrom pop, info d, chrom best) {
	int i;

	for (i = 0; i < d.popsize; i++)
		if (best.fitness < pop[i].fitness)
			best = pop[i];

	return best;
}

// Devolve um valor inteiro distribuido uniformemente entre min e max
int random_l_h(int min, int max) {
	return min + rand() % (max - min + 1);
}

// Devolve um valor real distribuido uniformemente entre 0 e 1
float rand_01() {
	return ((float)rand())/RAND_MAX;
}

// Escreve uma solução na consola
// Parâmetro de entrada: populacao actual (pop) e estrutura com parâmetros (d)
void write_best(chrom x, info d) {
	int i;

	printf("\nBest individual: %4.1f\n", x.fitness);
	for (i = 0; i < d.numGenes; i++)
		printf("%d", x.p[i]);
	putchar('\n');
}
