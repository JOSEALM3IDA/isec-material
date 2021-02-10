#include "imperio.h"

bool Imperio::canAdd(int q, int tipo) {
    int maxRecursos = hasTec("Banco Central") ? 5 : 3;
    int maxForca = hasTec("Drones Militares") ? 5 : 3;

    switch (tipo) {
        case 0: // ouro
            return q + cofre > maxRecursos ? false : true;
        case 1: // prod
            return q + armazem > maxRecursos ? false : true;
        case 2: // militar
            return q + forca > maxForca ? false : true;
        default:
            return false;
    }
}

errcode Imperio::recolha() {
    errcode err1 = addOuro(getProdOuroTotal());
    errcode err2 = addProd(getProdProdTotal());

    if (err1 == IMP_TOO_MUCH_OURO && err2 == IMP_TOO_MUCH_PROD) {
        return IMP_TOO_MANY_RESOURCES;
    } else if (err1 == IMP_TOO_MUCH_OURO) {
        return IMP_TOO_MUCH_OURO;
    } else if (err2 == IMP_TOO_MUCH_PROD) {
        return IMP_TOO_MUCH_PROD;
    } else if (err1 == OK && err2 == OK) {
        return OK;
    } else {
        return UNEXPECTED;
    }
}

errcode Imperio::addOuro(int q) {
    if (!canAdd(q, 0)) {
        cofre = hasTec("Banco Central") ? 5 : 3;
        return IMP_TOO_MUCH_OURO;
    } else {
        cofre += q;
        return OK;
    }
}

errcode Imperio::addProd(int q) {
    if (!canAdd(q, 1)) {
        armazem = hasTec("Banco Central") ? 5 : 3;
        return IMP_TOO_MUCH_PROD;
    } else {
        armazem += q;
        return OK;
    }
}

errcode Imperio::addForca(int q) {
    if (!canAdd(q, 2)) {
        forca = hasTec("Drones Militares") ? 5 : 3;
        return IMP_TOO_MUCH_FORCA;
    } else {
        forca += q;
        return OK;
    }
}

errcode Imperio::addTec(Tecnologia &newTec) {
    for (Tecnologia *t : tecnologias)
        if (t == &newTec)
            return TEC_ALREADY_BOUGHT;

    if (newTec.getCusto() > cofre)
        return IMP_NOT_ENOUGH_OURO;

    cofre -= newTec.getCusto();
    tecnologias.push_back(&newTec);
    return OK;
}

#if DEBUG
errcode Imperio::forceAddTec(Tecnologia &newTec) {
    for (Tecnologia *t : tecnologias)
        if (t == &newTec)
            return TEC_ALREADY_BOUGHT;

    tecnologias.push_back(&newTec);
    return OK;
}
#endif

bool Imperio::hasTec(string nome) const {
    for (Tecnologia *t : tecnologias)
        if (t->getNome() == nome)
            return true;

    return false;
}

errcode Imperio::troca(int tipo) {
    errcode code;
    switch (tipo) {
        case 0: // maisouro
            if (armazem < 2)
                return IMP_NOT_ENOUGH_PROD;

            if (addOuro(1) != OK)
                return IMP_CANT_TAKE_OURO;

            armazem -= 2;

            return NEXT;

        case 1: // maisprod
            if (cofre < 2)
                return IMP_NOT_ENOUGH_OURO;

            if (addProd(1) != OK)
                return IMP_CANT_TAKE_PROD;
            
            cofre -= 2;

            return NEXT;

        case 2: // maismilitar
            if (cofre < 1)
                return IMP_NOT_ENOUGH_OURO;

            if (armazem < 1)
                return IMP_NOT_ENOUGH_PROD;

            if (addForca(1) != OK)
                return IMP_CANT_TAKE_FORCA;

            armazem -= 1;
            cofre -= 1;

            return OK;

        default:
            return UNEXPECTED;
    }
}

errcode Imperio::addTerr(Territorio *tn) {
    for (Territorio *t : territorios) {
        if (t == tn)
            return TERR_ALREADY_CONQUERED;
    }

    tn->setConquistado(true);
    territorios.push_back(tn);
    
    return OK;
}

errcode Imperio::rmTerr(string nome) {
    for (auto it = territorios.begin(); it != territorios.end(); it++)
        if ((*it)->getNome() == nome) {
            (*it)->setConquistado(false);
            territorios.erase(it);
            return OK;
        }

    return TERR_NOT_FOUND;
}

void Imperio::rmTerr(Territorio *t) {
    for (auto it = territorios.begin(); it != territorios.end(); it++)
        if ((*it) == t) {
            (*it)->setConquistado(false);
            territorios.erase(it);
            return;
        }   
}

string Imperio::getTerritorios() const {
    ostringstream os;

    for (Territorio *t : territorios)
        os << endl << (*t) ;

    return os.str();
}

string Imperio::getNomeTecnologias() const {
    ostringstream os;

    for (Tecnologia *t : tecnologias) {
        os << t->getNome() << "     ";
    }

    return os.str();
}

int Imperio::getProdOuroTotal() const {
    int rtn = 0;
    for (Territorio *t : territorios)
        rtn += t->getOuro();

    return rtn;
}

int Imperio::getProdProdTotal() const {
    int rtn = 0;
    for (Territorio *t : territorios)
        rtn += t->getProd();

    return rtn;
}

int Imperio::getSomaPontosTerr() const {
    int rtn = 0;

    for (Territorio *t : territorios)
        rtn += t->getPontos();

    return rtn;
}

string Imperio::getAsString() const {
    ostringstream os;

    int maxRecursos = hasTec("Banco Central") ? 5 : 3;
    int maxForca = hasTec("Drones Militares") ? 5 : 3;
    os << "Forca: " << forca << '/' << maxForca << "   |   Cofre: " << cofre << '/' << maxRecursos << " (+" << getProdOuroTotal() << ")   |   Armazem: " << armazem << '/' << maxRecursos << " (+" << getProdProdTotal() << ')' << endl;

    if (tecnologias.size() > 0)
       os << "Tecnologias Adquiridas: " << getNomeTecnologias() << endl;
       
    os << "Territorios: " << territorios.size() << getTerritorios();

    return os.str();
}

ostream& operator<<(ostream& out, const Imperio& a) {
    out << a.getAsString();

    return out;
}