#include <iostream>
#include "Ponto.h"
#include "Retangulo.h"
#include "Desenho.h"

using namespace std;

void ex4f3 () {
    Desenho d("Outono");
    Ponto p1(1,2);

    d.addR(Retangulo(Ponto(1, -2), 4, 6));
    d.addR(Retangulo(Ponto(-1, 4), 4, 2));
    d.addR(Retangulo(Ponto(1, 2), 5, 30));

    d.elimina(20);

    cout << d.areaTotal() << endl;

    cout << d.getAsString() << endl;

    auto v = d.getRLocal(p1);

    cout << "Existem " << v.size() << " retangulos no ponto " << p1.getAsString() << ":" << endl;
    for(auto x : v){
        cout << x.getAsString() << endl;
    }
}

int main() {
    ex4f3();
}