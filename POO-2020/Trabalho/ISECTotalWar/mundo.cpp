#include "mundo.h"

Mundo::Mundo() {
    srand(time(NULL));
    cria("territorio_inicial", 1);
    imp.addTerr(territorios[0]);
}

Mundo::Mundo(const Mundo& ref) {
    imp = ref.imp;
    turno = ref.turno;
    eventos = ref.eventos;
    tecnologias = ref.tecnologias;

    for (int i = 0; i < ref.territorios.size(); i++) {
        territorios.push_back(ref.territorios[i]->clone());
        if (territorios[i]->isConquistado() == true) {
            imp.rmTerr(ref.territorios[i]);
            imp.addTerr(territorios[i]);
        }
    }
}

Mundo::~Mundo() {
    for (Territorio *t : territorios)
        delete t;
}

void Mundo::fimJogo() {
    ostringstream os;
    
    if (imp.getNTerr() == 0)
        os << "O Imperio ficou sem territorios. Consequentemente, perdeu tudo. Assim, acaba o jogo com 0 pontos.";
    else {
        int pontuacao = imp.getSomaPontosTerr() + imp.getSomaPontosTec();
        os << "O jogo terminou.\n\nPontos de vitoria (por territorios): +" << imp.getSomaPontosTerr() << " pontos" << "\nPontuacao por tecnologias: +" << imp.getSomaPontosTec() << " pontos";
        if (imp.getNTec() >= 5) {
            os << "\nBonus Cientifico: +1 ponto";
            pontuacao += 1;
        }
            
        if (getNTerritorios() == imp.getNTerr()) {
            os << "\nImperador Supremo: +3 pontos";
            pontuacao += 3;
        }
            
        os << "\n\nPontuacao total final: " << pontuacao;
    }

    infoFimJogo(os.str());
}

string Mundo::recAbandonado() {
    ostringstream rtn;

    rtn << "EVENTO: Recurso Abandonado" << endl << "Um recurso abandonado foi encontrado e fornece ao imperio uma unidade de ";

    if (turno <= 6) { // Primeiro ano
        rtn << "produtos";
        errcode code = imp.addProd(1);
        if (code == IMP_TOO_MUCH_PROD) {
            string s = codeToString[IMP_CANT_TAKE_PROD];
            s[0] = tolower(s[0]);
            rtn << ", mas foi desperdicada pois " << s << '.';
        } else if (code == OK) {
            rtn << '.';
        }
    } else {
        rtn << "ouro";
        errcode code = imp.addOuro(1);
        if (code == IMP_TOO_MUCH_OURO) {
            string s = codeToString[IMP_CANT_TAKE_OURO];
            s[0] = tolower(s[0]);
            rtn << ", mas foi desperdicada pois " << s << '.';
        } else if (code == OK) {
            rtn << '.';
        }
    }

    return rtn.str();
}

string Mundo::invasao() {
    ostringstream rtn;

    rtn << "EVENTO: Invasao" << endl << "Um imperio estrangeiro, com forca militar de valor ";

    int forca;
    if (turno <= 6)
        forca = 2;
    else
        forca = 3;

    rtn << forca << ", esta a tentou conquistar o territorio ";

    Territorio* terr = imp.getLastConquistado();

    int res = terr->getRes();
    rtn << terr->getNome() << ", cuja resistencia tem o valor de " << res;
    
    if (imp.hasTec("Defesas Territoriais")) {
        rtn << " + 1 (devido as Defesas Territoriais)";
        res++;
    }

    int sorte = rand() % 6 + 1;
    rtn << ". Na batalha, o imperio estrangeiro obteve um fator sorte de " << sorte << ", atacando com uma forca total de " << sorte + forca << ". ";

    if (sorte + forca < res) {
        rtn << "Como a resistencia do territorio superou a forca do ataque, a invasao falhou.";
    } else {
        imp.rmTerr(terr->getNome());
        rtn << "Como a forca do ataque superou a resistencia do territorio, a invasao teve sucesso e o seu imperio perdeu o territorio.";
    }

    return rtn.str();
}

string Mundo::aliDiplomatica() {
    ostringstream rtn;
    
    rtn << "EVENTO: Alianca Diplomatica" << endl << "Foi assinada uma alianca com um imperio estrangeiro. Em consequencia, recebeu uma unidade militar";

    errcode code = imp.addForca(1);
    if (code == IMP_TOO_MUCH_FORCA) {
        string s = codeToString[IMP_CANT_TAKE_FORCA];
        s[0] = tolower(s[0]);
        rtn << ", mas foi desperdicada pois " << s << '.';
    } else if (code == OK) {
        rtn << '.';
    }
    
    return rtn.str();
}

#if DEBUG
errcode Mundo::giveTec(string n) {
    for (int i = 0; i < tecnologias.size(); i++)
        if (tecnologias[i].getNome() == n)
            return imp.forceAddTec(tecnologias[i]);

    return TEC_DOESNT_EXIST;
}

errcode Mundo::giveTerr(string n) {
    for (Territorio *t : territorios)
        if (t->getNome() == n)
            return imp.addTerr(t);

    return TERR_NOT_FOUND;
}


errcode Mundo::escolheEvento(string& descr, string nome) {
    if (nome == "")
        return realizaEvento(descr);
    else
        for (int i = 0; i < eventos.size(); i++)
            if (eventos[i] == nome)
                return realizaEvento(descr, i);

    return EVNT_NOT_FOUND;
}

errcode Mundo::realizaEvento(string& s, int e) {
    int rnd;
    if (e == -1)
        rnd = rand() % 4;
    else
        rnd = e;
#else
errcode Mundo::realizaEvento(string& s) {
    int rnd = rand() % 4;
#endif
    switch (rnd) {
        case 0: // Sem evento
            s = "Nada de especial aconteceu. Todos podem dormir descansados.";
            break;

        case 1: // Recurso Abandonado
            s = recAbandonado();
            break;

        case 2: // Invasao
            s = invasao();
            
            if (imp.getNTerr() == 0) {
                fimJogo();
                return FIM_JOGO;
            }
            
            break;

        case 3: // Alianca Diplomatica
            s = aliDiplomatica();
            break;

        default:
            return UNEXPECTED;
    }

    return OK;
}

errcode Mundo::proxTurno() {
    turno++;
    
    if (turno >= 13) {
        fimJogo();
        return FIM_JOGO;
    }   

    for (Territorio *t : territorios)
        t->atualizar(turno);
    
    return OK;
}

string Mundo::infoFimJogo(string s) {
    static string info = "";

    if (info == "") {
        info = s;
        return "";
    } else
        return info;
}

errcode Mundo::conquista(string terrName, int& sorte) {
    for (Territorio *t : territorios)
        if (t->getNome() == terrName) {
            if (t->getPontos() == 3 && !imp.hasTec("Misseis Teleguiados"))
                return IMP_NO_REQUIRED_TEC;
                
            sorte = rand() % 6 + 1;
            if (t->getRes() <= imp.getForca() + sorte) {
                imp.addTerr(t);
                return OK;
            } else if (t->getRes() <= imp.getForca() + 6) {
                imp.perderForca();
                return IMP_NOT_ENOUGH_LUCK;
            } else {
                imp.perderForca();
                return IMP_NOT_ENOUGH_POWER;
            }
        }

    return TERR_NOT_FOUND;
}

errcode Mundo::cria(string tipo, int n) {
    if (n == 0)
        return CMD_NO_NEW_TERRITORIES;
    
    for (int i = 0; i < n; i++)
        if (tipo == "castelo")
            territorios.push_back(new Castelo());
        else if (tipo == "duna")
            territorios.push_back(new Duna());
        else if (tipo == "fortaleza")
            territorios.push_back(new Fortaleza());
        else if (tipo == "mina")
            territorios.push_back(new Mina());
        else if (tipo == "montanha")
            territorios.push_back(new Montanha());
        else if (tipo == "pescaria")
            territorios.push_back(new Pescaria());
        else if (tipo == "planicie")
            territorios.push_back(new Planicie());
        else if (tipo == "refugio")
            territorios.push_back(new Refugio());
        else if (tipo == "territorio_inicial")
            territorios.push_back(new Terr_Inicial());
        else
            return TERR_TYPE_UNKNOWN;
    
    return OK;
}

errcode Mundo::adquire(string tec) {
    for (int i = 0; i < tecnologias.size(); i++)
        if (tecnologias[i].getNome() == tec)
            return imp.addTec(tecnologias[i]);

    return TEC_DOESNT_EXIST;
}

string Mundo::getTerrInfo(string terrName) const {
    for (Territorio *t : territorios)
        if (terrName == t->getNome())
            return t->getAsString();
    return codeToString[TERR_NOT_FOUND];
}

string Mundo::getFreeTerritorios() const {
    ostringstream os;

    for (Territorio *t : territorios) {
        if (t->isConquistado() == false)
            os << endl << (*t);
    }

    return os.str();
}

string Mundo::getAvailableTec() const {
    ostringstream os;

    for (int i = 0; i < tecnologias.size(); i++)
        if (!imp.hasTec(tecnologias[i].getNome()))
            os << endl << tecnologias[i] << endl;

    return os.str();
}

string Mundo::getAsString() const {
    ostringstream os;
    os << "Territorios nao conquistados: " << territorios.size() - imp.getNTerr() << getFreeTerritorios() << endl << "\nImperio: " << endl << imp;
    return os.str();
}

Mundo& Mundo::operator=(const Mundo& dir) {
    if (this == &dir) return *this;         // Self assignment

    for (int i = 0; i < territorios.size(); i++)
        delete territorios[i];

    territorios.clear();

    imp = dir.imp;
    turno = dir.turno;
    eventos = dir.eventos;
    tecnologias = dir.tecnologias;

    for (int i = 0; i < dir.territorios.size(); i++) {
        territorios.push_back(dir.territorios[i]->clone());
        if (territorios[i]->isConquistado() == true) {
            imp.rmTerr(dir.territorios[i]);
            imp.addTerr(territorios[i]);
        }
    }

    return *this;
}

ostream& operator<<(ostream& out, const Mundo& a) {
    out << a.getAsString();

    return out;
}