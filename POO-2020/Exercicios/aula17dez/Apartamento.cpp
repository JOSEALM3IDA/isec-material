#include "Apartamento.h"

std::string Apartamento::getAsString() const 
{
    std::ostringstream os;
    
    os << Imovel::getAsString() << " N.Quartos: " << quartos;
    return os.str();
}