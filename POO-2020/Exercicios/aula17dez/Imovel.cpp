#include "Imovel.h"

int Imovel::conta = 1;

std::string Imovel::getAsString() const
{
    std::ostringstream os;
    
    os << getID() << " - Area: " << area << " Andar: " << andar << " Preco: " << preco;
    return os.str();
}

std::ostream& operator<<(std::ostream& out, const Imovel& a)
{
    out << a.getAsString();

    return out;
}