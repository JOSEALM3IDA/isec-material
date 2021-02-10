#include "Biblioteca.h"

Biblioteca::Biblioteca(const Biblioteca& ref)
{
    for (int i = 0; i < ref.v.size(); i++) {
        v.push_back(ref.v[i]->clone());
    }
}

Biblioteca::~Biblioteca()
{
    for (auto x : v) {
        delete x;
    }
}

bool Biblioteca::addLivro(Livro* p)
{
    for (Livro* l : v) {
        if (p == l) {
            return false;
        }
    }

    v.push_back(p);
    return true;
}

bool Biblioteca::eliminaLivro(std::string x)
{
    for (auto it = v.begin(); it < v.end(); it++) {
        if ((*it)->getISBN() == x) {
            delete *it;
            it = v.erase(it);
            return true;
        }
    }

    return false;
}


std::string Biblioteca::getAsString() const
{
    std::ostringstream os;

    for (Livro* p : v) {
        os << *p << std::endl;
    }

    return os.str();
}

Biblioteca& Biblioteca::operator=(const Biblioteca& dir)
{
    if (this == &dir) return *this;         //Self assignment

    for (int i = 0; i < v.size(); i++) {
        delete v[i];
        v.erase(v.begin() + i);
    }

    v.clear();
    
    for (int i = 0; i < dir.v.size(); i++) {
        addLivro(dir.v[i]->clone());
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Biblioteca& b)
{
    out << b.getAsString();

    return out;
}