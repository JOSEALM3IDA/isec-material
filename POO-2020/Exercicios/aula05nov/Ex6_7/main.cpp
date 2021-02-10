#include <iostream>
#include "pessoa.h"
#include "conta.h"

int main(){
    Pessoa p1("Ana Silva", 123456, 111222333);
    Pessoa p2("Bruno Pato", 567890, 444555666);
    
    //cout << p1.getAsString() << endl;    
    //cout << p2.getAsString() << endl;
    
    Conta c1(&p1);       // Conta c1 com saldo 0 e titular Ana Silva
    Conta c2(&p1);       // Conta c2 com saldo 0 e titular Ana Silva
    
    c2.variarSaldo(50);     // Variação de saldo
    c2.variarSaldo(-35);    // Variação de saldo
    
    cout << c2.getAsString() << endl;       // Mostra nome do titular e saldo

    c2.trocarTitular(&p2);

    cout << c2.getAsString() << endl; 
   
    const Pessoa *p = c1.getTitular();        // Obter ponteiro constante para titular da conta
    
    cout << p->getNome() << endl;
    
    return 0;
}