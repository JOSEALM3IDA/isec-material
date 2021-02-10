#include "Rede.h"

Rede::Rede(const Rede& ref) {
    for (Cartao* c : ref.cartoes)
        cartoes.push_back(c->clone());

    for (Tarifario* t : ref.tarifarios)
        tarifarios.push_back(t->clone());
}

Rede::~Rede() {
    for (Cartao* c : cartoes)
        delete c;

    for (Tarifario* t : tarifarios)
        delete t;
}

void Rede::addC(Cartao *c, int tarif) {
    for (Cartao* x : cartoes) {
        if (c->getNum() == x->getNum())
            return;
    }

    c->setT(tarifarios[tarif]);

    cartoes.push_back(c);
}

int Rede::getSaldo(int num) {
    for (Cartao* c : cartoes)
        if (num == c->getNum())
            return c->getSaldo();

    return -1;
}

void Rede::rmC(int num) {
    for (auto it = cartoes.begin(); it != cartoes.end(); it++)
        if (num == (*it)->getNum()) {
            cartoes.erase(it);
            return;
        }
            
}

bool Rede::autoriza(int num) const {
    for (Cartao* c : cartoes)
        if (num == c->getNum())
            return c->autorizaChamada();

    return false;
}

void Rede::regista(int num, int min) {
    for (Cartao* c : cartoes)
        if (num == c->getNum())
            c->registaChamada(min);
}

bool Rede::carrega(int num, int val) {
    for (Cartao* c : cartoes)
        if (num == c->getNum())
            return c->carrega(val);

    return false;
}

string Rede::getAsString() const {
    ostringstream os;

    os << "Cartoes: ";
    for (Cartao* c : cartoes)
        os << endl << *c;

    return os.str();
}

Rede& Rede::operator=(const Rede& dir) {
    if (this == &dir) return *this;         //Self assignment

    for (Cartao* c : cartoes)
        delete c;

    for (Tarifario* t : tarifarios)
        delete t;

    cartoes.clear();
    tarifarios.clear();

    for (Cartao* c : dir.cartoes)
        cartoes.push_back(c->clone());

    for (Tarifario* t : dir.tarifarios)
        tarifarios.push_back(t->clone());

    return *this;
}

ostream& operator<<(ostream& out, const Rede& r) {
    out << r.getAsString();

    return out;
}