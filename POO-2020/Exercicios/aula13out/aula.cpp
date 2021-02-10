#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void ex7f1() {
    string nome, palavra;
    istringstream is;

    cout << "Nome: ";
    getline(cin,nome);

    is.str(nome);

    // Escrever uma palavra por linha

    while (is >> palavra) { // Vai buscar apenas uma palavra (devolve True/False)
        cout << palavra << endl;
        if (palavra == "Silva")
            cout << "Olha o silva" << endl;
    }
    


/*
    for(char c : nome) {
        if (c == ' ') {
            cout << c << endl;
        }
        else {
            cout << c;
        }
    }
*/
    cout << endl;
}

int toInt(string s) {
    string n[4] = {"UM", "DOIS", "TRES", "QUATRO"};

    for (int i = 0; i < 4; i++)
        if (n[i] == s)
            return i+1;
    return -1;
}


string toStr(int d) {
    string n[4] = {"UM", "DOIS", "TRES", "QUATRO"};

    for (int i = 0; i < 4; i++)
        if (i+1 == d)
            return n[i];
    return "NULL";
}

void ex9f1 () {
    string s;
    int d, num;
    bool flag = true;

    while (flag == true) {
        cout << "Informacao (FIM para terminar): ";

        cin >> num;
        if (cin.good() == true)
            cout << toStr(num) << endl;
        else {
            cin.clear();
            cin >> s;

            if (s == "FIM")
                flag = false;
            else
                cout << toInt(s) << endl;
        }
    }

/*
    while (flag == true) {
        cout << "Numero por extenso (1 a 4) - FIM para terminar: ";
        cin >> s;

        if (s == "FIM") {
            flag = false;
        } else {
            cout << toInt(s) << endl;
        }
    }

    flag = true;

    while (flag == true) {
        cout << "Digito (1 a 4) (-1 para terminar): ";
        cin >> d;

        if (d == -1) {
            flag = false;
        } else {
            cout << toStr(d) << endl;
        }
    }
*/

}

#define TAM 15

struct Tabela {
    int tab[TAM];
};

void preenche (Tabela &t, int d) {
    for (int i = 0; i < TAM; i++) {
        t.tab[i] = d;
    }
}

void setValor (Tabela &t, int a, int b) {
    if (a < TAM && a >= 0)
        t.tab[a] = b;
}

void listar (Tabela t) {
    for (int i = 0; i < TAM; i++) {
        cout << t.tab[i] << " ";
    }

    cout << endl;
}

int getValor (Tabela t, int a) {
    if (a < TAM && a >= 0)
        return t.tab[a];

    return -1;
}

int& elementoEm(Tabela &a, int pos) {
    return a.tab[pos];
}

void ex1f2 () {
    Tabela t;

    preenche(t, 20);          // Preenche todas as posições com valor do segundo parâmetro
    setValor(t, 10, 50);      // Colocar valor do terceiro parâmetro na posição do segundo parâmetro
    listar(t);                // Mostra na consola todos os valores armazenados
   
    cout << getValor(t, 10) << endl;      // Obtém o valor armazenado na posição do segundo parâmetro

    cout << elementoEm(t, 9) << endl;

    elementoEm(t, 9) = 101;

    cout << elementoEm(t, 9) << endl;

}

int main () {
    ex1f2();

    return 0;
}