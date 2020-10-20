#include <stdio.h>

int EntregaDoPedido(int valor, int notas[], int existentes[], int entrega[], int n);

void main()
{
    int valor, notas[] = {50,20,10,5}, existentes[] = {0,2,0,0}, n = 4, i, entrega[] = {0,0,0,0};

    printf("Terminal -> estado inicial:\n");
    for(i = 0 ; i < n ; i++)
        if(existentes[i] != 0) //ERRO 1
            printf("%d nota(s) de %d;  ", existentes[i], notas[i]);
    printf("\n---------------------------------------------------------------------\n");

    do{
        do{
            printf("\nQual o valor que pretende [5,400] -> ");
            scanf("%d",&valor);
        }while((valor < 5 || valor > 400) && valor != 0); //ERRO 2

        if(valor == 0)
            break;

        for(i = 0; i < n ; i++) //ERRO 6
            entrega[i] = 0;

        if(EntregaDoPedido(valor, notas, existentes, entrega, n) == 1) // ERRO 3
        {
                for(i = 0 ; i < n ; i++)
                    if(entrega[i] != 0) // ERRO 4
                        printf("%d nota(s) de %d;  ", entrega[i], notas[i]);
        } // ERRO 5
        else
            printf("Entrega indisponivel.");

        printf("\n");

    }while(valor != 0);

    printf("\n---------------------------------------------------------------------\n");
    printf("Terminal -> estado final:\n");
    for(i = 0 ; i < n ; i++)
        if(existentes[i] != 0)
            printf("%d nota(s) de %d;  ", existentes[i], notas[i]);
    printf("\n");
}

int EntregaDoPedido(int valor, int notas[], int existentes[], int entrega[], int n)
{
    int soma = valor, i = 0, inexistentes, j, notasEntregues, notasExistentes;

    if(valor % 5 != 0)
        return 0;

    while(i <= n)
    {
        while(soma - notas[i] >= 0 && existentes[i] > 0)
        {
            entrega[i]++;
            soma -= notas[i];
            if(soma == 0)
            {
                for(j = 0 ; j < n ; j++) //ERRO 1
                    existentes[j] -= entrega[j];
                return 1;
            }
        }

        if(existentes[i] == 0)
        {
            inexistentes = 0;
            j = i;

            while(j <= n)
            {
                if(existentes[j] == 0)
                    inexistentes++;
                j++;
            }

            if(n-i == inexistentes)
                return 0;
        }
        i++;
    }
}
