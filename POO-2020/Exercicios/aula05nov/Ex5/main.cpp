#include "Prego.h"
#include "Aviso.h"

int main() {
    
    Prego a(2, 7);   
    Prego b(5, 8);
    
    Aviso a1("PISO MOLHADO", a);
    Aviso a2("FECHADO", a);
    
    cout << a1.getAsString() << endl;
     
    a1.mudaDePrego(b);
    
    cout << a1.getAsString() << endl;
    
    //cout << a.getAsString() << endl;
    //cout << b.getAsString() << endl;
      
    a.mudaLocal(6, 9);
    
    cout << a1.getAsString() << endl; 
    
    //cout << a.getAsString() << endl;
    
    return 0;
}