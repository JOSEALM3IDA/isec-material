#include "TV.h"
#include <sstream>

string TV::getAsString() const {
    ostringstream os;

    os << "Ligado: " << on << " Canal Atual: " << canalAtual << " Volume: " << volume << " NCanais: " << canais.size() << endl
       << "Canais Disponiveis: " << getTodosCanais() << endl;

    return os.str();
}

void TV::maisVol(size_t aumento) {
    if(on)
        volume += aumento;
}

void TV::menosVol(size_t diminuicao) {
    if(on)
        volume -= diminuicao;
}

string TV::getTodosCanais() const {
    ostringstream os;

    for(int i = 0; i < canais.size(); i++) {
        os << canais[i] << " : ";
    }

    return os.str();
}