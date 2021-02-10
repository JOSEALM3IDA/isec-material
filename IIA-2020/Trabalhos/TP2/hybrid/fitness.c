#include "fitness.h"

int qualidadeSol(const int* sol, const int* dist, int M, int G) {
    int i, j, k, count, div, qual; // div - diversidade | qual - qualidade

    for (i = 0; i < G; i++) {
        count = 0;
        for (j = 0; j < M; j++)
            if (sol[j] == i)
                count++;

        if (count != (M / G))
            return -1;
    }

    for (i = 0, qual = 0; i < G; i++) {
        div = 0;
        for (j = 0; j < M; j++)
            if (sol[j] == i)
                for (k = j + 1; k < M; k++)
                    if (sol[k] == i)
                        div += dist[j * M + k];

        
        qual += div;
        // printf("Qualidade: %i", qual);
    } 

    return qual;  
}

void qualidadePop(int* pop[POP_SIZE], int qualidade[POP_SIZE], const int* dist, int M, int G) {
    int i;

    for (i = 0; i < POP_SIZE; i++)
        qualidade[i] = qualidadeSol(pop[i], dist, M, G);
}