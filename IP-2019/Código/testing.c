#include <stdio.h>

/*
void main()
{
    float lado,perimetro;

    do{
        printf("Insira medida do lado: ");
        scanf("%f",&lado);
    }while(lado<=0);

    perimetro=3*lado;
    printf("Perimetro = %.2f\n",perimetro);
}
*/

void main()
{
    int num;

    do{
        printf("Indique o numero da tabuada que pretende: ");
        scanf("%d",&num);
    }while(num<1 || num>10);


    /*
    int i = 1;
    while(i<=10)
    {
        printf("%d x %d = %d\n", num,i,num*i);
        i++;

    */

    /*
    for(int i=1;i<=10;i++)
        printf("%d x %d = %d\n", num,i,num*i);
    */

    int i = 1;

    do{
        printf("%d x %d = %d\n", num,i,num*i);
        i++;
    }while(i>=1 && i<=10);
}
