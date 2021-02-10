#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <initializer_list>

///////////////////////////////////////////////////////////
class Facto {
    const std::string coisa;
    const std::string propriedade;
    int grau;

public:
    Facto(std::string c, std::string p, int g = 50) : coisa(c), propriedade(p), grau(g >= 0 && g <= 100 ? g : 50) {}
    
    void setGrau(int g) { grau = (g >= 0 && g <= 100 ? g : grau); }

    std::string getCoisa() const { return coisa; }
    std::string getPropriedade() const { return propriedade; }
    int getGrau() const { return grau; }

    std::string getAsString() const {
        std::ostringstream os;

        os << "Coisa: " << coisa << "\tPropriedade: " << propriedade << "\tGrau: " << grau;

        return os.str();
    }

    Facto& operator+=(const Facto& f2);
    Facto& operator++() { grau++; return *this; }

};

bool operator==(const Facto f1, const Facto f2) { return (f1.getCoisa() == f2.getCoisa() && f1.getPropriedade() == f2.getPropriedade() ? true : false); }

std::istream& operator>>(std::istream& is, Facto& f1) {
    int c;
    is >> c;
    f1.setGrau(c);
    return is;
}

Facto& Facto::operator+=(const Facto& f2) { if (f2 == *this) grau = (grau + f2.grau) / 2; return (*this); }
///////////////////////////////////////////////////////////


class Indiv {
    std::string nome;
    int BI;
    int ano;

    int tam;
    Facto** factos;

public:
    Indiv(std::string n, int b, int an, std::initializer_list<Facto> fcs) : nome(n), BI(b), ano(an) {
        tam = fcs.size();
        factos = new Facto*[tam];

        int i = 0;
        for (Facto f : fcs)
            factos[i++] = new Facto(f.getCoisa(), f.getPropriedade(), f.getGrau());
    }

    Facto* getFacto(std::string coisa, std::string prop) const {
        for (int i = 0; i < tam; i++)
            if (factos[i]->getCoisa() == coisa && factos[i]->getPropriedade() == prop)
                return factos[i];

        return nullptr;
    }

    float getMedia() const {
        float media = 0;
        for (int i = 0; i < tam; i++)
            media += factos[i]->getGrau();

        return media/tam;
    }

    void addFacto(Facto f) {
        Facto* p;
        if ( (p = getFacto(f.getCoisa(), f.getPropriedade())) == nullptr) {
            Facto* novof = new Facto(f.getCoisa(), f.getPropriedade(), f.getGrau());
            Facto** fcs = new Facto*[tam + 1];

            for (int i = 0; i < tam; i++)
                fcs[i] = factos[i];

            delete [] factos;

            factos = fcs;
            factos[tam++] = novof;
        } else
            *(p) += f;
    }

    std::string getAsString() const {
        std::ostringstream os;

        os << "Nome: " << nome << "\tBI: " << BI << "\tAno nascimento: " << ano << std::endl;

        for (int i = 0; i < tam; i++)
            os << factos[i]->getAsString() << std::endl;

        return os.str();
    }
};

int main() {
    Indiv brn("Bruno", 30533126, 1972, { Facto("hoje", "chuva", 100), Facto("amanha", "beija", 0), Facto("quarta", "passa a POO", 0)});

    Facto* f = brn.getFacto("amanha", "beija");
    if (f != nullptr)
        std::cout << f->getAsString() << std::endl;
    else
        std::cout << "Nao existe" << std::endl;

    std::cout << "Media dos graus: " << brn.getMedia() << std::endl;

    std::cout << std::endl << brn.getAsString() << std::endl;
    brn.addFacto(Facto("quarta", "passa a POO", 60));
    std::cout << brn.getAsString() << std::endl;
}