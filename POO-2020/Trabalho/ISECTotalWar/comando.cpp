#include "comando.h"

string Comando::getAsString() const {
    ostringstream os;

    os << "Comando: " << getNome() << ' ' << args << endl << "Disponivel: " << (disponivel ? "sim" : "nao") << endl;
    os << "Descricao: " << descr;

    return os.str();
}

ostream& operator<<(ostream& out, const Comando& a) {
    out << a.getAsString();

    return out;
}