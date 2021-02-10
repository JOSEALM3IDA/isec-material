#include <math.h>

#include "utils.h"
#include "fitness.h"

// Gera um vizinho da solucao dada (aplicando um operador)
// Parâmetros de entrada: solução atual, vizinho, valor de M (num elem) e de G (num subconj)
//void geraVizinho(int* a, int* b, int M, int G);
void geraVizinho(int* sol, int* viz, int* dist, int M, int G);

// Recristalização simulada
// Parametros: solucao, matriz de distancias, numero de vertices, temperatura máxima, temperatura mínima, fator atualizacao, numero de vizinhos
// Devolve o custo da melhor solucao encontrada
int simulatedAnnealing(int* sol, int* dist, int M, int G, int nVizinhos, float tempMaxima, float tempMinima, float fatorAtualizacao);