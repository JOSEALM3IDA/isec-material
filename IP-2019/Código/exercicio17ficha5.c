#include <stdio.h>
#include <ctype.h>

int ler();

void main()
{
    char c;
    printf("Insira uma palavra: ");

    printf("Numero de letras: %d\n",ler());
}

int ler()
{
    char ch;
    int num = 0;
    do{
        scanf("%c",&ch);
        ch = toupper(ch);
        printf("%c ",ch);
        num++;
    }while(ch!= '\n');

    return num-1;
}
