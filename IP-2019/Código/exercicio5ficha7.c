#define TAM_FRASE 150
#define TAM_PALAVRA 20
#include <stdio.h>
#include <string.h>

void inserir(int pos, char frase[], char palavra[]);

void main()
{
    int pos;
    char frase[TAM_FRASE], palavra[TAM_PALAVRA];
    printf("Insira frase: ");
    gets(frase);
    printf("Insira palavra: ");
    gets(palavra);
    printf("Insira posicao: ");
    scanf("%d",&pos);
    inserir(pos,frase,palavra);
    puts(frase);
}

void inserir(int pos, char frase[], char palavra[])
{
    if(strlen(frase) + strlen(palavra) < TAM_FRASE)
    {
        int i, j = 0;

        for(i = strlen(frase); i >= pos; i--)
            frase[i+strlen(palavra)] = frase[i];

        for(i = pos; i < pos + strlen(palavra); i++)
            frase[i] = palavra [j++];
    }
}
