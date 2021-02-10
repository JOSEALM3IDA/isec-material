#include "Contacto.h"

string Contacto::getAsString() const {
    ostringstream os;

    os << "Nome: " << getNome() << "\tContacto: " << getTel();

    return os.str();
}

ostream& operator<<(ostream& out, const Contacto& ref) {
    out << ref.getAsString();

    return out;
}