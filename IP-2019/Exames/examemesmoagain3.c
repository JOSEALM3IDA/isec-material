#include <stdio.h>
#include <string.h>
#define MAX 100

void maiorPalavra(char frase[], char palavra[])
{
    int maiorTam = 0, tam = 0, maiorInicio, inicio = 0, i = 0, j = 0;

    do{
        inicio = i;
        while(frase[i+1] != ' ' && frase[i+1] != '\0')
            i++;

        tam = i-inicio+1;
        if(tam > maiorTam)
        {
            maiorTam = tam;
            maiorInicio = inicio;
        }

            i += 2;
    }while(frase[i-1] != '\0');

    for(i = maiorInicio; i <= maiorInicio + maiorTam - 1; i++)
        palavra[j++] = frase[i];


    palavra[j] = '\0';

    puts(palavra);
}

void main()
{
    char palavra[MAX];
    char fr[] = "Era uma linda coisa anticonstitucionalissimamente pois sim";

    maiorPalavra(fr, palavra);
    printf("\nMaior palavra de: %s => ", fr);
    puts(palavra);
}
