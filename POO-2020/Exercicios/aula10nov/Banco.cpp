#include "Banco.h"

bool Banco::addConta(Pessoa p) {
    for (Conta &c : listaContas) {
        if (c.getTitular()->getCC() == p.getCC())
            return false;
    }

    Conta c = (&p);
    
    listaContas.push_back(c);
    return true;
}

bool Banco::atualizaSaldo(int cc, int dep) {
    for (Conta &c : listaContas) {
        if (c.getTitular()->getCC() == cc) {
            c.variarSaldo(dep);
            return true;
        }
    }

    return false;
}

float Banco::obterSaldo(int cc) const {
    for (Conta c : listaContas) {
        if (c.getTitular()->getCC() == cc)
            return c.getSaldo();
    }

    return -1;
}

float Banco::getTotalSaldos() const {
    float sum = 0;
    for (Conta c : listaContas)
        sum += c.getSaldo();

    return sum;
}

string Banco::getAsString() const {
    ostringstream os;

    os << "Banco: " << nome << endl;

    for(Conta c : listaContas) {
        os << c.getAsString() << endl;
    }

    return os.str();
}

void Banco::eliminarConta(int cc) {
    for (int i = 0; i < listaContas.size(); i++) {
        if (listaContas[i].getTitular()->getCC() == cc)
            listaContas.erase(listaContas.begin() + i);
    }
}

bool Banco::transferencia(int cc1 , int cc2, int montante, Banco &bd) {
    if (atualizaSaldo(cc1, -montante)) {
        bd.atualizaSaldo(cc2, montante);
        return true;
    }

    return false;
}