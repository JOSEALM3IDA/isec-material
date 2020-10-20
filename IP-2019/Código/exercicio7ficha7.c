#include <stdio.h>
#include <string.h>
#define TAMFRASE 80
#define TAMPAL 15

int func(char frase[], char palavra[], int tamf, int tamp);

void main()
{
    char f[TAMFRASE], p[TAMPAL];

    printf("Indique frase: "); gets(f);
    printf("Indique palavra: "); gets(p);

    if(func(f,p,TAMFRASE,TAMPAL))
        printf("Frase modificada: \n\t%s\n",f);
    else
        printf("Frase nao modificada!\n");
}

int func(char frase[], char palavra[], int tamf, int tamp)
{
    int i = strlen(frase), j, k;

    while(frase[i-1] == ' ')
        i--;

    while(frase[i-1] != ' ' && i - 1 >= 0)
        i--;

    if(i + strlen(palavra) <= tamf)
    {
        j = i + tamp;
            for(k=0;k<strlen(palavra);k++)
            {
                frase[i] = palavra[k];
                i++;
            }
            frase[i] = '\0';
            return 1;
    }
    else
        return 0;

}
