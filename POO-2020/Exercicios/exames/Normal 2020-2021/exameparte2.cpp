class Desenho() {
    vector<Fig2D*> figuras;

public:
    Desenho(const Desenho& ref) {
        for (Fig2D* f : ref.figuras)
            figuras.push_back(new Fig2D(*f));
    }

    ~Desenho() {
        for (Fig2D* f : figuras)
            delete f;
    }

    void addFigura(Figura* novaFig) {
        for (auto it = figuras.begin(); it != figuras.end(); i++) {
            if (novaFig->area() < figuras[i]->area()) {   // ORDENAR POR ÁREA DE FORMA CRESCENTE. DESEMPATE: NOVA FIG  É "MAIOR" (SITUA-SE DEPOIS, NO VETOR)
                figuras.insert(it, novaFig);
                return;
            }
        }
    }

    float somaAreas() const {     // OPERAÇÃO POLIMÓRFICA - CALCULAR SOMA DAS ÁREAS COM AS DIFERENTES FÓRMULAS DE CADA FIGURA
        float sum;
        for (Fig2D* f : figuras)
            sum += f->area();

        return sum;
    }

    Desenho& operator=(const Desenho& ref) {
        for (Fig2D* f: figuras)
            //

        //figuras.clear()

        for (Fig2D* f : ref.figuras)
            figuras.push_back(new Fig2D(*f));
    }
}