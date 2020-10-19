#include <stdio.h>
#include <stdlib.h>
#define M 8

void reduzir(int n, int m[n][n], float res[n/2][n/2]) {
    int i, k, p;
    float media = 0;

    for(i = 0; i < n; i += 2) {
        for(k = 0; k < n; k += 2) {
            media += m[i][k];
            media += m[i][k + 1];
            media += m[i + 1][k];
            media += m[i + 1][k + 1];
            media /= 4;

            res[i/2][k/2] = media;

            media = 0;
        }
    }
}

int main(int argc, char** argv) {
    int mat[M][M] = {
            {0,4,9,3,6,7,2,9},
            {9,4,7,8,3,4,7,2},
            {5,1,2,6,3,8,6,2},
            {7,1,4,8,7,2,0,7},
            {4,9,3,5,2,1,5,7},
            {5,3,4,7,8,9,1,0},
            {2,3,5,6,7,9,2,4},
            {2,3,4,5,6,7,8,9}
    };

    float reduzida[M/2][M/2] = {0.0};

    reduzir(M,mat,reduzida);

    for(int i = 0; i < M/2; i++, putchar('\n'))
        for(int j = 0; j < M/2; j++)
            printf("%6.2f",reduzida[i][j]);

    return 0;
}
