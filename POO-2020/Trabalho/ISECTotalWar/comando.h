#ifndef COMANDO_H
#define COMANDO_H

#include <vector>
#include <string>
#include <sstream>

#include "error_codes.h"

using namespace std;

class Comando {
    string nome, descr, args;
    bool disponivel = false;

public:
    Comando(string n, string d, string a = "") : nome(n), descr(d), args(a) {}

    // Devolve o nome do comando
    string getNome() const { return nome; }

    // Devolve a descricao do comando
    string getDescr() const { return descr; }

    // Devolve os argumentos que o comando necessita
    string getArgs() const { return args; }

    // Muda a disponibilidade do comando
    void setDisp (bool novaDisp) { disponivel = novaDisp; }

    // Verifica se o comando esta disponivel
    bool isDisp () const { return disponivel; }

    string getAsString() const;
};

ostream& operator<<(ostream& out, const Comando& a);

#endif /* COMANDO_H */