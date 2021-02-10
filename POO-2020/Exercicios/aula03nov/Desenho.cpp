#include "Desenho.h"

bool Desenho::addR(Retangulo r) {
    vector<Ponto> vertices;

    for(Retangulo r2 : v)
        if (r2.isSobreposto(r)) // Nao implementado corretamente
            return false;

    auto it = v.begin();
    while (it < v.end() && it->getArea() < r.getArea())
        it++;
    
    v.insert(it, r);

    return true;
}

int Desenho::areaTotal() const {
    int sum = 0;

    for(Retangulo var : v) {
        sum += var.getArea();
    }

    return sum;
}

string Desenho::getAsString() const {
    ostringstream os;

    os << "Nome: " << nome << endl;

    for(auto var : v) {
        os << "\t" << var.getAsString() << endl;
    }

    return os.str();
}

vector<Retangulo> Desenho::getRLocal(Ponto p) const {
    vector<Retangulo> rets;

    for(Retangulo r : v) {
        if (r.getCSE().igual(p)) {
            rets.push_back(r);
        }
    }

    return rets;
}

void Desenho::elimina(int lim) {

    auto it = v.begin();
    while (it < v.end())
        if (it->getArea() < lim)
            it = v.erase(it); // O erase invalida o iterador
        else
            it++;
}