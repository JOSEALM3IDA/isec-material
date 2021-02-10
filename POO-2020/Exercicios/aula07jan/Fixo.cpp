#include "Fixo.h"

int Fixo::calculaPagamento() 
{
    int preco = 0;
    const int *v = getV();
    int tam = getTam();

    for (int i = 0; i < tam; i++) {
        preco += v[i];
    }
    
    apagaTreinos();

    return preco;
}