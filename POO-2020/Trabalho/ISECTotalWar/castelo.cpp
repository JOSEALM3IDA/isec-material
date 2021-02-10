#include "castelo.h"

int Castelo::count = 1;

errcode Castelo::atualizar(int turno) {
    incrTConquistado();

    if (turno == 1 || turno == 7)
        setProd(3);
    else if (turno == 3 || turno == 9)
        setProd(0);
    
    return OK;
}

