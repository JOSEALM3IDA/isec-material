#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Empregado {
    string nome;

public:
    Empregado(const string& n) : nome(n) {}

    virtual ~Empregado() {}

    string getNome() const { return nome; }

    virtual string getAsString() const = 0;

    virtual Empregado* clone() = 0;

};

class Doutor : public Empregado {

public: 
    Doutor(const string& n) : Empregado(n) {}

    virtual string getAsString() const {
        ostringstream os;
        os << "Doutor " << Empregado::getNome();
        return os.str();
    }

    virtual Doutor* clone() { return new Doutor(*this); }
};

class Engenheiro : public Empregado {
    string nome;

public: 
    Engenheiro(const string & n) : Empregado(n) {}

    virtual string getAsString() const {
        ostringstream os;
        os << "Engenheiro " << Empregado::getNome();
        return os.str();
    }

    virtual Engenheiro* clone() { return new Engenheiro(*this); }
};

class Empresa {
    vector<Empregado*> empregados;

public:
    Empresa() {
        empregados.push_back(new Doutor("D1"));
        empregados.push_back(new Doutor("D2"));
        empregados.push_back(new Engenheiro("E1"));
        empregados.push_back(new Engenheiro("E2"));
    }

    Empresa(const Empresa& e2) {
        for (Empregado* e : e2.empregados)
            empregados.push_back(e->clone());
    }

    ~Empresa() {
        for (Empregado* e : empregados)
            delete e;
    }

    void cumprimentar() {
        for (Empregado* e : empregados)
            cout << "Bom dia " << e->getAsString() << endl;
    }

    //void removeDoutor(string nome) { // remove o doutor com esse nome do seu vector
    //}
    //void removeEngenheiro(string nome) { // remove o engenheiro com esse nome do seu vector
    //}

    Empresa& operator=(const Empresa& e2) {
        if (this == &e2) return *this;       // Self assignment

        for (Empregado* e : empregados)
            delete e;

        empregados.clear();

        for (Empregado* e : e2.empregados)
            empregados.push_back(e->clone());
    }
};

int main() {
    Empresa empresa;
    empresa.cumprimentar();

    Empresa e2 = empresa;
    Empresa e3(e2);
    e2.cumprimentar();
    e3.cumprimentar();
}