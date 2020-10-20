#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int vezesCarater(int x, char c, char frase[])
{
    int i = 0, vezes = 1;
    c = tolower(c);

    do{
        while(tolower(frase[i]) != c && frase[i] != '\0')
            i++;

        i++;

        while(tolower(frase[i]) == c && frase[i] != '\0')
        {
            i++;
            vezes++;
        }

        if (vezes >= x)
            return 1;

        vezes = 1;

    }while(frase[i] != '\0');

    return 0;
}

void main()
{
    char c, string[MAX], maior[MAX];
    int vezes = 3;

    printf("Carater: ");
    scanf("%c",&c);
    fflush(stdin);

    printf("\n");

    do{
        printf("Introduza uma string: ");
        gets(string);

        if(string[0] == 'F' && string[1] == 'I' && string[2] == 'M' && strlen(string) == 3)
            break;

        if(vezesCarater(vezes,c,string) == 1 && strlen(string) >= strlen(maior))
            strcpy(maior, string);

    }while(string[0] != 'F' || string[1] != 'I' || string[2] != 'M' || strlen(string) != 3);

    if(maior[0] == '\0')
        printf("\nEm nenhuma das strings aparece o caracter %c %d vezes consecutivas.\n", c, vezes);
    else
        printf("\nA maior string onde o caracter %c surgiu %d vezes consecutivas e: %s\n", c, vezes, maior);
}
