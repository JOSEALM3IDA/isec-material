#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "fitness.h"

#define bool int
#define false 0
#define true 1

// Inicialização do gerador de números aleatórios
void initRand();

// Devolve valor inteiro aleatorio entre min e max
int randomMinMax(int min, int max);

// Devolve um valor decimal no intervalo [0, 1]
float rand_01();

// Lê o ficheiro, preenchendo a matriz
// Parâmetros de entrada: nome do ficheiro
// Parâmetros de saida: ponteiros para a matriz de distancias, para M (num elem) e para G (num subconj)
void lerFicheiro(const char* nomeFich, int** mat, int* M, int* G);

// Gera solução inicial
// Parâmetros de entrada: valor de M (num elem) e G (num subconj)
// Parâmetros de saida: ponteiro para a solucao inicial preenchida
void initSol(int* sol, int M, int G);

// Apresenta na consola a solução dada
// Parâmetros de entrada: ponteiro para a solução, valor de M (num elem) e valor de G (num subconj)
void escreveSol(const int* sol, const int* dist, int M, int G);

// Gera populacao inicial
// Parâmetros de entrada: ponteiros para o vetor de soluções (população) e para a matriz de distancias, valor de M (num elem) e G (num subconj)
void initPop(int* pop[POP_SIZE], const int* dist, int M, int G);

// Substitui informacao de dois vetores
// Parâmetros de entrada: dois vetores (a e b), tamanho dos vetores (M)
void substitui(int* a, int* b, int M);

#endif /* UTILS_H */