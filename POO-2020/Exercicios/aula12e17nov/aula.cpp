#include <iostream>
#include "Fracao.h"


void ex1af4() {
    Fracao a(1,2), b(2), c;

    c = a * b;
    //c = c * 2; // Converte o 2 para Fracao atraves do construtor. Apenas o faz porque o construtor permite fazer uma fracao apenas com um inteiro
    //c = 2 * c;
    c *= 2; // Tem de ser definido a parte pois trata-se de outro operador

    (a *= b) *= c; // o 'a' altera-se duas vezes, neste caso


    //c = operator*(a,b);

    //cout << a.getAsString() << endl;
    //cout << b.getAsString() << endl;
    //cout << c.getAsString() << endl;

    cout << a << endl << b << endl << c << endl;
}

void ex1bf4() {
    Fracao x(1,2), y(2), z(2,4);

    cout << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl;

    cout << (x == y) << " " << (x < y) << endl;
    cout << (x != y) << " " << (x > y) << endl;
    cout << (2 == y) << " " << (2 >= y) << " " <<(2 <= y) << endl;
    cout << (z == 3) << " " << (z <= 3) << endl;
}

void ex1cf4() {
    Fracao x(1,2), y(2), z(2,4);

    cout << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl;

    x++;

    cout << endl;

    cout << "x: " << x << endl << "y: " << ++++y << endl << "z: " << z++ << endl;
}

int main () {
    ex1cf4();
    return 0;
}