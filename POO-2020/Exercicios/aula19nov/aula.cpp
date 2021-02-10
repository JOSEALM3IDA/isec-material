
#include <iostream>
#include <string>
#include "ABC.h"

using namespace std;

int main(){
    
    ABC a((char *)"AAAAAAAA");
    ABC *b = new ABC((char *)"BBBBBB");
    ABC c((char *)"CCCC");
  
    a = *b;
    
    c = c;
    
    delete b;
    
    return 0;
}




void f(ABC x){
    cout << "F: " << x.getFrase() << endl;
}

int main1(){   
    ABC *p = new ABC((char *)"Ola mundo!");  
    ABC b((char *)"Fim do Mundo");
    
    f(b);
    
    cout << p->getFrase() << endl;   
    cout << b.getFrase() << endl; 
    
    delete p;   
    return 0;
}
