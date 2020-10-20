#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 500

int ContaPrimeiro(char frase[])
{
    int i;
    char primeiro = ' ';
    int vezes = 0;
    for(i=0;i<strlen(frase);i++)
    {
        frase[i] = toupper(frase[i]);
        if (frase[i] != ' ' && primeiro == ' ')
        {
            primeiro = frase[i];
            vezes++;
            i++;
        }
        if (primeiro != ' ' && frase[i] == primeiro)
            vezes++;
    }
    return vezes;
}

void main()
{
    char frase[MAX];

    printf("Frase: ");
    gets(frase);

    printf("Numero de vezes que aparece o primeiro caracter: %d\n",ContaPrimeiro(frase));
}
