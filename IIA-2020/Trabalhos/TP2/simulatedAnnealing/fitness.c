#include "fitness.h"

int qualidadeSol(const int* sol, const int* dist, int M, int G) {
    int i, j, k, div, qual; // div - diversidade | qual - qualidade

    for (i = 0, qual = 0; i < G; i++) {
        div = 0;
        for (j = 0; j < M; j++)
            if (sol[j] == i)
                for (k = j + 1; k < M; k++)
                    if (sol[k] == i)
                        div += dist[j * M + k];

        qual += div;
    } 

    return qual;  
}