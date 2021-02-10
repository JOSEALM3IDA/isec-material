#include "Aquario.h"

Aquario::Aquario(string a) 
    : nome(a) {}

Aquario::Aquario(const Aquario& ref, string novoNome) {
    nome = novoNome;
    for (int i = 0; i < ref.v.size(); i++) {
        v.push_back(new Peixe(*ref.v[i]));
        v[i]->setAq(this);
    }
}

Aquario::~Aquario() {
    for (Peixe *p : v)
        delete p;

    cout << "Xau Aquario " << nome << endl;
}

string Aquario::getNome() const {return nome;}

bool Aquario::addPeixe(Peixe *p) {
    if (existePeixe(p->getID()))
        return false;

    p->setAq(this);
    v.push_back(p);

    return true;
}

string Aquario::getAsString() const {
    ostringstream os;

    os << "Aquario " << nome << ":";

    for (Peixe *p : v) {
        os << '\t' << *p;
    }

    return os.str();
}

bool Aquario::existePeixe(int num) const {
    for (Peixe *p : v)
        if (p->getID() == num)
            return true;

    return false;
}

Aquario& Aquario::operator=(const Aquario& dir) {
    if (this == &dir) return *this;         //Self assignment

    for (int i = 0; i < v.size(); i++) {
        delete v[i];
        v.erase(v.begin() + i);
    }

    v.clear();

    nome = dir.nome;

    for (auto it = dir.v.begin(); it < dir.v.end(); it++) {
        addPeixe(*it);
    }

    return *this;
}

ostream& operator<<(ostream& out, const Aquario& x) {
    out << x.getAsString();

    return out;
}