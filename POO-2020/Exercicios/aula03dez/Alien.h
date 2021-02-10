#ifndef ALIEN_H
#define ALIEN_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Alien {
    string nome;
    int energia;
public:
    Alien(string s):nome(s), energia(10){}
    
    ~Alien();
    
    string getNome() const {return nome;}
    int getEn() const {return energia;}

    string getAsString() const;

};

ostream& operator<<(ostream& out, const Alien& x);

#endif /* ALIEN_H */

