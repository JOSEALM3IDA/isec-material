#include <stdio.h>

int cubo(int num);
int devolver();
int propriedade(int num);

void main()
{
    char continuar;

    do{
        if(propriedade(devolver())==1)
            printf("O numero verifica a propriedade!\n\n");
        else
            printf("O numero nao verifica a propriedade!\n\n");
        printf("Insira 'S' se pretende continuar.  ");
        fflush(stdin);
        scanf("%c",&continuar);
    }while(continuar=='s' || continuar=='S');
}

int cubo(int num)
{
    int result;

    result = num * num * num;

    return result;
}

int devolver()
{
    int num;
    do{
        printf("Insira um numero inteiro entre 100 e 999: ");
        scanf("%d",&num);
    }while(num<100 || num>999);

    return num;
}

int propriedade(int num)
{
    int k, soma = 0, resto = 0, x = num;

    for(k=0;k<3;k++)
    {
        resto = x%10;
        soma += cubo(resto);
        x = x/10;
    }

    if (soma==num)
        return 1;
    else
        return 0;
}
