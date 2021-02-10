#include "Tarifario.h"
#include "Apressado.h"
#include "Fixo.h"
#include "Cliente.h"

int main(int argc, char** argv)
{
    Cliente* c1 = new Cliente("Ana Silva", 123, new Apressado);
    Cliente* c2 = new Cliente("Joao Pires", 456, new Apressado);
    Cliente* c3 = new Cliente("Francisco Pereira", 654, new Fixo);

    c1->iniciaTreino(100);
    c1->iniciaTreino(145);
    c1->terminaTreino(150);

    c1->iniciaTreino(180);
    c1->terminaTreino(190);


    std::cout << "C1 paga: " << c1->paga() << std::endl;
    std::cout << "C3 paga: " << c3->paga() << std::endl;

    c1->iniciaTreino(180);

    c2->iniciaTreino(185);

    c1->terminaTreino(190);

    c2->terminaTreino(190);

    c3->iniciaTreino(100);
    c3->terminaTreino(600);

    Cliente* c4 = new Cliente(*c1);

    c4->iniciaTreino(10);
    c4->terminaTreino(15);

    std::cout << *c1 << std::endl;
    std::cout << "C1 paga: " << c1->paga() << std::endl;

    std::cout << "C2 paga: " << c2->paga() << std::endl;
    std::cout << "C3 paga: " << c3->paga() << std::endl;

    std::cout << *c4 << std::endl;
    std::cout << "C4 paga: " << c4->paga() << std::endl;

    delete c1;
    delete c2;
    delete c3;
    delete c4;
    return 0;
}

