#ifndef CLUBE_H
#define CLUBE_H

#include <iostream>
#include "Pessoa.h"

class Clube {
    string nome;
    int tam;
    Pessoa **tab;
    int conta;
    
    public:
    Clube(string a, int b):nome(a), tam(b), conta(0) {
        tab = new Pessoa*[tam];
        for(int i=0;i<tam; i++)
            tab[i] = nullptr;
    }

    //Clube (const Clube&) {
    //
    //}

    // falta implementar construtor por copia

    ~Clube() { delete [] tab; }
    
    bool setMembro(Pessoa *p);          // Adiciona novo Sócio (se ainda existir espaço)
    
    bool eliminaMembro(int cc);         // Elimina Sócio, dado cc
    
    string getAsString() const;         // Obtem descrição textual
    
    Clube& operator=(const Clube& dir);
};

ostream& operator<<(ostream& out, const Clube& c);

#endif /* CLUBE_H */

