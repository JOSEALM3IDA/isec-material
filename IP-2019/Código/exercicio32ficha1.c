#include <stdio.h>

void main()
{
    int numero, resto, soma = 0;

    printf("Insira o numero inteiro: ");
    scanf("%d",&numero);

    do{
        resto = numero%10;
        soma += abs(resto);
        numero /= 10;
    }while (numero != 0);

    printf("Soma dos digitos do numero: %d\n",soma);
}
