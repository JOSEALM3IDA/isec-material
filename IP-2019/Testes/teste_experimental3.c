#include <stdio.h>

int classLiga(int CC,int DU, int RT)
{
    int testeA = 0, testeB = 0, testeC = 0, classi;

    if (CC<70)
        testeA = 1;
    if (DU>50)
        testeB = 1;
    if (RT>80)
        testeC = 1;

    if (testeA == 1 && testeB == 1 && testeC == 1)
        classi = 3;
    else if (testeA == 1 && testeB == 1)
        classi = 2;
    else if (testeC == 1)
        classi = 1;
    else
        classi = 0;

    return classi;
}

void main()
{
    int teste, nAbaixo = 0, nAcima = 0, ref, nTestes, classi, RT, DU, CC;
    printf("Numero de testes > ");
    scanf("%d",&nTestes);
    do{
        printf("Classificacao de referencia > ");
        scanf("%d",&ref);
    }while (ref<0 || ref>3);

    teste = 1;

    while (teste<=nTestes)
    {
        printf("\nTeste: %.2d\n",teste);
        do{
            printf("RT DU e CC > ");
            scanf("%d%d%d",&RT,&DU,&CC);
        }while(RT < 10 || RT > 120 || DU < 10 || DU > 120 || CC < 10 || CC > 120);

        classi = classLiga(CC,DU,RT);
        printf("Classificacao do metal = %d\n",classi);

        if (classi > ref)
            nAcima++;
        else if (classi < ref)
            nAbaixo++;

        teste++;
    }

    printf("\nNumero de testes acima da classificacao de referencia = %d",nAcima);
    printf("\nNumero de testes abaixo da classificacao de referencia = %d\n",nAbaixo);
}
