#ifndef FRACAO_H
#define FRACAO_H

#include <string>
#include <sstream>

using namespace std;

class Fracao {
    int num, den;

    public:
    
    // explicit proíbe a construção implícita (por exemplo, proíbe converter o 2 durante x == 2)
    explicit Fracao(int a = 0, int b = 1) : num(a), den(b > 0 ? b : 1) {} // o explicit é devido à ambiguidade causada pela implementação dos casts nas comparações lógicas

    int getNum() const {return num;}
    int getDen() const {return den;}

    void setNum(int a) {num = a;}
    void setDen(int a) {if (a > 0) den = a;}

    string getAsString() const {
        ostringstream os;

        os << "(" << num << "/" << den << ")";

        return os.str();
    }

    //Fracao operator* (Fracao b) {
    //    b.setNum(b.getNum() * num);
    //    b.setDen(b.getDen() * den);
    //
    //    return b;
    //}

    Fracao& operator*=(const Fracao& b); // Resumidamente, aplicar o & no return permite aplicacao sucessiva do operador ao mesmo objeto

    Fracao& operator++(); // ++x

    const Fracao operator++(int); // x++

    operator int() const { return num/den; } // Obrigatoriamente escrito dentro da classe
};

Fracao operator*(const Fracao& a, const Fracao& b); // Mais versatil se for de fora da classe

//Fracao operator*=(const Fracao& a, const Fracao& b); // Nao tem vantagens a estar fora da classe, logo poe-se dentro

ostream& operator<<(ostream& out, const Fracao& a); // Obrigatoriamente tem de estar fora da classe

bool operator==(const Fracao a, const Fracao b);

bool operator!=(const Fracao a, const Fracao b);

bool operator<(const Fracao a, const Fracao b);

bool operator<=(const Fracao a, const Fracao b);

bool operator>(const Fracao a, const Fracao b);

bool operator>=(const Fracao a, const Fracao b);

#endif /* FRACAO_H */