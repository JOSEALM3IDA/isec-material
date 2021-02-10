#include "Retangulo.h"
#include <iostream>

string Retangulo::getAsString() const {
    ostringstream os;

    os << "CSE: (" << cse.getAsString() << ") Larg: " << larg << " Alt: " << alt;

    return os.str();
}

vector<Ponto> Retangulo::getVertices() const {
    vector<Ponto> v;

    v.push_back(getCSE());
    v.push_back(getCSD());
    v.push_back(getCIE());
    v.push_back(getCID());

    return v;
}

bool Retangulo::hasInside(Ponto p) const {

    if (getCSE().getX() < p.getX() && getCSE().getY() > p.getY() &&
        getCID().getX() > p.getX() && getCID().getY() < p.getY()) {
        return true;
    }

    //cout << p.getAsString() << " nao dentro de retangulo " << getCSE().getAsString() << endl;
    

    return false;
}

bool Retangulo::isSobreposto(Retangulo r) const {
    vector<Ponto> v = getVertices();

    for (Ponto p : v) {
        if (r.hasInside(p)) { // Se algum dos vertices de r estiver dentro do retangulo
            return true;
        }
    }

    return false;
}