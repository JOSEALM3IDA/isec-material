#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <sstream>

using namespace std;

class Bilhete {
    string passageiro;
    int passaporte;
    string& companhia;
    vector<int> id_malas;

public:
    Bilhete(string p, int pa, string& comp, initializer_list<int> idm) : passageiro(p), passaporte(pa), companhia(comp), id_malas(idm) {}

    string getAsString() const {
        ostringstream os;

        os << "Nome: " << passageiro << "\tPassaporte: " << passaporte;
        os << "\tCompanhia: " << companhia << std::endl << "Malas: ";

        for (int id : id_malas) {
            os << id << ' ';
        }

        return os.str();
    }

    Bilhete& operator<<(int mala) {
        for (int id : id_malas)
            if (id == mala)
                return *this;

        id_malas.push_back(mala);
        return *this;
    }

    Bilhete& operator-=(int max) {
        for (auto it = id_malas.begin(); it != id_malas.end(); ) {
            if ((*it) >= max)
                it = id_malas.erase(it);
            else
                (it)++;
        }

        return *this;
    }
};

ostream& operator<<(ostream& out, const Bilhete b) {
    out << b.getAsString();
    return out;
}

int main() {
    string s = "TAP";
    string ss = "RyanBruh";
    Bilhete bilhete1("Angelo", 12345, s, {1, 3, 36, 22});
    Bilhete bilhete2("Ruiben", 1333, ss, {2, 4, 37, 44});

    cout << "\nPassageiro 1: " << bilhete1 << "\nPassageiro 2: " << bilhete2 << endl;

    bilhete1 << 123 << 789 << 123;

    cout << "\nPassageiro 1: " << bilhete1 << "\nPassageiro 2: " << bilhete2 << endl;

    (bilhete2 -= 40) -= 35;

    cout << "\nPassageiro 1: " << bilhete1 << "\nPassageiro 2: " << bilhete2 << endl;

    return 0;
}