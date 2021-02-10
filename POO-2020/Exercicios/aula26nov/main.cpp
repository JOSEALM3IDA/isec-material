#include <iostream>
#include "Agenda.h"

int main() {
    Agenda a;
    
    a.addContacto("Ana", 123123123);
    a.addContacto("Pedro", 333444555);
    
    cout << a << endl;
    
    string s = "Pedro";
    
    cout << "O telefone do/a " << s << " e: " << a.getTel(s) << endl;

    Agenda b = a;
    Agenda c(b);
   
    a.atualizaContacto("Pedro", 999999999);
    
    a.eliminaContacto(123123123);
    
    a.addContacto("Luis", 12);

    b.addContacto("Jose", 12345);

    cout << "Agenda A:" << endl << a << endl << "Agenda B:" << endl << b << endl << "Agenda C:" << endl << c << endl;

    return 0;
}

