#include "Peixe.h"
#include "Aquario.h"

int Peixe::conta = 500;

Peixe::Peixe(string a, string b)
    : nome(a), cor(b), peso(10), id(conta++), aq(nullptr) {}

Peixe::Peixe (const Peixe& ref) {
    nome = ref.nome;
    cor = ref.cor;
    peso = ref.peso;
    id = conta++;
}

Peixe::~Peixe() {
    cout << "Xau Peixe " << nome << endl;
}

string Peixe::getNome() const { return nome; }
string Peixe::getCor() const { return cor; }
int Peixe::getID() const { return id; }

void Peixe::setAq(Aquario *a) { aq = a; }

string Peixe::getAsString() const {
    ostringstream os;

    os << nome << " (id: "<< id << ") (cor: " << cor << ") (peso: " << peso << "g)";

    if (aq != nullptr)
        os << " (aq: " << aq->getNome() << ")";

    return os.str();
}

ostream& operator<<(ostream& out, const Peixe& x) {
    out << x.getAsString();

    return out;
}