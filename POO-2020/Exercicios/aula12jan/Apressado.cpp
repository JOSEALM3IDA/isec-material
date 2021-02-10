#include "Apressado.h"

int Apressado::calculaPagamento() 
{
    int preco = 0;
    const int *v = getV();
    int tam = getTam();

    for (int i = 0; i < tam; i++) {
        if (v[i] <= 10)
            preco += 10;
        else if (v[i] <= 20)
            preco += 15;
        else
            preco += 25;
    }
    apagaTreinos();

    return preco;
}