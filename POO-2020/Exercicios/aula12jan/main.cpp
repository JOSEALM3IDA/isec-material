#include "Tarifario.h"
#include "Apressado.h"
#include "Fixo.h"
#include "Cliente.h"
#include "Sociavel.h"
#include "Ginasio.h"

int main(int argc, char** argv)
{
    Ginasio g;

    g.addCliente(new Sociavel("Ana Silva", 123, new Apressado));
    g.addCliente(new Sociavel("Joao Pires", 456, new Apressado));

    g.passaTempo(10);

    g.registaEntrada(123);

    g.passaTempo(12);

    g.registaEntrada(456);

    g.passaTempo(6);

    std::cout << g << std::endl;

    g.registaSaida(123);

    std::cout << g << std::endl;

    g.passaTempo(30);

    //g.registaSaida(456);

    std::cout << g << std::endl;
    std::cout << g.pagamento(123) << std::endl;
    std::cout << g.pagamento(456) << std::endl;
    std::cout << g.pagamento(456) << std::endl;

    return 0;
}

