#include "Clube.h"

bool Clube::setMembro(Pessoa *p) {
    if (conta < tam) {
        tab[conta++] = p;
        return true;
    } else return false;
}

bool Clube::eliminaMembro(int cc) {
    for (int i = 0; i < tam; i++) {
        if (tab[i]->getCC() == cc) {
            tab[i] = tab[--conta];
            tab[conta] = nullptr;
            return true;
        }
    }

    return false;
}

string Clube::getAsString() const {
    ostringstream os;

    os << "Nome: " << nome << "\tN Membros maximo: " << tam << "\tN Membros atual: " << conta << endl << "Membros: " << endl;

    for (int i = 0; i < conta; i++) {
        os << (*tab[i]) << endl;
    }

    return os.str();
}

Clube& Clube::operator=(const Clube& dir) {
    if (this == &dir) return *this;         //Self assignment
    
    nome = dir.nome;
    tam = dir.tam;
    conta = dir.conta;

    delete [] tab;

    tab = new Pessoa*[tam];
    for (int i = 0; i < tam; i++) {
        tab[i] = dir.tab[i];
    }

    return *this;
}

ostream& operator<<(ostream& out, const Clube& c) {
    out << c.getAsString();

    return out;
}