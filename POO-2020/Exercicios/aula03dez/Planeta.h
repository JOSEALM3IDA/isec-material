#ifndef PLANETA_H
#define PLANETA_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "Alien.h"

using namespace std;

class Planeta {
    string nome;
    vector<Alien*> pop;

public:

    Planeta(string s):nome(s) {}

    Planeta(const Planeta& ref);

    ~Planeta();

    bool existeAlien(string na) const;

    bool addAlien(Alien* a);
    bool rmAlien(string na);
    
    string getNome() const {return nome;}
    string getPop() const;

    Planeta& operator=(const Planeta& dir);

    string getAsString() const;
};

ostream& operator<<(ostream& out, const Planeta& x);

#endif /* PLANETA_H */

