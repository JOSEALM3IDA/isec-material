#include "Caderno.h"

void Caderno::setLocal(string novoLocal) {
    if (!aberto)
        local = novoLocal;
}

int Caderno::getTotalPalavras() {
        int nPalavras = 0;
        string palavra;
        stringstream iss;
        iss.str(conteudo);

        while (iss >> palavra)
            nPalavras++;

        return nPalavras;
}

string Caderno::getAsString() const {
        ostringstream os;

        os << "Marca: " << marca << " Cor: " << cor << " nPag: " << nPag << " Local: " << local << endl 
           << "Texto: " << conteudo << endl;

        return os.str();
}