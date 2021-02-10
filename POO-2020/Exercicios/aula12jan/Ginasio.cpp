#include "Ginasio.h"

Ginasio::Ginasio(const Ginasio& ref)
{
    tempo = ref.tempo;
    aTreinar = ref.aTreinar;

    for (Cliente *c : ref.v) {
        v.push_back(c->clone());
    }
}

Ginasio::~Ginasio() {
    for (Cliente* c : v) {
        delete c;
    }
}

void Ginasio::registaEntrada(int cc) {
    for (Cliente* c : v) {
        if (c->getCC() == cc) {
            if (c->iniciaTreino(tempo)) {
                aTreinar++;
                for (Cliente* x : v)
                    if (x != c)
                        x->reageEntrada();
                return;
            }
        }
    }
}

void Ginasio::registaSaida(int cc) {
    for (Cliente* c : v) {
        if (c->getCC() == cc) {
            if (c->terminaTreino(tempo)) {
                aTreinar--;
                for (Cliente* x : v)
                    x->reageSaida();
                return;
            }
        }
    }
}

int Ginasio::pagamento(int cc) {
    for (Cliente* c : v)
        if (c->getCC() == cc)
            return c->paga();

    return -1;
}

std::string Ginasio::getAsString() const {
    std::ostringstream os;

    os << "Tempo atual: " << tempo << "\t\tA treinar: " << aTreinar << std::endl;
    for (Cliente* c : v) {
        os << *c << std::endl;
    }

    return os.str();
}

Ginasio& Ginasio::operator=(const Ginasio& dir)
{
    if (this == &dir) return *this;         //Self assignment

    for (Cliente* c : v)
        delete c;

    v.clear();


    tempo = dir.tempo;
    aTreinar = dir.aTreinar;

    for (Cliente *c : dir.v) {
        v.push_back(c->clone());
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Ginasio& g)
{
    out << g.getAsString();

    return out;
}