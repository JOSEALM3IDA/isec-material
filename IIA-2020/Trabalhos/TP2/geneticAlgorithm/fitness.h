#ifndef FITNESS_H
#define FITNESS_H

#include <stdio.h>

#include "utils.h"

// Calcula e devolve a qualidade de uma solução
// Parâmetros de entrada: solução a avaliar, matriz das distâncias, numero M de elementos, numero G de subconjuntos
// Devolve a qualidade da solução
int qualidadeSol(const int* sol, const int* dist, int M, int G);

// Calcula a qualidade da populacao, preenchendo o vetor de qualidades
void qualidadePop(int* pop[POP_SIZE], int qualidade[POP_SIZE], const int* dist, int M, int G);

#endif /* FITNESS_H */