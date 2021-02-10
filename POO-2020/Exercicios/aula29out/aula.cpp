#include <iostream>
#include "Ponto.h"
#include "Retangulo.h"

using namespace std;

void ex1f3 () {
    
    Ponto a(2, 4), b(-4, 0);
    const Ponto c(0, 3);
    
    cout << a.getAsString() << endl;
    
    a.setX(8);
    
    cout << c.getX() << endl;
    
    cout << a.dist(c) << endl;
    cout << c.dist(a) << endl;
    cout << c.dist() << endl;
    
    cout << a.getAsString() << endl;
}

void ex3f3 () {
    Ponto a(2, 3);
    
    Retangulo r(a, 4, 12);
    
    cout << r.getAsString() << endl;
    
    cout << "Area: " << r.getArea() << endl;
}

int main() {
    ex3f3();
}