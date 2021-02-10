
#ifndef ABC_H
#define ABC_H

#include <iostream>
#include <cstring>

using namespace std;

class ABC {
    char *p;  
public:
    
    ABC(char *s){
        p = new char[strlen(s)+1];
        strcpy(p, s);
        cout << "Construtor " << p << endl;
    }
    
    ABC(const ABC& ref){
        p = new char[strlen(ref.p)+1];
        strcpy(p, ref.p);
    }
    
    ~ABC(){
        delete [] p;
        cout << "Destrutor " << p << endl;
    }
    
    ABC& operator=(const ABC& dir){
    
        if(this == &dir) return *this;      // Prevenir Self-assignment 
        
        delete [] p;
        p = new char[strlen(dir.p)+1];
        strcpy(p, dir.p);
        return *this;
    }
    
    const char* getFrase() const{return p;}   
};

#endif /* ABC_H */

