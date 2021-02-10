#include "FC.h"

std::string FC::getAsString() const
{
    std::ostringstream os;
    
    os << Livro::getAsString() << " " << planeta << " " << ano;
    return os.str();
}