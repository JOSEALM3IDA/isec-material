#include <stdio.h>
#include <ctype.h>

int PontoNoRetangulo(float vInfEsq[], float vSupDir[], float ponto[]);

void main()
{
    int parti = 0, soma = 0, i, vezes, recorde = 0, melhorParti = 0;
    char continuar, desconto;
    float vInfEsq[2], vSupDir[2], ponto[2];
    vInfEsq[0] = 2.0;
    vInfEsq[1] = 1.5;
    vSupDir[0] = 4.0;
    vSupDir[1] = 2.5;
    do{
        fflush(stdin);
        printf("Inserir participante (S/N)? ");
        scanf("%c", &continuar);
        continuar = tolower(continuar);
        fflush(stdin);

        if (continuar == 's')
        {
            vezes = 0;
            parti++;

            printf("Participante %d:\n",parti);
            printf("Estudante (S/N)? ");
            scanf("%c", &desconto);
            fflush(stdin);

            desconto = tolower(desconto);

            if (desconto == 's')
                soma += 5;
            else
                soma += 10;

            for(i=1;i<=15;i++)
            {
                do{
                    printf("Coordenadas do lancamento %d: ",i);
                    scanf("%f %f", &ponto[0], &ponto[1]);
                }while(ponto[0] < 0.0 || ponto[0] > 6.0 || ponto[1] < 0.0 || ponto[1] > 3.0);

                if(PontoNoRetangulo(vInfEsq, vSupDir, ponto) == 1)
                    vezes++;
            }
            if (vezes > recorde)
            {
                recorde = vezes;
                melhorParti = parti;
            }
            printf("Conseguiu %d pontos!\n",vezes);
        }
    }while (continuar == 's');
    printf("-----------------------------------\n");
    printf("Total de participantes = %d\n", parti);
    printf("Valor angariado (€) = %d\n", soma);
    printf("N do participante vencedor = %d\n", melhorParti);
}
int PontoNoRetangulo(float vInfEsq[], float vSupDir[], float ponto[])
{
    float x1 = vInfEsq[0], x2 = vSupDir[0];
    float y1 = vInfEsq[1], y2 = vSupDir[1];

    if(ponto[0]>=x1 && ponto[0]<=x2 && ponto[1]>=y1 && ponto[1]<=y2)
        return 1;
    else
        return 0;
}
