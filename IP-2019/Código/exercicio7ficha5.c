#include <stdio.h>

void triangulo(int linhas);

void main()
{
    int nLinhas;
    do{
        printf("Insira o numero de linhas: ");
        scanf("%d",&nLinhas);
    }while (nLinhas > 9 || nLinhas <= 1);
    triangulo(nLinhas);
}

void triangulo(int linhas)
{
    int esp = 0,i;
    int nL = linhas;
    for(int j=0;j<nL;j++)
    {
        for(i=0;i<esp;i++)
            printf("  ");
        for(i=1;i<linhas;i++)
            printf("%d ",i);
            for(i=linhas;i>0;i--)
                printf("%d ",i);
        linhas--;
        esp++;
        printf("\n");
    }
}
