#ifndef SISTEMAPLANETARIO_H
#define SISTEMAPLANETARIO_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <initializer_list>

#include "Planeta.h"

using namespace std;

class SistemaPlanetario {
    vector<Planeta*> planetas;

public:

    SistemaPlanetario(initializer_list<Planeta*> il):planetas(il) {}

    SistemaPlanetario(const SistemaPlanetario& ref);
    
    ~SistemaPlanetario();
    
    bool existePlaneta(string pn) const;

    bool addPlaneta(Planeta* p);

    bool addAlien(Alien* a, string pn);

    bool mover(string na, string no, string nd);

    string getAsString() const;

};

ostream& operator<<(ostream& out, const SistemaPlanetario& x);

#endif /* SISTEMAPLANETARIO_H */

