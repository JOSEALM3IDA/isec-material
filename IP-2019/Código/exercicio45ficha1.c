#include <stdio.h>

int divisores(n)
{
    int conta = 0;
    int i = 1;
    while(i<=n)
    {
        if(n%i == 0)
            conta++;
        i++;
    }
    return(conta);
}

void main()
{
    int n,nDiv;
    do{
        printf("Insira um numero: ");
        scanf("%d",&n);
        if(n>0)
        {
            nDiv = divisores(n);
            if(nDiv == 2)
                printf("O numero que inseriu e primo.\n");
        }
    }while(n>0);
}
