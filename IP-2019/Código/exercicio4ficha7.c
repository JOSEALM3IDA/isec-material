#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 500

void main()
{
    char frase[MAX];
    char primeira[MAX];
    char palavra[MAX];
    int i = 0, j = 0, k = 0, vezes = 1;

    printf("Frase: ");
    gets(frase);

    //Desconsiderar espaços em branco no inicio: mover 'i' para o inicio da primeira palavra

    while(frase[i] == ' ')
        i++;

    //Mover 'j' para o final da primeira palavra

    j = i;

    while(frase[j] != ' ' && frase[j] != '\0')
        j++;
    j--;

    //Guardar a primeira palavra

    for(;i<=j;i++)
    {
        primeira[k] = tolower(frase[i]);
        k++;
    }
    primeira[k] = '\0';


    //Repetir até que a frase acabe (ou seja, repetir enquanto frase[j] != '\0' E frase[i] != 0
    while(frase[j] != '\0' && frase[i] != '\0')
    {
        // Guardar o index do primeiro char da palavra
        i = j + 1;
        while (frase[i] == ' ')
            i++;

        // Guardar o index do ultimo char da palavra
        j = i;
        while (frase[j] != ' ' && frase[j] != '\0')
            j++;
        j--;

        //Guardar a palavra a ser comparada
        k = 0;
        for(;i<=j;i++)
        {
            palavra[k] = tolower(frase[i]);
            k++;
        }
        palavra[k] = '\0';

        //Comparar com a primeira palavra
        if(strcmp(primeira,palavra)==0)
            vezes++;
    }

    printf("Palavra: %s \t Vezes: %d \n",primeira,vezes);

}



/*
void main()
{
    char frase[MAX];
    char primeira[MAX];
    char palavra[MAX];
    int i = 0, k = 0 , j , z , vezes = 1;

    printf("Frase: ");
    gets(frase);

    while(frase[i] == ' ')
        i++;

    j = i;
    z = i;

    while(i<strlen(frase))
    {
        while(frase[j] != ' ')
            j++;
        i++;
    }

    while(z<j)
    {
        primeira[k] = frase[z];
        k++;
        z++;
    }
    primeira[k] = '\0';

    i = j;
    z = j;
    k = 0;

    while(frase[j] == ' ')
        j++;

    while(frase[i] != '\0')
    {
        while(i<strlen(frase))
        {
            while(frase[j] != ' ')
            j++;
            i++;
        }

        while(z<j)
        {
            palavra[k] = frase[z];
            k++;
            z++;
        }

        if(strcmp(primeira,palavra)==0)
            vezes++;

        i = j;
        z = j;
        k = 0;

        while(frase[j] == ' ')
            j++;
    }



    printf("A palavra: '");
    printf("%s",primeira);
    printf("' apareceu %d vezes.",vezes);
}
*/

