#include <stdio.h>
#include <string.h>

#define TAMFRASE 81
#define TAMPALAVRA 9

int UltimaPalavra(char frase[], char palavra[], int dmax);

void main()
{
    char frase[TAMFRASE], ultima[TAMPALAVRA];
    int p = 0;

    printf("Indique uma frase: ");
    gets(frase);
    p = UltimaPalavra(frase,ultima,TAMPALAVRA-1);
    if(p>=0)
        printf("Ultima palavra: %s, que comeca na posicao %d da frase \n",ultima,p);
    else
        printf("Nao foi possivel definir a ultima palavra \n");
}

int UltimaPalavra(char frase[], char palavra[], int dmax)
{
    int p = strlen(frase), i, j = 0, k;

    while (frase[p-1] == ' ') // colocar p na ultima letra da ultima palavra
        p--;

    k = p;

    while (frase[p-1] != ' ' && p != 0) // colocar p na primeira letra da ultima palavra
        p--;

    if (strlen(frase) - (p+1) <= dmax)
    {
        for(i = p; i < k; i++)
            palavra[j++] = frase[i];
        palavra[j] = '\0';
        return p;
    }
    else
        return -1;
}
