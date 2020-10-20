#include <stdio.h>

void main()
{
    float nTeste1,nTeste2,nExame,nFinal;

    printf("Insira a nota do teste 1: ");
    scanf("%f",&nTeste1);
    printf("Insira a nota do teste 2: ");
    scanf("%f",&nTeste2);
    printf("Insira a nota do exame: ");
    scanf("%f",&nExame);

    nTeste1=nTeste1/10;
    nTeste2=nTeste2/10;
    nExame=16*nExame/20;
    nFinal=nTeste1+nTeste2+nExame;

    printf("Nota final da disciplina de IP: %.1f\n",nFinal);
}
