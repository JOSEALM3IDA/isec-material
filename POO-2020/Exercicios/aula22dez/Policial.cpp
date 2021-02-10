#include "Policial.h"

std::string Policial::getAsString() const
{
    std::ostringstream os;
    
    os << Livro::getAsString() << ". " << nomeDet;

    if (nTiros > 10) {
        os << " Nao aconselhado a criancas";
    } else {
        os << " " << nTiros;
    }

    return os.str();
}   