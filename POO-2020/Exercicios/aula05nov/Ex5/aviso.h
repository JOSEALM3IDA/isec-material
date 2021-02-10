#ifndef AVISO_H
#define AVISO_H

#include "Prego.h"

class Aviso {
    string txt;
    const Prego* ref;
    
public:
    Aviso(string a, Prego& b):txt(a),ref(&b){}
    
    string getAsString() const{
        ostringstream os;
        
        os << txt << " no local " << ref->getAsString();
        return os.str();
    }
    
    void mudaDePrego(Prego& p){
        ref=&p;
    }   
};

#endif /* AVISO_H */