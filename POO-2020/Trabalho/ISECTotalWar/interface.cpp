#include "interface.h"

Interface::Interface(Mundo& m) : mnd(m) {
    cout << "\n|+ ISEC: Total War +|\n"; 
    jogo();
}

Interface::Interface(const Interface& ref) : mnd(ref.mnd) {
    proxFase = ref.proxFase;
    comandos = ref.comandos;

    for (int i = 0; i < ref.saves.size(); i++) {
        saves.push_back(new Save(*(ref.saves[i])));
    }
}

Interface::~Interface() {
    for (Save *s : saves)
        delete s;
}

string Interface::infoTurno() {
    ostringstream os;

    int turno = mnd.getTurno();
    os << "|* TURNO " << turno << " (ANO " << (turno == 0 ? 0 : turno / 7 + 1) << " TURNO " << (turno >= 7 ? turno % 7 + 1 : turno % 7) << ") *|"; 

    return os.str();
}

errcode Interface::pedirComandos() {
    int code;
    while (1) {
        cout << "\nComandos disponiveis:";
        for (Comando c : comandos)
            if (c.isDisp() == true)
                cout << ' ' << c.getNome();
        
        
        cout << "\nCMD: ";
        string input;
        getline(cin, input);

        if (input.size() < 1) {
            cout << "Comando invalido! Erro: " << codeToString[CMD_UNKNOWN] << endl;
            continue;
        }
        
        errcode code = execute(split(input, ' ')); // FIM_JOGO
        if (code == NEXT || code == AVANCA || code == ATIVA) {
            cout << "\nComando executado com sucesso!" << endl;
            return code;
        } else if (code == FIM_JOGO) {
            return FIM_JOGO;
        } else if (code != OK) {
            cout << "\nComando falhou! Razao: " << codeToString[code] << "." << endl;
        } else {
            cout << "\nComando executado com sucesso!" << endl;
            return OK;
        }

        if (code == IMP_NOT_ENOUGH_POWER || code == IMP_NOT_ENOUGH_LUCK)
            return NEXT;
    }
}

vector<string> Interface::split(const string &s, char c) {
    vector<string> result;
    stringstream ss(s);
    string item;

    bool flag;
    while (getline(ss, item, c)) {
        flag = false;
        for (char temp : item)
            if (temp != ' ')
                flag = true;

        if (flag)
            result.push_back(item);
    }

    return result;
}

void Interface::jogo() {
    errcode code;

    proxFase = -1;
    while (1) {
        switch (proxFase) {
            case -1:
                code = faseSetup();
                break;
            
            case 0:
                code = faseConquista();
                break;

            case 1:
                code = faseRecolha();
                break;
            
            case 2:
                code = faseCompra();
                break;

            case 3:
                code = faseEventos();

                if ((code = mnd.proxTurno()) == FIM_JOGO)
                    break;
                break;

            case 4:
                cout << endl << mnd.infoFimJogo() << endl;
                while ((code = pedirComandos()) == OK);
                
                if (code == AVANCA) {
                    cout << endl;
                    return;
                } else
                    break;

            default:
                cout << "ERRO GRAVE" << endl;
        }

        if (code == FIM_JOGO)
            proxFase = 4;
        else if (code != ATIVA)
            proxFase = proxFase == 3 ? 0 : proxFase + 1;
    }
}

errcode Interface::faseSetup() {
    cout << "\n-- FASE DE SETUP -- " << endl;

    changeCMDDisp("lista", true);
    changeCMDDisp("grava", true);
    changeCMDDisp("ativa", true);
    changeCMDDisp("apaga", true);
    changeCMDDisp("info", true);
    changeCMDDisp("avanca", true);

#if DEBUG
    changeCMDDisp("quit", true);
    changeCMDDisp("toma", true);
    changeCMDDisp("modifica", true);
    changeCMDDisp("fevento", true);
#endif

    changeCMDDisp("carrega", true);
    changeCMDDisp("cria", true);

    errcode code;
    while ((code = pedirComandos()) == OK);
    
    changeCMDDisp("carrega", false);
    changeCMDDisp("cria", false);

    return code;
}

errcode Interface::faseConquista() {
    
    cout << "\n\n" << infoTurno() << endl << endl << "-- FASE DE CONQUISTA -- " << endl;

    changeCMDDisp("conquista", true);
    changeCMDDisp("passa", true);

    errcode code;
    while ((code = pedirComandos()) == OK);

    changeCMDDisp("conquista", false);
    changeCMDDisp("passa", false);

    if (code == ATIVA || code == AVANCA)
        return code;

#if DEBUG
    if (code == FIM_JOGO)
        return code;
#endif

    while ((code = pedirComandos()) == OK);

    return code;
}

errcode Interface::faseRecolha() {
    cout << endl << endl << "-- FASE DE RECOLHA -- " << endl;

    int ouroAntes = mnd.getCofreImp();
    int prodAntes = mnd.getArmazemImp();
    errcode code = mnd.recolha();

    int ouroAtual = mnd.getCofreImp();
    int prodAtual = mnd.getArmazemImp();
    cout << "\nRecolhidas " << ouroAtual - ouroAntes << " unidades de ouro e " << prodAtual - prodAntes << " unidades de produtos." << endl;
    cout << "\nCofre: " << ouroAtual << "\tArmazem: " << prodAtual << endl;

    if (code != OK)
        cout << "\nINFO: " << codeToString[code] << '.' << endl;

    if (mnd.hasTecTrocaImp()) {
        changeCMDDisp("maisouro", true);
        changeCMDDisp("maisprod", true);

        cout << "\nTem a tecnologia necessaria para realizar trocas." << endl;

        errcode code;
        while ((code = pedirComandos()) == OK);
        
#if DEBUG
        if (code == FIM_JOGO)
            return code;
#endif

        changeCMDDisp("maisouro", false);
        changeCMDDisp("maisprod", false);
    } else
        cout << "\nNao tem tecnologia necessaria para realizar trocas." << endl;

    while ((code = pedirComandos()) == OK);    

    return code;
}

errcode Interface::faseCompra() {
    cout << endl << endl << "-- FASE DE COMPRA -- " << endl;

    cout << "\nTecnologias disponiveis para compra:" << endl;
    cout << mnd.getAvailableTec();

    changeCMDDisp("maismilitar", true);
    changeCMDDisp("adquire", true);

    errcode code;
    while ((code = pedirComandos()) == OK);

    changeCMDDisp("maismilitar", false);
    changeCMDDisp("adquire", false);

    return code;
}

errcode Interface::faseEventos() {
    cout << endl << endl << "-- FASE DE EVENTOS -- " << endl;

    string descr;
    
#if DEBUG
    errcode code = mnd.escolheEvento(descr);
#else
    errcode code = mnd.realizaEvento(descr);
#endif

    if (code == OK)
        cout << endl << descr << endl;
    else if (code == FIM_JOGO)
        return code;

    while ((code = pedirComandos()) == OK);

    return code;
}

errcode Interface::carrega(string fileName) {
    ifstream fp(fileName);
    if (!fp)
        return FILE_CANT_OPEN;


    changeCMDDisp("lista", false);
    changeCMDDisp("grava", false);
    changeCMDDisp("ativa", false);
    changeCMDDisp("apaga", false);
    changeCMDDisp("info", false);
    changeCMDDisp("avanca", false);

#if DEBUG
    changeCMDDisp("quit", false);
    changeCMDDisp("toma", false);
    changeCMDDisp("modifica", false);
    changeCMDDisp("fevento", false);
#endif

    int initSize = mnd.getNTerritorios();

    errcode code = FILE_BAD_FORMAT;
    bool breakFlag = true;
    string line;
    while (breakFlag && getline(fp, line)) {

        vector<string> input = split(line, ' ');

        code = execute(input);
        switch (code) {
            case OK:
                break;
            case TERR_TYPE_UNKNOWN:
            case CMD_NO_NEW_TERRITORIES:
            case CMD_NOT_AVAILABLE:
                cout << "\nLinha nao executada: '" << line << "' (" << codeToString[code] << ")" << endl;
                code = OK;
                continue;
            case CMD_INVALID_ARGS:
            case CMD_UNKNOWN:
                code = FILE_BAD_FORMAT;
                breakFlag = false;
                break;
            default:
                code = UNEXPECTED;
                breakFlag = false;
                break;
        }
    }

    int endSize = mnd.getNTerritorios();
    if (endSize == initSize)
        cout << "\nAVISO: " << codeToString[FILE_NO_NEW_TERRITORIES] << endl;
    else
        cout << "\nCriados " << endSize - initSize << " territorios!" << endl;

    changeCMDDisp("lista", true);
    changeCMDDisp("grava", true);
    changeCMDDisp("ativa", true);
    changeCMDDisp("apaga", true);
    changeCMDDisp("info", true);
    changeCMDDisp("avanca", true);

#if DEBUG
    changeCMDDisp("quit", true);
    changeCMDDisp("toma", true);
    changeCMDDisp("modifica", true);
    changeCMDDisp("fevento", true);
#endif

    return code;
}

errcode Interface::execute(vector<string> inputv) {
    int i, code;

    for (i = 0; i < comandos.size(); i++)
        if (comandos[i].getNome() == inputv[0])
            if (comandos[i].isDisp() == true)
                break;
            else
                return CMD_NOT_AVAILABLE;
    
    if (i == comandos.size())
        return CMD_UNKNOWN;

    switch (i) {
        case 0: // carrega
            if (inputv.size() != 2) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            return carrega(inputv.at(1));

        case 1: // cria
            if (inputv.size() != 3) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            for (char c : inputv[2])
                if (!isdigit(c))
                    return CMD_INVALID_ARGS;

            return mnd.cria(inputv[1], stoi(inputv[2]));

        case 2: { // conquista
            if (inputv.size() != 2) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            string terrName = inputv[1];
            int sorte, forcaMilitarAtaque = mnd.getForcaImp();
            code = mnd.conquista(terrName, sorte);
            if (code == IMP_NOT_ENOUGH_LUCK || code == IMP_NOT_ENOUGH_POWER) {
                cout << endl << mnd.getTerrInfo(terrName) << endl;
                cout << "\nForca militar ao atacar: " << forcaMilitarAtaque;
                cout << "\nSorte na batalha: " << sorte;
                cout << "\nForca de ataque total: " << forcaMilitarAtaque + sorte << endl;

                if (forcaMilitarAtaque != mnd.getForcaImp()) {
                    cout << "\nPerdeu uma unidade de forca militar." << endl;
                    cout << "Nova forca militar: " << mnd.getForcaImp() << endl;
                } else {
                    cout << "\nNao perdeu uma unidade de forca militar pois esta ja se encontra a 0." << endl;
                }
                    
                return code;
            } else if (code != OK) {
                return code;
            } else {
                cout << endl << mnd.getTerrInfo(terrName) << "\n\nTerritorio " << terrName << " conquistado, com sorte: " << sorte << endl;
                return NEXT;
            }
        }

        case 3: // passa
            if (inputv.size() != 1)  {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            return NEXT;

        case 4: // maisouro
            if (inputv.size() != 1) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            return mnd.trocaOuroImp();

        case 5: // maisprod
            if (inputv.size() != 1) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            return mnd.trocaProdImp();

        case 6: // maismilitar
            if (inputv.size() != 1) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            return mnd.trocaMilitarImp();

        case 7: { // adquire
            if (inputv.size() <= 1) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }
            
            ostringstream os;
            for (size_t i = 1; i < inputv.size(); i++) {
                os << inputv[i];
                if (i < inputv.size() - 1)
                    os << ' ';
            }

            return mnd.adquire(os.str());
        }

        case 8: // lista
            if (inputv.size() == 1) {
                cout << "\n\n" << infoTurno() << endl << "\nMundo: " << endl << mnd << endl;

                if (saves.size() > 0) {
                    cout << "\nSaves disponiveis: ";
                    for (Save *s : saves)
                        cout << s->getNome() << ' ';
                    cout << endl;
                }
                return OK;
            } else if (inputv.size() == 2) {
                string s = mnd.getTerrInfo(inputv[1]);
                if (s == codeToString[TERR_NOT_FOUND])
                    return TERR_NOT_FOUND;
                            
                cout << '\n' << s << endl;
                return OK;
            } else {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

        case 9: // avanca
            if (inputv.size() != 1)  {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            return AVANCA;

        case 10: // grava
            if (inputv.size() != 2) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            int fase;
            for (auto it = saves.begin(); it != saves.end(); it++) {
                if ((*it)->getNome() == inputv[1]) {
                    cout << "\nTem a certeza que pretende substituir o save existente? (Y/N) ";

                    string s;
                    char c;
                    while (1) {
                        getline(cin, s);
                        c = toupper(s[0]);

                        if (c != 'Y' && c != 'N')
                            cout << "Opcao invalida! Introduza uma opcao valida (Y/N): ";
                        else
                            break;
                    }
                    
                    if (c == 'Y') {
                        cout << "\nSave " << inputv[1] << " substituido." << endl;
                        delete (*it);
                        saves.erase(it);

                        if (proxFase == 3)
                            fase = 0;
                        else if (proxFase == -1)
                            fase = -1;
                        else
                            fase = proxFase + 1;

                        saves.push_back(new Save(inputv[1], mnd, fase));
                        return OK;
                    } else {
                        cout << "\nSave " << inputv[1] << " nao carregado." << endl;
                        return SAVE_USER_CANCEL;
                    }
                }
            }

            if (proxFase == 3)
                fase = 0;
            else if (proxFase == -1)
                fase = -1;
            else
                fase = proxFase + 1;

            saves.push_back(new Save(inputv[1], mnd, fase));

            return OK;

        case 11: // ativa
            if (inputv.size() != 2) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            for (auto it = saves.begin(); it != saves.end(); it++) {
                if ((*it)->getNome() == inputv[1]) {
                    cout << "\nTem a certeza que pretende substituir o mundo atual pelo mundo do save " << inputv[1] << "? Vai perder todas as mudancas atuais nao gravadas! (Y/N) ";

                    string s;
                    char c;
                    while (1) {
                        getline(cin, s);
                        c = toupper(s[0]);

                        if (c != 'Y' && c != 'N')
                            cout << "Opcao invalida! Introduza uma opcao valida (Y/N): ";
                        else
                            break;
                    }
                    
                    if (c == 'Y') {
                        cout << "\nSave " << inputv[1] << " carregado." << endl;
                        mnd = (*it)->getMundo();
                        proxFase = (*it)->getFase();
                        return ATIVA;
                    } else {
                        cout << "\nSave " << inputv[1] << " nao carregado." << endl;
                        return SAVE_USER_CANCEL;
                    }
                }
            }

            return SAVE_NOT_FOUND;

        case 12: // apaga
            if (inputv.size() != 2) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            for (auto it = saves.begin(); it != saves.end(); it++) {
                if ((*it)->getNome() == inputv[1]) {
                    cout << "\nTem a certeza que pretende apagar o save " << inputv[1] << "? (Y/N) ";

                    string s;
                    char c;
                    while (1) {
                        getline(cin, s);
                        c = toupper(s[0]);

                        if (c != 'Y' && c != 'N')
                            cout << "Opcao invalida! Introduza uma opcao valida (Y/N): ";
                        else
                            break;
                    }
                    
                    if (c == 'Y') {
                        cout << "\nSave" << inputv[1] << " apagado." << endl;
                        delete (*it);
                        saves.erase(it);
                        return OK;
                    } else {
                        cout << "\nSave" << inputv[1] << " nao apagado." << endl;
                        return SAVE_USER_CANCEL;
                    }
                }
            }

            return SAVE_NOT_FOUND;

        case 13: // info
            if (inputv.size() != 2) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            int j;
            for (j = 0; j < comandos.size(); j++)
                if (comandos[j].getNome() == inputv[1]) {
                    cout << endl << comandos[j] << endl;
                    return OK;
                }
                
            return CMD_INFO_UNKNOWN;

#if DEBUG
        case 14: // toma
            if (inputv.size() < 3 || (inputv[1] != "tec" && inputv[1] != "terr")) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            errcode code;
            if (inputv[1] == "tec") {
                ostringstream os;
                for (size_t i = 2; i < inputv.size(); i++) {
                    os << inputv[i];
                    if (i < inputv.size() - 1)
                        os << ' ';
                }

                code = mnd.giveTec(os.str());
            } else
                code = mnd.giveTerr(inputv[2]);
            
            return code;

        case 15: // modifica
            if (inputv.size() != 3 || (inputv[1] != "ouro" && inputv[1] != "prod")) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }
            
            for (char c : inputv[2])
                    if (!isdigit(c)) {
                        cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                        return CMD_INVALID_ARGS;
                    }

            if (inputv[1] == "ouro")
                mnd.modificaOuroImp(stoi(inputv[2]));
            else
                mnd.modificaProdImp(stoi(inputv[2]));

            return OK;

        case 16: { // fevento
            if (inputv.size() < 2) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            ostringstream os;
            for (size_t i = 1; i < inputv.size(); i++) {
                os << inputv[i];
                if (i < inputv.size() - 1)
                    os << ' ';
            }

            string evnt;
            errcode code = mnd.escolheEvento(evnt, os.str());
            if (code == OK || code == FIM_JOGO) {
                cout << endl << evnt << endl;
                return OK;
            }   

            return code;
        }

        case 17: // quit
            if (inputv.size() != 1) {
                cout << "\nInstrucoes: " << comandos[i].getNome() << ' ' << comandos[i].getArgs() << endl;
                return CMD_INVALID_ARGS;
            }

            mnd.forceFimJogo();
            return FIM_JOGO;
#endif

        default:
            return CMD_UNKNOWN;
    }

    return UNEXPECTED;
}

errcode Interface::changeCMDDisp(string nomeCMD, bool novaDisp) {
    for (Comando& cmd : comandos) {
        if (cmd.getNome() == nomeCMD) {
            if (novaDisp == cmd.isDisp())
                return CMD_DISP_UNCHANGED;
            else {
                cmd.setDisp(novaDisp);
                return OK;
            }
        }
    }

    return CMD_UNKNOWN;
}

string Interface::getComandosDisponiveis() const {
    ostringstream os;

    for (Comando cmd : comandos) {
        if (cmd.isDisp())
            os << cmd.getNome() << " ";
    }

    return os.str();
}

Interface& Interface::operator=(const Interface& dir) {
    if (this == &dir) return *this;         // Self assignment

    for (int i = 0; i < saves.size(); i++)
        delete saves[i];

    saves.clear();

    mnd = dir.mnd;
    proxFase = dir.proxFase;
    comandos = dir.comandos;

    for (int i = 0; i < dir.saves.size(); i++) {
        saves.push_back(new Save(*(dir.saves[i])));
    }
    return *this;
}