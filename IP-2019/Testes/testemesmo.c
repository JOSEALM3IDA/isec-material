#include <stdio.h>

int salas(int nAlunos, int capacidadeSalas)
{
    int nSalas;
    if (nAlunos%capacidadeSalas == 0)
        nSalas = nAlunos/capacidadeSalas;
    else
        nSalas = (nAlunos/capacidadeSalas) + 1;
    return nSalas;
}

void main()
{
    int capacidadeSala, nAlunos, maiorSalas, maiorUC, UC, nSalas;
    capacidadeSala = 50;
    UC = 1;

    do{
        do
        {
            printf("Numero de alunos inscritos na UC %d: ",UC);
            scanf("%d",&nAlunos);
        }while(nAlunos < 0);

        if (nAlunos != 0)
        {
            nSalas = salas(nAlunos,capacidadeSala);
            if (UC == 1)
            {
                maiorSalas = nSalas;
                maiorUC = 1;
            }
            else if (nSalas > maiorSalas)
            {
                maiorSalas = nSalas;
                maiorUC = UC;
            }
            printf("Numero de salas necessario para a UC %d: %d\n",UC,nSalas);
            UC++;
        }
    }while(nAlunos != 0);

    printf("\nMaior numero de salas por exame: %d",maiorSalas);
    printf("\nOcorre na UC %d.\n",maiorUC);
}
