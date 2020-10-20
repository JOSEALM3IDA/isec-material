#include <stdio.h>
#include <string.h>
#define MAX 200

int substituiPalavras(char frase[], char palavra[]);

void main()
{
    char palavra[MAX]="XXXXX";
    char fr[MAX] = " Era uma linda coisa  sim pois era, pois!";

    printf("\n***\nForam substituidas %d palavras na frase: %s\n", substituiPalavras(fr,palavra), fr);
}

int substituiPalavras(char frase[], char palavra[])
{
    int tamanho = strlen(palavra), i = 0, j, tamNaFrase, k = 0, substituidas = 0;

    while(frase[i] == ' ')
        i++;

    do{
        j = i;

        while(frase[i+1] != ' ' && frase[i+1] != '\0') //ERRO 1
            i++;

        tamNaFrase = i - j; //ERRO 2

        if(tamNaFrase == tamanho)
        {
            substituidas++;
            k = 0;
            j++; //ERRO 3
            for(; j <= i ; j++)
                frase[j] = palavra[k++];
        }

        while(frase[i+1] == ' ' && frase[i+1] != '\0') //ERRO 4
            i++;

    }while(frase[i+1] != '\0');

    return substituidas;
}
