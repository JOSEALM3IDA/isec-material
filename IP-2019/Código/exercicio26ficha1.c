#include <stdio.h>

void main()
{
    float base,potencia = 1;
    int expoente;

    printf("Insira a base da potencia: ");
    scanf("%f",&base);
    printf("Insira o expoente da potencia: ");
    scanf("%d",&expoente);

    for(int i = 1; i <= expoente ; i++)
    {
        potencia *= base;
    }

    printf("Valor: %.1f\n",potencia);
}
