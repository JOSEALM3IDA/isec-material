#include <stdio.h>

int maior (int V[], int dim)
{
    int i, maiorN = V[0], vezesMaior = V[0];

    for(i=1;i<dim;i++)
    {
        if(V[i]>maiorN)
        {
            maiorN = V[i];
            vezesMaior = V[i];
        }
        else if (V[i]==maiorN)
            vezesMaior += maiorN;
    }

    return vezesMaior;
}

void main()
{
    int tam,i;

    printf("Insira o tamanho do array: ");
    scanf("%d", &tam);
    int A[tam];

    for(i=1;i<=tam;i++)
    {
        printf("Insira valor %d: ",i);
        scanf("%d",&A[i-1]);
    }

    printf("\nSoma: %d\n",maior(A,tam));
}
