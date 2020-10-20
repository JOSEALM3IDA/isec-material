#include <stdio.h>
#include <string.h>
#define MAX 100

void maiorPalavra(char frase[], char palavra[]);

void main()
{
    char palavra[MAX];
    char fr[] = "Era uma anticaralhose ant poasdasadsdairrrs sim";

    maiorPalavra(fr, palavra);
    printf("\nMaior palavra de: %s => ", fr);
    puts(palavra);
}

void maiorPalavra(char frase[], char palavra[])
{
    int i = 0, k, tam = 0, maiorTam = 0, pos = 0, j = 0;
    do{
        i = j;

        while(frase[i+1] != ' ' && frase[i+1] != '\0')
            i++;

        tam = i - j + 1;

        if (tam > maiorTam)
        {
            pos = j;
            maiorTam = tam;
        }

        j = i + 2;

    }while(j < strlen(frase));

    for(k=0;k<maiorTam;k++)

    {
        palavra[k] = frase[pos++];
        palavra[k+1] = '\0';
    }
}
