#include <stdio.h>
#include <ctype.h>

int PontoNoRetangulo(float vInfEsq[], float vSupDir[], float ponto[])
{
    if (vInfEsq[0] <= ponto[0] && vInfEsq[1] <= ponto[1] && vSupDir[0] >= ponto[0] && vSupDir[1] >= ponto[1])
        return 1;
    else
        return 0;
}

void main()
{
    int parti = 0, cash = 0, pontos = 0, maiorPontos = 0, vencedor = 0, i;
    float ponto[2], vInfEsq[2] = {2.0,1.5}, vSupDir[2] = {4.0,2.5}, caixaInf[2] = {0.0,0.0}, caixaSup[2] = {6.0,3.0};
    char inserir, estudante;

    do{
        printf("Inserir participante (S/N)? ");
        scanf("%c",&inserir);
        fflush(stdin);
        inserir = tolower(inserir);

        if(inserir != 's')
            break;

        parti++;
        printf("Participante %d:\n",parti);
        printf("Estudante (S/N)? ");
        scanf("%c",&estudante);
        fflush(stdin);
        estudante = tolower(estudante);

        if(estudante == 's')
            cash += 5;
        else
            cash += 10;

        for(i=1;i<=3;i++)
        {
            do{
                printf("Coordenadas do lancamento %d: ", i);
                scanf("%f %f",&ponto[0],&ponto[1]);
                fflush(stdin);
            }while(PontoNoRetangulo(caixaInf,caixaSup,ponto) == 0);

            if(PontoNoRetangulo(vInfEsq,vSupDir,ponto) == 1)
                pontos++;
        }
        printf("Conseguiu %d pontos!\n", pontos);

        if(pontos >= maiorPontos)
        {
            vencedor = parti;
            maiorPontos = pontos;
        }

        pontos = 0;
    }while(inserir == 's');

    printf("--------------------------------\n");
    printf("Total de Participantes: %d\n",parti);
    printf("Valor angariado () = %d\n",cash);
    printf("N do participante vencedor = %d\n", vencedor);
}
