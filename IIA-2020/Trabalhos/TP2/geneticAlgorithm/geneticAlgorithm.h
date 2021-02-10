#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <math.h>

#include "utils.h"
#include "fitness.h"

// Preenche uma estrutura com os progenitores da próxima geração, de acordo com o resultados do torneio
// Parâmetros de entrada: população atual (pop)
// Parâmetros de saida: nova população de pais
void tournament(int* pop[POP_SIZE], int* parents[POP_SIZE], int qualidade[POP_SIZE], int M);

// Operadores geneticos a usar na geração dos filhos
// Parâmetros de entrada: vetor com os pais (parents), vetor que guardará os descendentes (offspring), tamanho M da população
void geneticOperators(int* parents[POP_SIZE], int* offspring[POP_SIZE], int qualidade[POP_SIZE], const int* dist, int M, int G);

// Preenche o vetor offspring com o resultado das operações de recombinação
// Parâmetros de entrada: vetor dos pais, matriz das distâncias, numero M de elementos, numero G de subconjuntos
// Parâmetros de saída: vetor dos descendentes mutados
void crossover(int* parents[POP_SIZE], int* offspring[POP_SIZE], int* dist, int M, int G);

// Causa mutações na população
// Parâmetros de entrada: vetor dos descendentes mutados, matriz das distâncias, numero M de elementos, numero G de subconjuntos
// Parâmetros de saída: vetor dos descendentes mutados
void mutation(int* offspring[POP_SIZE], const int* dist, int M, int G);

#endif /* GENETICALGORITHM_H */