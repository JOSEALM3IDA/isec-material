#include <stdio.h>

int maior(int n)
{
    int i = 1,conta = 1;
    int num, max;
    for(i=1;i<=n;i++)
    {
        printf("Insira um numero: ");
        scanf("%d",&num);
        if(i==1 || num > max)
        {
            max = num;
            conta = 1;
        }
        else if (num==max)
            conta++;
    }
    return (conta);
}

void main()
{
    int a;
    printf("Insira quantos numeros quer na sequencia: ");
    scanf("%d",&a);
    printf("\n");

    printf("\nVezes que o maior valor apareceu na sequencia: %d \n",maior(a));
}


/*
int receber(int a)
{
    int contador = 0, maior, anterior;
    for (int i=0;a<i;i++)
    {
        printf("Valor: ");
        scanf("%d",&maior);

        if(anterior==NaN)
            anterior=maior;
        else if (maior == anterior);
            contador++;
        else if (maior > anterior)
        {
            anterior = maior;
            contador = 0;
        }
    }

    return contador;
}

void main()
{
    int a;
    printf("Quantos numeros quer na sequencia? : ");
    scanf("%d",a);
    receber(a);
}
*/
