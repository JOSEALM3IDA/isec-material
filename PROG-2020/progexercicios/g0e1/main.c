#include <stdio.h>

int encontrarMaior(int vetor[], int tam){
    int i, posMaior = 0;

    for(i = 1; i < tam; i++)
        if(vetor[i] > vetor[posMaior])
            posMaior = i;

    return vetor[posMaior];
}
int main() {
    int v[12] = {4,2,23,43,66,12,98,123,55,2,1,9};

    int maior = encontrarMaior(v,12);

    printf("Maior valor: %d",maior);

    return 0;
}
