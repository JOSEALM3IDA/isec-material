package jogo.logica.dados.jogadores;

import jogo.logica.dados.tabuleiro.Tabuleiro;
import jogo.logica.dados.tabuleiro.TipoFicha;

import java.io.Serializable;

public abstract class JogadorAdapter implements Jogador, Serializable {

    protected int numJogadasDesdeMinijogo = 0;
    private final String nome;
    private final TipoFicha ficha;
    protected boolean isVencedor = false;
    protected int numFichasEspeciais = 0;
    protected int numCreditos = 0;
    protected int numMinijogos = 0;

    protected JogadorAdapter(String nome, TipoFicha ficha) {
        this.nome = nome;
        this.ficha = ficha;
    }

    @Override
    public void setNumJogadasDesdeMinijogo(int numJogadasDesdeMinijogo) {
        if (numJogadasDesdeMinijogo < 0) {
            this.numJogadasDesdeMinijogo = 0;
            return;
        }

        this.numJogadasDesdeMinijogo = numJogadasDesdeMinijogo;
    }

    @Override
    public void setNumCreditos(int num) {
        if (num < 0) {
            this.numCreditos = 0;
            return;
        }

        this.numCreditos = num;
    }

    @Override
    public void setNumFichasEspeciais(int num) {}

    @Override
    public void adicionarMinijogo() {}

    @Override
    public void reset() {
        numJogadasDesdeMinijogo = 0;
        isVencedor = false;
        numFichasEspeciais = 0;
        numCreditos = 0;
    }

    @Override
    public int getJogadaAutomatica(Tabuleiro tabuleiro) { return -1; }

    @Override
    public TipoFicha getFicha() { return ficha; }

    @Override
    public String getNome() { return nome; }

    @Override
    public boolean isComputador() { return false; }

    @Override
    public void setVencedor(boolean valor) { isVencedor = valor; }

    @Override
    public boolean isVencedor() { return isVencedor; }

    @Override
    public int getNumJogadasDesdeMinijogo() { return numJogadasDesdeMinijogo; }

    @Override
    public int getNumFichasEspeciais() { return numFichasEspeciais; }

    @Override
    public int getNumCreditos() { return numCreditos; }

    @Override
    public int getNumMinijogos() { return numMinijogos; }

    @Override
    public String toString() { return nome; }
}
