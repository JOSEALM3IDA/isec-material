#include <stdio.h>

void main()
{
    int numeroValidos,numeroBrancos,numeroNulos,numeroVotantes;
    float percentagemValidos,percentagemBrancos,percentagemNulos;

    printf("Insira o numero de votos validos: ");
    scanf("%d",&numeroValidos);

    printf("Insira o numero de votos brancos: ");
    scanf("%d",&numeroBrancos);

    printf("Insira o numero de votos nulos: ");
    scanf("%d",&numeroNulos);

    numeroVotantes=numeroValidos+numeroBrancos+numeroNulos;
    percentagemValidos=100*numeroValidos/numeroVotantes;
    percentagemBrancos=100*numeroBrancos/numeroVotantes;
    percentagemNulos=100*numeroNulos/numeroVotantes;


    printf("\nNumero total de votantes: %d\nPercentagem de votos validos: %0.2f%%\nPercentagem de votos brancos: %0.2f%%\nPercentagem de votos nulos: %0.2f%%\n",numeroVotantes,percentagemValidos,percentagemBrancos,percentagemNulos);
}
