#include "Planeta.h"

Planeta::Planeta(const Planeta& ref) {
    for (Alien *a : ref.pop)
        addAlien(new Alien(a->getNome()));
}

Planeta::~Planeta() {
    for (Alien *a : pop)
        delete a;

    cout << "D planeta " << nome << endl;
}

bool Planeta::existeAlien(string na) const {
    for (Alien *a : pop)
        if (a->getNome() == na)
            return true;

    return false;
}

bool Planeta::addAlien(Alien* a) {
    if (!existeAlien(a->getNome())) {
        pop.push_back(a);
        return true;
    }

    return false;
}

bool Planeta::rmAlien(string na) {
    for (auto it = pop.begin(); it < pop.end(); it++)
        if ((*it)->getNome() == na) {
            pop.erase(it);
            return true;
        }

    return false;
}

string Planeta::getPop() const {
    ostringstream os;

    for (Alien* a : pop) {
        os << *a << "; ";
    }

    return os.str();
}

Planeta& Planeta::operator=(const Planeta& dir) {
    if (this == &dir) return *this;         //Self assignment

    for (int i = 0; i < pop.size(); i++) {
        delete pop[i];
        pop.erase(pop.begin() + i);
    }

    pop.clear();

    for (auto it = dir.pop.begin(); it < dir.pop.end(); it++) {
        addAlien((*it));
    }

    return *this;
}

string Planeta::getAsString() const {
    ostringstream os;

    os << getNome() << ": " << getPop();

    return os.str();
}

ostream& operator<<(ostream& out, const Planeta& x) {
    out << x.getAsString();

    return out;
}