#include <iostream>
#include <ctime>

#include "Cartao.h"
#include "Tarifario.h"
#include "Tagarela.h"
#include "FalaPouco.h"
#include "Rede.h"

using namespace std;

int main() {
    srand(time(NULL));

    Rede tmn({new Tagarela, new FalaPouco});

    tmn.addC(new Cartao(123456, 20.0, nullptr), 0);
    tmn.addC(new Cartao(444, 50.0, nullptr), 0);

    cout << tmn << endl;

    cout << tmn.getSaldo(123456) << endl;

    if (tmn.autoriza(123456))
        tmn.regista(123456, 401);

    cout << tmn.getSaldo(123456) << endl;

    return 0;
}



