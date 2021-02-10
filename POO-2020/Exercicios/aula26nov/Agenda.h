#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include <iostream>
#include <sstream>
#include "Contacto.h"

class Agenda{
    vector<Contacto*> v;

    int encontraContacto(string a) const;
    int encontraContacto(int n) const;

    public:

    Agenda() = default;

    Agenda(const Agenda& ref){
        for (auto it = ref.v.begin(); it < ref.v.end(); it++) {
            addContacto((*it)->getNome(), (*it)->getTel());
        }
    }

    ~Agenda() { // Se precisamos de destrutor para apagar memoria dinamica, precisamos de ter cuidado com a robustez da classe: implementar o construtor por copia e o operador de atribuição
        for (int i = 0; i < v.size(); i++)
            delete v[i];
    }

    bool addContacto(string nome, int tel);     // Impede a adição de contactos com nomes repetidos e devia organizar por ordem alfabetica
    
    int getTel(string a) const;     // Devolve telefone do Contacto a (-1 se não existir)
    
    bool atualizaContacto(string a, int nt);    // Atualiza numero do contacto a
    
    bool eliminaContacto(int t);        // Elimina contacto com este numero
    
    Agenda& operator=(const Agenda& dir);

    string getAsString() const;
};

ostream& operator<<(ostream& out, const Agenda& ref);


#endif /* AGENDA_H */

