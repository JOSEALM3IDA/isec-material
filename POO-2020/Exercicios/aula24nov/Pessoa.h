#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <sstream>

using namespace std;

class Pessoa {
    string nome;
    int cc, nif;
    
public:
    Pessoa(string a, int b, int c);

    string getNome() const;
    int getCC () const;
    int getNIF() const;
    
    void setNome(string a);
    
    string getAsString () const;
};

ostream& operator<<(ostream& out, const Pessoa& c);

#endif /* PESSOA_H */

