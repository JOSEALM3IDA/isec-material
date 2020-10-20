#include <stdio.h>
#define N 10

int posicaoMaior(int v[], int tam)
{
    int i ,maior = v[0], pos = 0;
    for(i=1;i<tam;i++)
        if (v[i]>=maior)
        {
            maior = v[i];
            pos = i;
        }
    return pos;
}

void moverDireita(int v[], int tam)
{
    int i, aux = v[tam-1];

    for(i = tam-1; i>0; i--)
    {
        v[i] = v [i-1];
    }
    v[0] = aux;
}

void main()
{
    int vetor[N], posicao, i;
    for(i=0;i<N;i++)
    {
        printf("Insira valor %d: ",i+1);
        scanf("%d",&vetor[i]);
    }
    posicao = posicaoMaior(vetor, N);
    printf("\nMaior valor surge na posicao %d.\n",posicao+1);

    moverDireita(vetor, N);

    printf("\nVetor:");

    for(i=0;i<N;i++)
    {
        printf(" %d",vetor[i]);
    }
}
