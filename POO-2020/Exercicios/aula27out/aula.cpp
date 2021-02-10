#include <iostream>

#include "TV.h"

using namespace std;

void ex9f2() {
    /*
    vector<int> v = {10, 45, 43, -3, 67};

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    
    cout << endl;

    v.pop_back();

    v.push_back(100);
    v.push_back(12);

    vector<int>::iterator it;

    for(it = v.begin(); it < v.end(); it++)
        cout << *it << " ";
    
    cout << endl;
    */

   TV a({"RTP", "RTP2", "SIC", "TVI"});

    a.turnOn();
    
    a.maisVol();
    
    a.changeCanal(3);
    
    cout << a.getTodosCanais() << endl;
    
    cout << a.getAsString() << endl;
    
    a.turnOff();
}

int main() {
    ex9f2();

    return 1;
}