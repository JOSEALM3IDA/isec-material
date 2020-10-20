#include <stdio.h>
#include <string.h>
#define TAM 100

void main()
{
    char frase[TAM];
    int i, len;

    printf("Insira uma frase:\n\n");
    gets(frase);

    len = strlen(frase);

    printf("\n");

    for(i=len-1;i>=0;i--)
        printf("%c",frase[i]);

    printf("\n");
}
