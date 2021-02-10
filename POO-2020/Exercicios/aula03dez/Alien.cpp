#include "Alien.h"

Alien::~Alien() {
    cout << "D alien " << nome << endl;
}

string Alien::getAsString() const {
    ostringstream os;

    os << getNome() << " " << getEn();

    return os.str();
}

ostream& operator<<(ostream& out, const Alien& x) {
    out << x.getAsString();

    return out;
}