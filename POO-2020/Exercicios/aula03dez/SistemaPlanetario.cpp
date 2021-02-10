#include "SistemaPlanetario.h"

SistemaPlanetario::SistemaPlanetario(const SistemaPlanetario& ref) {
    for (Planeta *p : ref.planetas)
        addPlaneta(new Planeta(*p));
}

SistemaPlanetario::~SistemaPlanetario() {
    for (Planeta *p : planetas)
        delete p;

    cout << "D Planetario" << endl;
}

bool SistemaPlanetario::existePlaneta(string pn) const {
    for (Planeta *p : planetas)
        if (p->getNome() == pn)
            return true;

    return false;
}

bool SistemaPlanetario::addPlaneta(Planeta* p) {
    if (!existePlaneta(p->getNome())) {
        planetas.push_back(p);
        return true;
    }
        
    return false;
}

bool SistemaPlanetario::addAlien(Alien* a, string pn) {
    if (existePlaneta(pn))
        for (Planeta *p : planetas)
            if (p->getNome() == pn) {
                p->addAlien(a);
                return true;
            }

    return false;
}

bool SistemaPlanetario::mover(string na, string no, string nd) {
    if(existePlaneta(no) && existePlaneta(nd))
        for (Planeta *po : planetas)
            if (po->getNome() == no)
                if (po->existeAlien(na))
                    for (Planeta *pd : planetas)
                        if (pd->getNome() == nd) {
                            po->rmAlien(na);
                            pd->addAlien(new Alien{na});
                            return true;
                        }

    return false;
}

string SistemaPlanetario::getAsString() const {
    ostringstream os;

    for (Planeta *p : planetas)
        os << *p << endl;

    return os.str();
}

ostream& operator<<(ostream& out, const SistemaPlanetario& x) {
    out << x.getAsString();

    return out;
}