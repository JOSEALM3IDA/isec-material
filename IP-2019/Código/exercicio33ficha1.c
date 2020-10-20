#include <stdio.h>

void main()
{
    int N,soma = 0,divisor = 1;

    printf("Indique o valor de N: ");
    scanf("%d",&N);

    do{
        if (N % divisor == 0)
        {
            printf("Divisor: %d\n",divisor);
            soma += divisor;
        }
        divisor++;
    }while(divisor < N);

    if (soma == N)
    {
        printf("O numero %d trata-se de um numero perfeito.\n",N);
    }
    else
        printf("O numero %d nao se trata de um numero perfeito.\n",N);
}
