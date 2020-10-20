#include <stdio.h>
#include <time.h>
#define MAX 500

int PedeAposta(int jogador)
{
    int ap;

    printf("\nJogador %d \n",jogador);
    printf("Insira a aposta: ");
    scanf("%d",&ap);

    return(ap);
}

int NumeroAleatorioInt(int limite)
{
    srand((unsigned)time(NULL));
    return(rand()%limite);
}

int Compara(int a, int b)
{
    int res;
    if (a<b)
        res = -1;
    else if (a>b)
        res = 1;
    else
        res = 0;
    return res;
}

void main()
{
    int alvo,aposta,r,j=1;
    alvo = NumeroAleatorioInt(MAX);
    do{
        aposta = PedeAposta(j);
        r = Compara(alvo,aposta);
        if (r==1)
            printf("Valor alvo esta acima!\n");
        else if (r==-1)
            printf("Valor alvo esta abaixo!\n");
        else
            printf("O jogador %d venceu!\n",j);
        if (j==1)
            j = 2;
        else
            j = 1;
    }while (r!=0);
}
