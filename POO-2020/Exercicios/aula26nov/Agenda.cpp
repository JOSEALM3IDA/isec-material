#include "Agenda.h"

int Agenda::encontraContacto(string a) const {
    for(int i = 0; i < v.size(); i++) {
        if (v[i]->getNome() == a)
            return i;
    }

    return -1;
}

int Agenda::encontraContacto(int n) const {
    for(int i = 0; i < v.size(); i++) {
        if (v[i]->getTel() == n)
            return i;
    }

    return -1;
}

bool Agenda::addContacto(string nome, int tel) {
    if (encontraContacto(nome) == -1) {
        v.push_back(new Contacto(nome, tel));
        return true;
    } else return false;
}

int Agenda::getTel(string a) const { 
    int i = encontraContacto(a);
    if (i != -1)
        return v[i]->getTel();
    else return -1;
}

bool Agenda::atualizaContacto(string a, int nt) {
    int i = encontraContacto(a);
    if (i != -1) {
        v[i]->setTel(nt);
        return true;
    } else return false;
}

bool Agenda::eliminaContacto(int t) {
    int i = encontraContacto(t);
    if (i != -1) {
        delete v[i];
        v.erase(v.begin() + i);
        return true;
    } else return false;
}

Agenda& Agenda::operator=(const Agenda& dir) {
    if (this == &dir) return *this;         //Self assignment

    for (int i = 0; i < v.size(); i++) {
        delete v[i];
        v.erase(v.begin() + i);
    }

    v.clear();
    
    for (auto it = dir.v.begin(); it < dir.v.end(); it++) {
        addContacto((*it)->getNome(), (*it)->getTel());
    }

    return *this;
}

string Agenda::getAsString() const {
    ostringstream os;

    os << "Numero de Contactos: " << v.size() << endl;

    for (const Contacto *pc : v) {
        os << *pc << endl;
    }

    return os.str();
}

ostream& operator<<(ostream& out, const Agenda& ref) {
    out << ref.getAsString();
    return out;
}