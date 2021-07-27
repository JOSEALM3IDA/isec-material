package jogo.logica.dados.jogadores;

import jogo.logica.dados.tabuleiro.Tabuleiro;
import jogo.logica.dados.tabuleiro.TipoFicha;

public interface Jogador {

    void setNumJogadasDesdeMinijogo(int numJogadasDesdeMinijogo);
    void setNumCreditos(int num);
    void setNumFichasEspeciais(int num);
    void adicionarMinijogo();
    void reset();

    int getJogadaAutomatica(Tabuleiro tabuleiro);
    TipoFicha getFicha();
    String getNome();
    boolean isComputador();
    void setVencedor(boolean valor);
    boolean isVencedor();
    int getNumJogadasDesdeMinijogo();
    int getNumFichasEspeciais();
    int getNumCreditos();
    int getNumMinijogos();
}
