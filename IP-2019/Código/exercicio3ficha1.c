#include <stdio.h>
#define PI 3.1416 //Primeiro include, depois define

void main()
{
    float raio,area,perimetro; //Em C, declarar sempre as variaveis primeiro

    printf("Insira o raio do circulo:");
    scanf("%f",&raio);

    area=PI*raio*raio;
    perimetro=2*PI*raio;

    printf("Area do circulo: %0.1f\nPerimetro do circulo: %0.1f\n",area,perimetro);
}
