#include <iostream>

#include "Peixe.h"
#include "Aquario.h"

using namespace std;

int main() {    
    Peixe *p1 = new Peixe("Nemo", "Amarelo");
    Peixe *p2 = new Peixe("Shark");
    
    cout << *p1 << endl;
    cout << *p2 << endl;
    
    Aquario a("Oceano");
    
    a.addPeixe(p1);
    a.addPeixe(p2);

    Aquario b(a, "Mar");
    
    cout << a << endl;
    cout << b << endl;


    
    return 0;
}

