#include <stdio.h>

float peso = 0,altura = 0,IMC = 0;

float IndiceMassaCorporal(float,float);

void main()
{
    printf("Insira o peso em kg e a altura do individuo em metros: ");
    scanf("%f%f",&peso,&altura);

    IMC = IndiceMassaCorporal(peso,altura);

    printf("IMC: %.1f\n",IMC);

    if(IMC < 18.5)
        printf("Abaixo do peso normal\n");
    else if(IMC<25)
        printf("Peso normal\n");
    else if(IMC<30)
        printf("Acima do peso normal\n");
    else
        printf("Obesidade\n");
}

float IndiceMassaCorporal(float peso, float altura)
{
    float IMC = peso/(altura*altura);
    return IMC;
}
