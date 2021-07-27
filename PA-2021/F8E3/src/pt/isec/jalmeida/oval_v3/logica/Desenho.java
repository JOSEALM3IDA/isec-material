package pt.isec.jalmeida.oval_v3.logica;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Desenho implements Serializable {
    public static final int serialVersionUID = 1;

    double r, g, b;
    Figura atual;
    Figura.TipoFigura tipo;
    ArrayList<Figura> lista;

    public Desenho() { this.lista = new ArrayList<>(); }

    public void setRGB(double r, double g, double b) { this.r = r; this.g = g; this.b = b; }

    public void setTipo(Figura.TipoFigura tipo) { this.tipo = tipo; }

    public Figura.TipoFigura getTipo() { return this.tipo; }


    public double getR() { return r; }
    public double getG() { return g; }
    public double getB() { return b; }

    public void inicia(double x, double y) {
        if (tipo == null) tipo = Figura.TipoFigura.LINHA;

        switch (tipo) {
            case LINHA -> atual = new Linha();
            case RETANGULO -> atual = new Retangulo();
            case OVAL -> atual = new Oval();
            default -> {
                atual = null;
                return;
            }
        }

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
