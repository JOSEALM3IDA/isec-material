#include <iostream>

#include "Peixe.h"
#include "Piranha.h"
#include "Aquario.h"

int main() {
    
    Peixe *p1 = new Peixe("Nemo", "Amarelo");
    Peixe *p2 = new Peixe("Shark");
    Peixe /*ou Piranha*/ *p3 = new Piranha("Dora", "Azul");
    
    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    
    Aquario a("Oceano");
    
    a.addPeixe(p1);
    a.addPeixe(p2);
    a.addPeixe(p3);

    a.distribuirComida(60);
    a.limparFundo();         // Eliminar os peixes mortos do aquario
    
    cout << a << endl;
    
    return 0;
}

