
#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"

int main(int argc, char** argv) {

    retangulo ret = {0,0, 2, 2}, ret2;
    printR(ret);
    //deslocarR(&ret, 2,2);
    printf("%.1f", areaR(ret));
    //initR(&ret2);
    //printR(ret2);

    //ponto2D p1 = {1,3}, p2, p3 = {3,9};

    //printPonto(p1);

    //printf("\n%d\n", dentroR(ret, p1));

    /*
    initPonto(&p2);
    
    printPonto(p2);

    movePonto(&p1, 3, -2);
    printPonto(p1);

    mesmaReta(&p1, &p2, &p3);

    return 0;
     */
}

