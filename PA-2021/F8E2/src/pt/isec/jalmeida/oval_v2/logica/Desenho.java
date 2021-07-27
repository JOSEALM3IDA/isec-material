package pt.isec.jalmeida.oval_v2.logica;

import java.util.ArrayList;
import java.util.List;

public class Desenho {
    double r, g, b;
    Figura atual;
    ArrayList<Figura> lista;

    public Desenho() { this.lista = new ArrayList<>(); }

    public void setRGB(double r, double g, double b) { this.r = r; this.g = g; this.b = b; }

    public double getR() { return r; }
    public double getG() { return g; }
    public double getB() { return b; }

    public void inicia(double x, double y) {
        atual = new Figura();
        atual.setP1(x, y);
        atual.setP2(x, y);
        atual.setRGB(r, g, b);
    }

    public void altera(double x, double y) {
        if (atual == null) return;
        atual.setP2(x, y);
    }

    public void termina(double x, double y) {
        if (atual == null) return;
        atual.setP2(x ,y);
        lista.add(atual);
        atual = null;
    }

    public void apagaUltima() {
        atual = null;
        if (lista.isEmpty()) return;
        lista.remove(lista.size() - 1);
    }

    public void apagaTudo() {
        lista.clear();
        atual = null;
    }

    public List<Figura> getLista() { return lista; }
    public Figura getAtual() { return atual; }
}
