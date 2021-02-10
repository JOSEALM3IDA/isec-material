#ifndef PREGO_H
#define PREGO_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Prego{
    int x, y;
    
public:
    Prego(int a, int b):x(a), y(b){
        cout << "C - Prego: " << x << ", " << y << endl;
    }
    
    ~Prego(){
        cout << "D - Prego: " << x << ", " << y << endl;
    }
    
    string getAsString() const{
        ostringstream os;
        
        os << "(" << x << ", " << y << ")";
        return os.str();      
    }
    
    void mudaLocal(int nx, int ny){
        x = nx;
        y = ny;
    }
};

#endif /* PREGO_H */