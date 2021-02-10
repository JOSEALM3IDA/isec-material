#include "Tarifario.h"

Tarifario::Tarifario(const Tarifario& ref)
{
    if (tam == 0) {
        v = nullptr;
        tam = 0;
    } else {
        v = new int [tam];
        tam = ref.tam;

        for (int i = 0; i < tam; i++)
            v[i] = ref.v[i];
    }
}

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

    for (int i = 0; i < tam; i++)
        t[i] = v[i];

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