#include "Tarifario.h"

void Tarifario::apagaTreinos()
{
    if (v != nullptr) {
        delete [] v;
        tam = 0;
        v = nullptr;
    }
}

void Tarifario::acrescentaTreino(int x)
{
    int *t = new int [tam + 1];

    if (!t) return;

    for (int i = 0; i < tam; i++) {
        t[i] = v[i];
    }

    if (v != nullptr) delete [] v;

    v = t;

    v[tam++] = x;
}

std::string Tarifario::getAsString() const
{
    std::ostringstream os;

    for (int i = 0; i < tam; i++)
        os << v[i] << ' ';

    os << '(' << tam << ')';

    return os.str();
}

std::ostream& operator<<(std::ostream& out, const Tarifario& t)
{
    out << t.getAsString();

    return out;
}