#include "simulatedAnnealing.h"

// VIZINHANÇA 1
/*
void geraVizinho(int* sol, int* viz, int M, int G) {
    int i, g1, g2, p1, p2;
    
    for (i = 0; i < M; i++)
        viz[i] = sol[i];

    g1 = randomMinMax(0, G - 1);

    do
        g2 = randomMinMax(0, G - 1);
    while (g2 == g1);

    do
        p1 = randomMinMax(0, M - 1);
    while (sol[p1] != g1);

    do
        p2 = randomMinMax(0, M - 1);
    while (sol[p2] != g2);

    viz[p1] = g2;
    viz[p2] = g1;
} */

// VIZINHANÇA 2 - Troca os piores elementos de 2 conjuntos aleatorios
void geraVizinho(int* sol, int* viz, int* dist, int M, int G) {
    int i, j, g1, g2;
    int sum, sump1, sump2;
    int p1 = -1, p2 = -1;

    for (i = 0; i < M; i++)
        viz[i] = sol[i];

    g1 = randomMinMax(0, G - 1);

    do
        g2 = randomMinMax(0, G - 1);
    while (g2 == g1);

    // Somar todas as distâncias que incluem o elemento i
    // Ir buscar a menor dessas somas
    for (i = 0; i < M; i++) {
        sum = 0;
        for (j = 0; j < M; j++)
            if (j != i && sol[i] == sol[j]) // Se forem do mesmo grupo
                sum += dist[i * M + j];

        if (sol[i] == g1 && (p1 == -1 || sum < sump1)) { // Se forem do grupo g1
            sump1 = sum;
            p1 = i;
        } else if (sol[i] == g2 && (p2 == -1 || sum < sump2)) { // Se forem do grupo g2
            sump2 = sum;
            p2 = i;
        }
    }

    // Trocar os elementos
    viz[p1] = g2;
    viz[p2] = g1;
}

int simulatedAnnealing(int* sol, int* dist, int M, int G, int nVizinhos, float tempMaxima, float tempMinima, float fatorAtualizacao) {
    int *viz, custo, custoViz, i;
    float temp = tempMaxima, p, delta;
    int iteracoes = 0;

	viz = malloc(sizeof(int) * M);
    if (viz == NULL) {
        fprintf(stderr, "<ERRO> Alocacao de memoria da nova solucao falhou.\n");
        exit(-1);
    }


	// Avalia solucao inicial
    custo = qualidadeSol(sol, dist, M, G);

    while (temp > tempMinima) { // O algoritmo termina quando a temperatura mínima for atingida
        for (i = 0; i < nVizinhos; i++) { // Ciclo interno para criar varios vizinhos
            // Gera vizinho
            //geraVizinho(sol, viz, M, G);
            geraVizinho(sol, viz, dist, M, G);

            // Avalia vizinho
            custoViz = qualidadeSol(viz, dist, M, G);

            // Aceita vizinho se a qualidade aumentar (problema de maximização)
            if (custoViz >= custo) { // Aceitar solucoes de custo igual
                substitui(sol, viz, M);
                custo = custoViz;
            } else {
                delta = custoViz - custo;
                p = exp(-delta / temp);
                if (rand_01() < p) {
                    substitui(sol, viz, M);
                    custo = custoViz;
                }
            }
        }

        // Atualiza a temperatura (geometrica)
        temp *= fatorAtualizacao; // O fator deve ser < 1

        // Atualiza a temperatura (linear)
        //temp -= fatorAtualizacao;

        iteracoes++;
    }

    printf("Simulated annealing performed %d iterations.\n\n", iteracoes);

    free(viz);
    return custo;
}