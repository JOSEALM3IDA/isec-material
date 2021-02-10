#ifndef PONTO_H
#define PONTO_H

#include <sstream>
#include <cmath>

using namespace std;

class Ponto {
    int x, y;

    public:

    Ponto(int a = 0, int b = 0) : x(a), y(b) {}

    string getAsString() const;

    void setX(int a) { x = a; }
    int getX() const { return x; }

    void setY(int a) { y = a; }
    int getY() const { return y; }

    float dist(Ponto b = Ponto(0,0)) const { return sqrt( pow(x - b.getX(), 2) + pow(y - b.getY() , 2) ); }

    bool igual(const Ponto p2) {
        if (getX() == p2.getX() && getY() == p2.getY())
            return true;
        else
            return false;
    }
};

#endif /* PONTO_H */