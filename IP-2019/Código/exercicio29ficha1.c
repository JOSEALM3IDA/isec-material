#include <stdio.h>

void main ()
{
    float peso, media = 0, maiorpeso = 0;
    int contador = 0;

    do{
        printf("Indique peso (Kg): ");
        scanf("%f",&peso);
        if (peso > 60)
        {
            media += peso;
            contador++;
        }
        else if (peso < 60)
            if (maiorpeso < peso)
                maiorpeso = peso;
        else
            contador = 1;
    }while(peso >= 0);

    media /= contador;
    printf("Media dos pesos acima de 60Kg: %.2f \n",media);
    printf("Maior peso abaixo de 60Kg: %.2f \n",maiorpeso);
}
