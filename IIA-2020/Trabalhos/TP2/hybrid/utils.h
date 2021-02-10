#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lista infinita de defines
#define DEFAULT_RUNS 50
#define POP_SIZE 100
#define GER_NUM 1000
#define PROB_REPROD 0.2
#define PROB_MUTAC 0.1
#define T_SIZE 10
#define SA_N_VIZINHOS 10
#define SA_TEMPERATURA_MAXIMA 50
#define SA_TEMPERATURA_MINIMA 5
#define SA_FATOR_ATUALIZACAO 0.5
#define SA_CHANCE 0.1

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

// Escreve soluções para um ficheiro
void escreverFicheiro(char* fName, float MBF, const int* sol, const int qualidade, int M, int G);

// Gera solução inicial
// Parâmetros de entrada: valor de M (num elem) e G (num subconj)
// Parâmetros de saida: ponteiro para a solucao inicial preenchida
void initSol(int* sol, int M, int G);

// Apresenta na consola a solução dada
// Parâmetros de entrada: ponteiro para a solução, qualidade da solução, valor de M (num elem) e valor de G (num subconj)
void escreveSol(FILE* fs, const int* sol, const int qualidade, int M, int G);

// Gera populacao inicial
// Parâmetros de entrada: ponteiros para o vetor de soluções (população) e para a matriz de distancias, valor de M (num elem) e G (num subconj)
void initPop(int* pop[POP_SIZE], const int* dist, int M, int G);

// Apresenta na consola a populacao dada
// Parâmetros de entrada: ponteiro para a população, vetor de qualidades, valor de M (num elem) e valor de G (num subconj)
void escrevePop(FILE* fs, int* pop[POP_SIZE], const int qualidade[POP_SIZE], int M, int G);

// Substitui informacao de dois vetores
// Parâmetros de entrada: dois vetores (a e b), tamanho dos vetores (M)
void substitui(int* a, int* b, int M);

// Reparar uma solução
void repararSol(int* sol, int* dist, int M, int G);

// Repara a população
void repararPop(int* pop[POP_SIZE], int* dist, int M, int G);


#endif /* UTILS_H */