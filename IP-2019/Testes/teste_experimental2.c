#include <stdio.h>

float valor (int horas, int minutos)
{
    float valor;
    if (horas == 0)
        valor = 0;
    else if (horas == 1 || horas == 2)
        valor = (((horas-1)*60+minutos)/15)*0.1;
    else
        valor = 0.8 + (((horas-3)*60+minutos)/15)*0.2;

    return valor;
}

void main()
{
    int nClientes, cliente, horas, minutos;
    float medio, preco;
    printf("Numero de clientes > ");
    scanf("%d",&nClientes);
    medio = 0;
    cliente = 1;

    while (cliente<=nClientes)
    {
        do{
            printf("\nCliente: %.2d\n",cliente);
            printf("Horas e minutos > ");
            scanf("%d:%d",&horas,&minutos);
        }while(horas < 0 || minutos < 0 || minutos >= 60);

        preco = valor(horas,minutos);

        if (preco==0)
            printf("Pode sair. Nao tem de pagar\n");
        else
        printf("Valor a pagar = %.2f\n",preco);

        medio += preco;
        cliente++;
    }
    medio/=nClientes;
    printf("\nCusto medio por cliente = %.2f\n",medio);
}
