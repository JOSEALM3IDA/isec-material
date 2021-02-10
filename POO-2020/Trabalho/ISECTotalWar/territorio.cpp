#include "territorio.h"

void Territorio::setConquistado(bool b) {
    conquistado = b;
    tempoConquistado = conquistado ? 1 : 0;
}

errcode Territorio::atualizar(int turno) { 
    if (isConquistado())
        tempoConquistado++;

    return OK; 
}

string Territorio::getAsString() const {
    ostringstream os;

    os << nome << "   |   Producao: " << prodOuro << "o - " << prodProdutos << "p   |   resistencia: " << resistencia;
    if (isConquistado())
        os << "   |   Conquistado ha: " << tempoConquistado << " turnos";
    
    return os.str();
}

ostream& operator<<(ostream& out, const Territorio& a) {
    out << a.getAsString();

    return out;
}