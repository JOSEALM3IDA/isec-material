#include "planicie.h"

int Planicie::count = 1;

errcode Planicie::atualizar(int turno) {
    incrTConquistado();
            
    if (turno == 7)
        setProd(2);
    
    return OK;
}

