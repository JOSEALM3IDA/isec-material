#include "Pessoa.h"

Pessoa::Pessoa(string a, int b, int c):nome(a), cc(b), nif(c){}
    
string Pessoa::getNome() const {return nome;}

int Pessoa::getCC () const {return cc;}

int Pessoa::getNIF() const {return nif;}
    
void Pessoa::setNome(string a) {nome=a;}
    
string Pessoa::getAsString () const{
    ostringstream os;
    
    os << "Nome: " << nome << "  CC: " << cc << "  NIF: " << nif;
    return os.str();
}

ostream& operator<<(ostream& out, const Pessoa& c) {
    out << c.getAsString();

    return out;
}