#include <iostream>
#include <string>
#include <sstream>

class Facto {
    const std::string coisa;
    const std::string propriedade;
    int grau;

public:
    Facto(std::string c, std::string p, int g = 50) : coisa(c), propriedade(p), grau(g >= 0 && g <= 100 ? g : 50) {}
    
    void setGrau(int g) { grau = (g >= 0 && g <= 100 ? g : grau); }

    std::string getCoisa() const { return coisa; }
    std::string getPropriedade() const { return propriedade; }

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

int main() {
    Facto facto1("hoje", "chove", 30);
    Facto facto2("hoje", "chove", 60);

    std::cout << facto1.getAsString() << std::endl;
    std::cin >> facto1 >> facto2;
    facto1 += facto2;
    std::cout << "F1:\t" << facto1.getAsString() << std::endl;
    std::cout << "F2:\t" << facto2.getAsString() << std::endl;
}