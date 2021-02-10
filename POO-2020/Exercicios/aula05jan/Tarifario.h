#ifndef TARIFARIO_H
#define TARIFARIO_H

#include <iostream>
#include <sstream>

class Tarifario {
    int *v;
    int tam;   
    
protected:
    void apagaTreinos();    // Eliminar o array dinâmico de inteiros
    const int* getV() { return v; }
    int getTam() { return tam; }
    
public:
    Tarifario() : v(nullptr), tam(0) {}
 
    virtual ~Tarifario() { delete [] v; }
    
    void acrescentaTreino(int x);

    virtual int calculaPagamento() = 0; // MÉTODO VIRTUAL PURO

    std::string getAsString() const;
};

std::ostream& operator<<(std::ostream& out, const Tarifario& t);

#endif /* TARIFARIO_H */

