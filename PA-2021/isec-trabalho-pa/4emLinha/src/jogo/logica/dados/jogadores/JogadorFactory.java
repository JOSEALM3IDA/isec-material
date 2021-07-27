package jogo.logica.dados.jogadores;

import jogo.logica.dados.tabuleiro.TipoFicha;

public class JogadorFactory {

    private JogadorFactory() {}

    public static Jogador getJogador(TipoJogador tipoJogador, String nomeJogador, TipoFicha novaFicha) {
        return switch (tipoJogador) {
            case HUMANO -> new Humano(nomeJogador, novaFicha);
            case COMPUTADOR -> new Computador(nomeJogador, novaFicha);
        };
    }
}
