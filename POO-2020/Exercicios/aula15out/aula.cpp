#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Tabela {
    static const int TAM = 15;

    int tab[TAM];

    public:

    Tabela(int val) { // Construtor
        for (int i = 0; i < TAM; i++) {
            tab[i] = val++;
        }
    }

    Tabela() = default;

    Tabela(int val, int inc) {
        for (int i = 0; i < TAM; i++) {
            tab[i] = val;
            val += inc;
        }
    }

    void listar() const { // const faz com que a função não possa alterar o objeto
        for (int i = 0; i < TAM; i++) {
            cout << tab[i] << " ";
        }

        cout << endl;
    }

    void preenche(int d) {
        for (int i = 0; i < TAM; i++) {
            tab[i] = d;
        }
    }

    int& elementoEm(int pos) {
        return tab[pos];
    }
    
};

void ex2f2 () {
    //Tabela t; // Quando mudo o construtor preciso de mudar (ou não)
    //Tabela t(20);
    Tabela t(20, 3);

    //t.preenche(20);          // Preenche todas as posições com valor do segundo parâmetro
    t.listar();                // Mostra na consola todos os valores armazenados

    cout << t.elementoEm(9) << endl;

    t.elementoEm(9) = 101;

    cout << t.elementoEm(9) << endl;

    t.listar();

}

// Os objetos Auto são criados indicando marca, modelo e ano. Pode ou não ser indicada a matrícula
// Depois da criação, a marca, modelo e ano não podem ser alterados

class Auto {
    const string marca;
    const string modelo;
    string matricula;
    const int ano;

    public:

    Auto(string nMarca, string nModelo, int nAno, string nMatricula = "") 
    : marca(nMarca), modelo(nModelo), ano(nAno), matricula(nMatricula) {}

    void setMat(string nMatricula) { matricula = nMatricula; }

    string getMarca() const { return marca; }

    int getAno() const { return ano; }

    string getMat() const { return matricula; }

    bool mudaMat(Auto& x) {
        if (matricula == "" || x.getMat() == "" || this == &x)
            return false;

        string temp = x.matricula;
        x.matricula = matricula;
        matricula = temp;

        return true;
    }
};

void ex6f2() {
    Auto c1("Opel", "Corsa", 2001, "AA-12-BB");
    Auto c2("Fiat", "Punto", 2000);

    cout << c1.getMarca() << endl;
    cout << c2.getAno() << endl;

    c2.setMat("XX-30-YY");

    cout << c2.getMat() << endl;

    if (c1.mudaMat(c2)) {

    }

    cout << c1.getMat() << endl;

}

int main () {
    ex6f2();

    return 0;
}