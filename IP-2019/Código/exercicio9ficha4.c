#include <stdio.h>

float num, soma = 0, media = 0, numAnterior;
int i = 0;

void main()
{
    printf("Insira uma sequencia crescente de numeros: \n");
    scanf("%f",&num);
    do{
        soma += num;
        i++;
        numAnterior = num;
        scanf("%f",&num);
    }while(num > numAnterior);

    media = soma / i;

    printf("Media %.1f Soma: %.1f\n",media,soma);
}
