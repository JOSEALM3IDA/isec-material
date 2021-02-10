#ifndef GINASIO_H
#define GINASIO_H

#include <vector>
#include <sstream>

#include "Cliente.h"

class Ginasio{
    std::vector<Cliente*> v;
    int tempo, aTreinar;
public:
    Ginasio() : tempo(0), aTreinar(0) {}
    Ginasio(const Ginasio& ref);
    
    virtual ~Ginasio();     // Eliminar clientes

    int getATreinar() const { return aTreinar; }
    
    void addCliente(Cliente* p) { v.push_back(p); p->ligaGin(this); }
    
    void passaTempo(int x) { tempo += x; }
    
    void registaEntrada(int cc);
    
    void registaSaida(int cc);
    
    int pagamento(int cc);

    std::string getAsString() const;

    Ginasio& operator=(const Ginasio& dir);
};

std::ostream& operator<<(std::ostream& out, const Ginasio& g);

#endif /* GINASIO_H */