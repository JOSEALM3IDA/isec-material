#include "Ponto.h"

string Ponto::getAsString() const {
    ostringstream os;

    os << "x: " << x << " y: " << y;

    return os.str();
}