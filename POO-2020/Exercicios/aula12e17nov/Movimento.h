#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Movimentos {
    string nome;
    int saldo;
    vector<int> v;

    public:

    int getSaldo() const { return saldo; }

    void setSaldo(int val) { saldo = val; }

    string getAsString() const;

    Movimentos(string s, int v) : nome(s), saldo(v) {}

    Movimentos operator+(int val) const;

    Movimentos operator-(int val) const;

    Movimentos& operator+=(int val);
};

bool operator==(const Movimentos a, const Movimentos b);

ostream& operator<<(ostream& out, const Movimentos& a);

#endif /* MOVIMENTO_H */