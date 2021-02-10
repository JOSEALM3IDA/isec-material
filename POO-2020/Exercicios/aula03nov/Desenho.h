#ifndef DESENHO_H
#define DESENHO_H

#include <vector>
#include "Retangulo.h"

class Desenho {
    string nome;
    vector<Retangulo> v;

public:
    Desenho(string s): nome(s){}
    
    bool addR(Retangulo r);     // Adiciona Retangulo r ao Desenho
    
    int areaTotal() const;      // Devolve soma das areas dos retangulos do Desenho
    
    string getAsString() const; // Obtem descrição textual completa (Nome + Retangulos)

    vector<Retangulo> getRLocal(Ponto p) const; // Devolve conjunto de retangulos com cse no Ponto p

    vector<Retangulo>::iterator procurar(int area) const;

    void elimina(int lim); // Elimina todos os retangulos com area inferior ao limite
};

#endif /* DESENHO_H */

