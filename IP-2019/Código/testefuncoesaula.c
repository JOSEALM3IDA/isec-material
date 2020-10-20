#include <stdio.h>

int potencia(int,int);

void main()
{
    int b,e,resultado;
    printf("Indique base e expoente: ");
    scanf("%d%d",&b,&e);
    resultado = potencia(b,e);
    printf("Resultado = %d\n",resultado);
}

int potencia(int base,int expoente)
{
    int res=1,i;
    for(i=1;i<=expoente;i++)
        res *= base;
    return res;
}
