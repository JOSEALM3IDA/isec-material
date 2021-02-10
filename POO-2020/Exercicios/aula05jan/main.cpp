#include "Tarifario.h"
#include "Apressado.h"

int main(int argc, char** argv)
{
    Tarifario* t = new Apressado;
    
    std::cout << t->calculaPagamento() << std::endl;
    
    t->acrescentaTreino(50);
    t->acrescentaTreino(500);

    std::cout << (*t) << std::endl;
    
    std::cout << t->calculaPagamento() << std::endl;

    t->acrescentaTreino(30);

    std::cout << t->calculaPagamento() << std::endl;
 
    delete t;
    return 0;
}

