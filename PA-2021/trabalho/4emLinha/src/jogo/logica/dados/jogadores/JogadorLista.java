package jogo.logica.dados.jogadores;

import jogo.logica.dados.tabuleiro.Tabuleiro;
import jogo.logica.dados.tabuleiro.TipoFicha;
import jogo.utils.Utils;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class JogadorLista implements Serializable {
    private static final int MAX_PLAYERS = 2;

    private final ArrayList<Jogador> jogadores = new ArrayList<>(2);
    private int currJogadorIdx = 0;
    private int primeiroJogadorIdx;

    public boolean isFullJogadores() { return jogadores.size() == MAX_PLAYERS; }

    public void addJogador(TipoJogador tipoJogador, String nomeJogador) {
        if (isFullJogadores()) return;

        TipoFicha novaFicha = getRandomFichaDisponivel();
        if (novaFicha == null || novaFicha == TipoFicha.NONE) return;

        if (!existeJogador(nomeJogador)) {
            Jogador novoJogador = JogadorFactory.getJogador(tipoJogador, nomeJogador, novaFicha);
            jogadores.add(novoJogador);
        }

        if (!isFullJogadores()) return;

        primeiroJogadorIdx = Utils.getNumeroRandom(getNumJogadores());
        currJogadorIdx = primeiroJogadorIdx;
    }

    private TipoFicha getRandomFichaDisponivel() {
        List<TipoFicha> tipos = new ArrayList<>(Arrays.asList(TipoFicha.values()));

        for (var jogador : jogadores) {
            TipoFicha fichaJogador = jogador.getFicha();

            if (fichaJogador == null) continue;

            tipos.remove(fichaJogador);
        }

        if (tipos.isEmpty()) return null;
        return tipos.get(0);
    }

    public boolean existeJogador(String nomeJogador) {
        for (var jogador : jogadores) if (nomeJogador.equals(jogador.getNome())) return true;

        return false;
    }

    public void proxJogador() {
        Jogador currJogador = getJogadorAtual();
        currJogador.setNumJogadasDesdeMinijogo(currJogador.getNumJogadasDesdeMinijogo() + 1);

        currJogadorIdx++;

        if (currJogadorIdx == jogadores.size()) currJogadorIdx = 0;
    }

    public void undoJogador(int numVezes) {
        for (var jogador : jogadores) jogador.setNumJogadasDesdeMinijogo(0);

        for (int i = 0; i < numVezes; i++) {
            currJogadorIdx--;

            if (currJogadorIdx < 0) currJogadorIdx = jogadores.size() - 1;
        }

    }

    public void setVencedorJogadorComFicha(TipoFicha ficha) {
        for (var jogador : jogadores) {
            if (jogador.getFicha() == ficha) {
                jogador.setVencedor(true);
                continue;
            }

            jogador.setVencedor(false);
        }
    }

    public void aceitarMinijogo() { getJogadorAtual().adicionarMinijogo(); }

    public boolean isComputadorAJogar() { return getJogadorAtual().isComputador(); }
    public int getNumJogadores() { return jogadores.size(); }
    public String getNomeJogadorAtual() { return getJogadorAtual().getNome(); }
    public int getJogadaAutomatica(Tabuleiro tabuleiro) { return getJogadorAtual().getJogadaAutomatica(tabuleiro); }
    public TipoFicha getFichaAtual() { return getJogadorAtual().getFicha(); }
    public TipoFicha getFichaAnterior() { return currJogadorIdx == 0 ? jogadores.get(jogadores.size() - 1).getFicha() : jogadores.get(currJogadorIdx - 1).getFicha(); }
    public int getNumJogadasDesdeMinijogoCurrJogador() { return getJogadorAtual().getNumJogadasDesdeMinijogo(); }
    private Jogador getJogadorAtual() { return jogadores.get(currJogadorIdx); }

    public String getNomeVencedor() {
        for (var jogador : jogadores) if (jogador.isVencedor()) return jogador.getNome();

        return null;
    }

    public TipoFicha getFichaVencedor() {
        for (var jogador : jogadores) if (jogador.isVencedor()) return jogador.getFicha();

        return null;
    }


    public void limpar() { jogadores.clear(); }

    public void adicionaFichaEspecialJogadorAtual() { getJogadorAtual().setNumFichasEspeciais(getNumFichasEspeciaisJogadorAtual() + 1); }

    public int getNumFichasEspeciaisJogadorAtual() { return getJogadorAtual().getNumFichasEspeciais(); }

    public void usarFichaEspecialJogadorAtual() { getJogadorAtual().setNumFichasEspeciais(getNumFichasEspeciaisJogadorAtual() - 1); }

    public void removeCreditoJogadorAtual(int numCreditos) { getJogadorAtual().setNumCreditos(getJogadorAtual().getNumCreditos() - numCreditos); }

    public boolean haVencedor() {
        for (var jogador : jogadores) if (jogador.isVencedor()) return true;
        return false;
    }

    public int getNumCreditosJogadorAtual() { return getJogadorAtual().getNumCreditos(); }

    public void resetEstadoJogadores() {
        for (var jogador : jogadores) jogador.reset();
        currJogadorIdx = primeiroJogadorIdx;
    }

    @Override
    public String toString() {
        if (jogadores.isEmpty()) return "Sem Jogadores";

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < jogadores.size(); i++) {
            sb.append(i + 1).append(": ").append(jogadores.get(i).toString());
            if (i != jogadores.size() - 1)
                sb.append('\n');
        }

        return sb.toString();
    }

    public int getNumMinijogosJogadorAtual() { return getJogadorAtual().getNumMinijogos(); }
}
