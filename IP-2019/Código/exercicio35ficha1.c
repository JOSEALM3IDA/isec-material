#include <stdio.h>

void main()
{
    int A,B,C,D,E,F,soma = 0;

    printf("A:");
    scanf("%d",&A);
    printf("B:");
    scanf("%d",&B);
    printf("C:");
    scanf("%d",&C);
    printf("D:");
    scanf("%d",&D);
    printf("E:");
    scanf("%d",&E);
    printf("F:");
    scanf("%d",&F);

    for(int i=A;i<=B;i++)
    {
        for(int j=C;j<=D;j++)
        {
            for(int y=E;y<=F;y++)
                soma += i*j*y;
        }
    }

    printf("Resultado: %d\n",soma);
}
