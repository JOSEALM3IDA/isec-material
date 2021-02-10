#ifndef SAVE_H
#define SAVE_H

#include "mundo.h"

class Save {
    std::string nome;
    Mundo mnd;
    int faseAtual; // -1 -> setup; 0 -> conquista; 1 -> recolha; 2 -> compra; 3 -> eventos; 4 -> fim de jogo;
    
public:
    Save(std::string n, Mundo& m, int f) : nome(n), mnd(m), faseAtual(f) {}

    // Devolve o nome do save
    std::string getNome() const { return nome; }

    // Devolve o mundo guardado no save
    Mundo getMundo() const { return mnd; }

    // Devolve a fase guardada no save
    int getFase() const { return faseAtual; }
};

#endif /* SAVE_H */