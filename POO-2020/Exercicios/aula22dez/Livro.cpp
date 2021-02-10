#include "Livro.h"

std::string Livro::getAsString() const
{
    std::ostringstream os;
    
    os << autor << ". " << titulo << ", ISBN: " << isbn;
    return os.str();
}   

std::ostream& operator<<(std::ostream& out, const Livro& l)
{
    out << l.getAsString();

    return out;
}