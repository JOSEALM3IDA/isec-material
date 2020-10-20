#include <stdio.h>

void main()
{
    int nLados;
    float mLados, perimArea;

    printf("Insira o numero de lados do poligono (3, 4 ou 5): ");
    scanf("%d",&nLados);
    if (nLados == 3 || nLados == 4)
        {
            printf("Insira a medida dos lados do poligono: ");
            scanf("%f",&mLados);
        }

    switch (nLados)
    {
        case 3:
        {
            perimArea = 3*mLados;
            printf("\nO poligono e um triangulo.\nPerimetro do triangulo: %.2f\n",perimArea);
            break;
        }
        case 4:
        {
            perimArea = mLados*mLados;
            printf("\nO poligono e um quadrado.\nArea do quadrado: %.2f\n",perimArea);
            break;
        }
        case 5:
        {
            printf("\nO poligono e um pentagono.\n");
            break;
        }
        default:
            printf("\nA medida dos lados e invalida!\n");
    }



}
