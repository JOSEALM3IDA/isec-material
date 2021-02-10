#include "pescaria.h"

int Pescaria::count = 1;

errcode Pescaria::atualizar(int turno) {
    incrTConquistado();

    if (turno == 7)
        setProd(4);
    
    return OK;
}
