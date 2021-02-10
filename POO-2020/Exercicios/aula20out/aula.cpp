#include <iostream>
#include <string>

#include "Caderno.h"

using namespace std;

void ex4f2() {
    Caderno c("Note", "Verde", 80, 40, 20, "ISEC");

    c.setLocal("Casa");

    cout << c.getLocal() << endl;

    c.abrir();

    c.escrever("Ola Mundo!");

    c.setLocal("Cafe");

    c.fechar();

    cout << c.getPaginas() << endl;

    c.escrever("Mais uma frase");

    cout << c.obtemTexto() << endl;

    cout << c.getTotalPalavras() << endl;

    cout << c.getAsString() << endl;

}

int main() {

    ex4f2();

    return 0;
}