#include "utils.h"

void initRand() { srand((unsigned)time(NULL)); }

int randomMinMax(int min, int max) { return min + rand() % (max - min + 1); }

float rand_01() { return ((float)rand()) / RAND_MAX; }

void lerFicheiro(const char* nomeFich, int** mat, int* M, int* G) {
    int i, j, dist;
    char c;

    FILE* fp = fopen(nomeFich, "r");
    if (fp == NULL) {
        fprintf(stderr, "<ERRO> Nao foi possivel abrir o ficheiro. Codigo: {%d}\n", errno);
        exit(-1);
    }

    // Ler a primeira linha do ficheiro
    fscanf(fp, "%d %d", M, G);
    while (fgetc(fp) != '\n');

    // Alocar espaço para a matriz que vai ser lida e preenchida
    (*mat) = malloc(sizeof(int) * (*M) * (*M));
    if ((*mat) == NULL) {
        fprintf(stderr, "<ERRO> Nao foi possivel alocar memoria para a matriz das distancias.\n");
        exit(-1);
    }

    // Inicializar os valores da matriz, colocando 0 na diagonal e -1 nos restantes
    for (i = 0; i < *M; i++)
        for (j = 0; j < *M; j++)
            (*mat)[i * (*M) + j] = (i == j ? 0 : -1);
            

    // Preencher toda a matriz exceto as diagonais
    i = j = 0;
    while (fscanf(fp, "%d %d %d\n", &i, &j, &dist) == 3) 
        (*mat)[i * (*M) + j] = (*mat)[i + j * (*M)] = dist;

    if (*M % *G != 0) {
        fprintf(stderr, "<ERRO> Informacao no ficheiro esta errada, pois nao e possivel dividir igualmente %d elementos por %d conjuntos.\n", *M, *G);
        exit(-1);
    }

    // Verificar se a informacao no ficheiro esta correta
    for (i = 0; i < *M; i++)
        for (j = 0; j < *M; j++)
            if ((*mat)[i * (*M) + j] == -1) {
                fprintf(stderr, "<ERRO> Ficheiro nao contem a distancia entre todos os elementos.\n");
                exit(-1);
            }
}

void initSol(int* sol, int M, int G) {
    int i, j, pos;

    // Inicializar a solucao
    for (i = 0; i < M; i++)
        sol[i] = -1;

    for (i = 0; i < G; i++) { // Para cada subconjunto
        for (j = 0; j < M / G; j++) { // Atribuir M / G elementos ao subconjunto (de modo a dividir os elementos igualmente pelo subconjunto)
            do // Escolher um elemento sem subconjunto
                pos = randomMinMax(0, M - 1);
            while (sol[pos] != -1);

            sol[pos] = i; // Atribuir o elemento ao subconjunto
        }
    }
}

void escreveSol(const int* sol, const int* dist, int M, int G) {
    int i, j;
    for (i = 0; i < G; i++) {
        printf("\nConjunto %d: [", i);
        for (j = 0; j < M; j++) {
            if (sol[j] == i) {
                printf(" %d", j);
            }
        }
        printf(" ]");
    }

    printf("\nQualidade: %i\n", qualidadeSol(sol, dist, M, G));
}

void initPop(int* pop[POP_SIZE], const int* dist, int M, int G) {
    int i;

    // Gerar cada individuo da populacao
    for (i = 0; i < POP_SIZE; i++) {
        pop[i] = malloc(sizeof(int) * M);
        if (pop[i] == NULL) {
            fprintf(stderr, "<ERRO> Nao foi possivel alocar memoria para a solucao inicial.\n");
            exit(-1);
        }

        initSol(pop[i], M, G);
    }
}

void substitui(int* a, int* b, int M) {
    int i, temp;
    for (i = 0; i < M; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}