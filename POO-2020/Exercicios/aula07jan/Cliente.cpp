#include "Cliente.h"

Cliente::Cliente(const Cliente& ref)
{
    nome = ref.nome;
    start = ref.start;
    cc = ref.cc;
    emTreino = ref.emTreino;

    t = ref.t->clone();
}

void Cliente::iniciaTreino(int x)
{
    if (!emTreino) {
        start = x;
        emTreino = true;
    }
}

void Cliente::terminaTreino(int x)
{
    if (emTreino) {
        t->acrescentaTreino(x - start);
        start = -1;
        emTreino = false;
    }
}

std::string Cliente::getAsString() const {
    std::ostringstream os;

    os << "Nome: " << nome << "\t\tCC: " << cc << "\t\tTarifarios: " << (*t);

    return os.str();
}

Cliente& Cliente::operator=(const Cliente& dir)
{
    if (this == &dir) return *this;         //Self assignment

    delete t;
    
    nome = dir.nome;
    start = dir.start;
    cc = dir.cc;
    emTreino = dir.emTreino;

    t = dir.t->clone();

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Cliente& c)
{
    out << c.getAsString();

    return out;
}