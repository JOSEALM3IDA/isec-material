#include <stdio.h>

void main()
{
    float nota1,nota2,media; //Declaração das variáveis

    printf("Indique a nota do teste 1:");
    scanf("%f",&nota1); //Especificação de formato (%f) em percentagem; Endereço de memória (&), que seria nota1
    printf("Indique a nota do teste 2:");
    scanf("%f",&nota2);

    media=(nota1+nota2)/2;

    printf("Media = %.2f\n",media);
}
