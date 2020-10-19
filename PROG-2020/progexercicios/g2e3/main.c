
#include <stdio.h>

//#include "ponto.h"      // Quero usar a estrutura struct ponto

#include "retangulo.h"

#define MAX 10


int main(){

    retangulo tab[MAX];     // 3a.
    int total=0;

    addR(tab, &total);      // 3b.
    addR(tab, &total);
    addR(tab, &total);

    printf("%d\n",total);

    escreveTodosR(tab, total);      // 3c.

    eliminaR(tab, &total);          // 3d -> Eliminar o retangulo com menor area

    printf("\n\n");

    escreveTodosR(tab, total);

    return 0;

}


