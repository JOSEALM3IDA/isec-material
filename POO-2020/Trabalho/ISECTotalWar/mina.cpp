#include "mina.h"

int Mina::count = 1;

errcode Mina::atualizar(int turno) {
    incrTConquistado();
    
    if (turno == 1 || turno == 7)
        setOuro(1);
    else if (turno == 4 || turno == 10)
        setOuro(2);
    
    return OK;
}
