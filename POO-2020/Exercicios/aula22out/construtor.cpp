
#include <iostream>
#include <sstream>

using namespace std;

class MSG{
    char letra;
    int num;
    
    static int contador; 
public:
    
    MSG(char c='x'):letra(c),num(contador++){
        cout << "Construtor " << letra << " " << num << endl;}
    
    
    MSG(const MSG& ref):letra(ref.letra),num(contador++){
        cout << "CPC " << letra << " " << num << endl;}
    
   
    
    ~MSG(){ 
        cout << "Destrutor " << letra << " " << num << endl; }
    
    string getAsString() const{
        ostringstream os;
        
        os << "Letra: " << letra << " Num:" << num;
        return os.str();       
    }      
};

int MSG::contador = 1;

void testeG(){
    MSG a('p');
    
}

void testeH(MSG v){
    
}

void testeL(MSG &a){
    cout << a.getAsString() << endl;
}

MSG testeM(){
    MSG x('p');
    
    return x;
}

MSG& testeN(MSG& a){
    
    return a;
}


int mainA(){   
    MSG a;
    MSG b('r');
    
    a = testeN(b);
    return 0;
}



void f1(MSG* r1, MSG& r2){
    MSG x;
    
    *r1 = x;
}

void f2(MSG p){
    MSG &r = p;  
}

MSG& f3(MSG* r){  
    return *r;
}

int main(){
    MSG a('a');
    MSG b('b');
    MSG c(a);
    
    f1(&a, b); 
    f2(c); 
    f3(&a) = b; 
    return 0;
}





