#include <stdio.h>

int  verificaLimites(int n,int sup,int inf);

void main()
{
    int num,limS,limI;
    char op;

    printf("Insira o limite inferior e superior: ");
    scanf("%d%d",&limI,&limS);
    do{
        printf("\nInsira o numero: ");
        scanf("%d",&num);

        if (verificaLimites(num,limS,limI)==1)
            printf("DENTRO\n\n");
        else
            printf("FORA\n\n");

        printf("Continuar?\t");
        fflush(stdin);
        scanf("%c",&op);
    }while (op=='S' || op=='s');

}

int verificaLimites(int n,int sup,int inf)
{
    if (n<=sup && n>=inf)
        return 1;
    else
        return 0;
}
