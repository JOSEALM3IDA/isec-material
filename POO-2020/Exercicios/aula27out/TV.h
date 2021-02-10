#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

class TV {
    static const int     VMAX = 10, VMIN = 0;
    vector<string> canais;
    bool on = false; 
    size_t canalAtual = 0;
    size_t volume = 0;
    //size_t nCanais;

    public:

    TV(initializer_list<string> list) {
        //initializer_list<string> :: iterator it;

        for (auto it = list.begin(); it < list.end(); it++) {
            canais.push_back(*it);
        }
    }

    string getCanal() const {return canais[canalAtual];}
    string getTodosCanais() const;
    string getAsString() const;

    void turnOn() {on = true;}
    void turnOff() {on = false;}
    void maisVol(size_t aumento = 1);
    void menosVol(size_t diminuicao = 1);
    void changeCanal(size_t canal) {canalAtual = canal;}

};