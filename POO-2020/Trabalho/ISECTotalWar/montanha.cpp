#include "montanha.h"

int Montanha::count = 1;

errcode Montanha::atualizar(int turno) {
    incrTConquistado();

    if (isConquistado() && getTConquistado() == 3)
        setProd(1);
    
    return OK;
}
