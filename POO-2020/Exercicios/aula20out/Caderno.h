#ifndef CADERNO_H
#define CADERNO_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Caderno {
    const string marca, cor;
    string local;
    const int nPag, alt, larg;
    bool aberto;
    string conteudo;

    public:

    Caderno(string a, string b, int c, int d, int e, string f)
    : marca(a), cor(b), nPag(c), alt(d), larg(e), local(f) {
        aberto = false;
        conteudo = "";
    }

    ~Caderno() {
        cout << "Xau caderno " << marca << "!" << endl;
    }

    void setLocal(string novoLocal);

    void abrir() { aberto = true; }
    
    void fechar() { aberto = false; }

    string getLocal() const { return local; }

    int getPaginas() const { return nPag; }

    void escrever(string novo) {
        if(aberto)
            conteudo += novo + '\n';
    }

    string obtemTexto() const { 
        if (!aberto)
            return conteudo;
        else
            return "";
    }

    int getTotalPalavras();

    string getAsString() const;
};

#endif /* CADERNO_H */