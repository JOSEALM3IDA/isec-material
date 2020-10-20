#include <stdio.h>

void main()
{
    int popA, popB, anos = 0;
    float taxaA, taxaB;
    do{
        printf("Populacao de A: ");
        scanf("%d",&popA);
        printf("Populacao de B: ");
        scanf("%d",&popB);
        printf("Taxa de crescimento da populacao A: ");
        scanf("%f",&taxaA);
        printf("Taxa de crescimento da populacao B: ");
        scanf("%f",&taxaB);
    }while (popA < 0 || popB < 0 || taxaA < taxaB);

    taxaA /= 100;
    taxaB /= 100;

    do{
        popA += (popA * taxaA);
        popB += (popB * taxaB);
        anos++;
        printf("Ano: %d \nPop A: %d \nPop B: %d\n\n",anos,popA,popB);
    }while (popA < popB);

    printf("Anos necessarios para que a populacao de A surpasse a de B: %d\n",anos);
}
