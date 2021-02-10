#include <iostream>
#include "Movimento.h"

int main(int argc, char** argv) {

    Movimentos p1("Artur", 100);        // Cria objeto com nome e saldo inicial
    Movimentos p2("Ana", 200);
    
    p1 = p1 + 20;                       // Depósito de 20 Euros
    
    p1 = p1 + 30 - 80;                  // Depósito de 30 euros e levantamento de 80 
    
    p2 += 50;                          // Depósito de 50 euros
    
    p2 - 20;                            // Deve compilar, mas não altera o objeto

    cout << "Iguais: " << (p1 == p2) << endl;       // São iguais se tiverem o mesmo saldo
    
    cout << p1 << endl;                 // Apresenta informação completa sobre o objeto: Nome, Saldo e Movimentos
    
    cout << p2 << endl;
       
    return 0;
}