#include <stdio.h>
#include <ctype.h>

int caracteres(char ch);

void main()
{
    char c;
    printf("Insira um carater: ");
    scanf("%c",&c);
    printf("\n%d\n",caracteres(c));
}

int caracteres(char ch)
{
    ch = tolower(ch);
    int num = 0;
    switch (ch)
    {
        case('a'):
            num = 1;
            break;
        case('e'):
            num = 2;
            break;
        case('i'):
            num = 3;
            break;
        case('o'):
            num = 4;
            break;
        case('u'):
            num = 5;
    }
    return num;
}
