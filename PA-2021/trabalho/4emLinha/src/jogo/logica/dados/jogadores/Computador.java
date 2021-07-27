package jogo.logica.dados.jogadores;

import jogo.logica.dados.tabuleiro.Tabuleiro;
import jogo.logica.dados.tabuleiro.TipoFicha;
import jogo.utils.Utils;

public class Computador extends JogadorAdapter {

    public Computador(String nome, TipoFicha ficha) { super(nome, ficha); }

    @Override
    public int getJogadaAutomatica(Tabuleiro tabuleiro) {
        int coluna;

        do { coluna = Utils.getNumeroRandom(tabuleiro.getNumColunas()); } while (!tabuleiro.isJogavelColuna(coluna));

        return coluna;
    }

    @Override
    public boolean isComputador() { return true; }

    @Override
    public void setNumFichasEspeciais(int num) { /* não usa fichas especiais */ }

    @Override
    public void reset() {
        numJogadasDesdeMinijogo = 0;
        isVencedor = false;
        numFichasEspeciais = 0;
        numCreditos = 0;
    }

    @Override
    public String toString() { return getNome() + " (CPU)"; }

}
