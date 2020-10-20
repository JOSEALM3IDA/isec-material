#include <stdio.h>
#include <string.h>
#define MAX 500

void main()
{
    int i;
    char frase[MAX];

    printf("Frase: ");
    gets(frase);

    for(i=0;i<strlen(frase);i++)
    {
        if (i==0)
        {
            do{
                if (frase[i] == ' ')
                    i++;
            }while (frase[i]==' ');
        }


        if (frase[i] == ' ' && frase[i+1] != ' ')
            printf("\n");
        else if(frase[i] != ' ')
            printf("%c",frase[i]);
    }

    printf("\n");
}

