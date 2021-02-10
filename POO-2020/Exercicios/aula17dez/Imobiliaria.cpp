#include "Imobiliaria.h"

void Imobiliaria::addImovel(Imovel *p) 
{
    v.push_back(p);
}

std::string Imobiliaria::getAsString() const 
{
    std::ostringstream os;

    os << "Imobiliaria " << nome << " tem " << v.size() << " imoveis:" << std::endl;
    for (Imovel *p : v) {
        os << *p << std::endl;
    }

    return os.str();
}

std::ostream& operator<<(std::ostream& out, const Imobiliaria& a)
{
    out << a.getAsString();

    return out;
}