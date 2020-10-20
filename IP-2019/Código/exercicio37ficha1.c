#include <stdio.h>

void main()
{
    int numero, operacoes = 0;

    do{
        printf("Indique o valor do numero: ");
        scanf("%d",&numero);
    }while(numero <= 0);
    printf("\n");
    do{
        if (numero%2 == 0)
            numero /= 2;
        else
            numero = 3*numero + 1;

        operacoes++;
        printf("Operacao: %d \nValor: %d \n\n",operacoes,numero);
    }while(numero != 1);

    printf("Numero total de operacoes: %d \n",operacoes);
}
