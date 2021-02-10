#include "tecnologia.h"

string Tecnologia::getAsString() const {
    ostringstream os;

    os << "Nome: " << nome << "\tCusto: " << custo << " de ouro" << endl << "Descricao: " << descr;

    return os.str();
}

ostream& operator<<(ostream& out, const Tecnologia& a) {
    out << a.getAsString();

    return out;
}