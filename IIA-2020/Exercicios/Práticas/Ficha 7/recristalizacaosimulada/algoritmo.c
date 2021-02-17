#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

// Gera um vizinho
// Parametros: solucao actual, vizinho, numero de vertices
//swap two vertices
void gera_vizinho(int a[], int b[], int n)
{
    int i, p1, p2;

    for(i=0; i<n; i++)
        b[i]=a[i];
	// Encontra posicao com valor 0
    do
        p1=random_l_h(0, n-1);
    while(b[p1] != 0);
	// Encontra posicao com valor 0
    do
        p2=random_l_h(0, n-1);
    while(b[p2] != 1);
	// Troca
    b[p1] = 1;
    b[p2] = 0;
}

// Recristalização simulada
// Parametros: solucao, matriz de adjacencias, numero de vertices, temperatura máxima, temperatura mínima, fator atualizacao, numero de vizinhos
// Devolve o custo da melhor solucao encontrada
int simulated_annealing(int sol[], int *mat, int vert, float temp_maxima, float temp_minima, float fator_atualizacao, int n_vizinhos)
{
    int *nova_sol, custo, custo_viz, i;
    float temp = temp_maxima, p, delta;
    int iteracoes = 0;

	nova_sol = malloc(sizeof(int)*vert);
    if(nova_sol == NULL) {
        printf("Erro na alocacao de memoria");
        exit(1);
    }


	// Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);

    while (temp > temp_minima) { // O algoritmo termina quando a temperatura mínima for atingida
        for (i = 0; i < n_vizinhos; i++) { // Ciclo interno para criar varios vizinhos (não especifico do sim annealing)
            // Gera vizinho
            gera_vizinho(sol, nova_sol, vert);

            // Avalia vizinho
            custo_viz = calcula_fit(nova_sol, mat, vert);

            /* == ABORDAGEM A == */ /*
            // Aceita vizinho se o custo diminuir (problema de minimizacao)
            if(custo_viz <= custo) {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            } else {
                delta = custo_viz - custo;
                p = exp(-delta / temp);
                if (rand_01() < p) {
                    substitui(sol, nova_sol, vert);
                    custo = custo_viz;
                }
            } */

            /* == ABORDAGEM B == */ // (exatamente igual, assumindo que o rand devolve [0, 1[, que neste caso nao é verdade)
            delta = custo_viz - custo;
            p = exp(-delta / temp);
            // rand: [0, 1[
            if (rand_01() < p) {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }

        // Atualiza a temperatura (geometrica)
        temp *= fator_atualizacao; // O fator deve ser < 1

        // Atualiza a temperatura (linear)
        // temp -= 0.25;

        iteracoes++;
    }

    printf("Simulated annealing performed %d iterations.\n", iteracoes);

    free(nova_sol);
    return custo;
}
