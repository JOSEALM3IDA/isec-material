#include "Cartao.h"

bool Cartao::carrega(float valor) {
    if (t->carregaValor(valor) == true) {
        saldo += valor;
        return true;
    }
    return false;
}

string Cartao::getAsString() const {
    ostringstream os;
    
    os << "Cartao " << num << " com saldo " << saldo;       
    return os.str();
}

ostream& operator<<(ostream& out, const Cartao& c) {
    out << c.getAsString();

    return out;
}