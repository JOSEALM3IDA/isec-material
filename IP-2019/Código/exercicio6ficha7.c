#include <stdio.h>
#include <string.h>
#define MAX 500

void duplicar(char frase[], char letra, int TAM)
{
    int i,j;
    char current = ' ';

    i=0;

    do{
        do{
            current = frase[i];
            i++;
        }while(current != letra && current != '\0');

        if (frase[i] != '\0' && strlen(frase) + 1 <= TAM)
        {
            for(j = strlen(frase); j >= i; j--)
                frase[j+1] = frase[j];

            frase[i++] = letra;
        }
    }while (current != '\0');

}

void main()
{
    char frase[MAX];
    char letra;

    printf("Insira frase: ");
    gets(frase);

    printf("Insira a letra: ");
    scanf("%c",&letra);

    duplicar(frase, letra, MAX);
    puts(frase);
}
