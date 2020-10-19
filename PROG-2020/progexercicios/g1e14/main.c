#include <stdio.h>

void printVetor(float a[], int tam){
    int i;

    for(i=0; i<tam; i++)
        printf("%.2f\t", a[i]);
}


//Guião1: Exercicio 14 (modificado - float)
void escreveMF(int nLin, int nCol, float m[][nCol]){
    int i,j;

    for(i=0; i<nLin; i++){
        for(j=0; j<nCol; j++)
            printf("%.2f\t", m[i][j]);
        putchar('\n');
    }
}

int main() {

    float m1[3][2] = {{1.0, 4.5},{-2.5, 8.9},{0.3, 1.4}};
    float m2[2][6] = {{1.0, 1.6, 4.2, 1.4, 0.5, -3.4},{2.5, 8.1, 0.9, -0.1, 0.8, 3.5}};

    int min2=-1, max2=-1;

    //printVetor(m1[0], 3*2);
    //putchar('\n');
    //printVetor(m2[0],2*6);

    printf("Matriz M1:\n");
    escreveMF(3, 2, m1);

    printf("\nMatriz M2:\n");
    escreveMF(2, 6, m2);

    return 0;
}