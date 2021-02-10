#include "Retangulo.h"

string Retangulo::getAsString() const {
    ostringstream os;

    os << "CSE: (" << cse.getAsString() << ") Larg: " << larg << " Alt: " << alt;

    return os.str();
}