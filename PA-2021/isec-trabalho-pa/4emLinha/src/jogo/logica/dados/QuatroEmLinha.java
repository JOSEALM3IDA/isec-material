package jogo.logica.dados;

import jogo.logica.dados.jogadores.*;
import jogo.logica.dados.minijogos.Minijogo;
import jogo.logica.dados.minijogos.MinijogoFactory;
import jogo.logica.dados.tabuleiro.Tabuleiro;
import jogo.logica.dados.tabuleiro.TipoFicha;

import java.io.Serializable;
import java.util.LinkedList;
import java.util.List;

public class QuatroEmLinha implements Serializable {

    private final JogadorLista jogadorLista = new JogadorLista();
    private final Tabuleiro tabuleiro = new Tabuleiro();
    private transient Minijogo minijogo = null;

    public boolean checkFimJogo() {
        TipoFicha fichaAnterior = jogadorLista.getFichaAnterior();

        if (tabuleiro.isEmpatado()) return true;
        if (!tabuleiro.checkQuatroEmLinha(fichaAnterior)) return false;

        jogadorLista.setVencedorJogadorComFicha(fichaAnterior);
        return true;
    }

    public void resetJogo() {
        jogadorLista.limpar();
        tabuleiro.limpar();
    }

    public void desistirJogadorAtual() {
        TipoFicha fichaAnterior = jogadorLista.getFichaAnterior();
        jogadorLista.setVencedorJogadorComFicha(fichaAnterior);
    }

    public void comecarMinijogo() {
        if (!temMinijogoDisponivel()) return;

        minijogo = MinijogoFactory.getMinijogo(jogadorLista.getNumMinijogosJogadorAtual());
        minijogo.comecar();
        jogadorLista.aceitarMinijogo();
    }

    public void jogarFichaEspecial(int col) {
        List<TipoFicha> colunaVazia = new LinkedList<>();
        for (int lin = 0; lin < tabuleiro.getNumLinhas(); lin++) colunaVazia.add(TipoFicha.NONE);

        jogadorLista.usarFichaEspecialJogadorAtual();
        tabuleiro.setColuna(col, colunaVazia);
    }

    public void processaUndoJogadorAtual(int numVezes) {
        jogadorLista.removeCreditoJogadorAtual(numVezes);
        anteriorJogador(numVezes);
    }

    public void addJogador(TipoJogador tipoJogador, String nomeJogador) { jogadorLista.addJogador(tipoJogador, nomeJogador); }
    public void jogarFicha(int col) { tabuleiro.addFicha(col, jogadorLista.getFichaAtual()); }
    public void removeFicha(int col) { tabuleiro.removeFicha(col); }
    public void setColuna(int col, List<TipoFicha> novaColuna) { tabuleiro.setColuna(col, novaColuna); }
    public void resetTabuleiro() { tabuleiro.limpar(); }
    public void resetEstadoJogadores() { jogadorLista.resetEstadoJogadores(); }
    public void proxJogador() { jogadorLista.proxJogador(); }
    private void anteriorJogador(int numVezes) { jogadorLista.undoJogador(numVezes); }
    public void enviarRespostaMinijogo(String resposta) { if (minijogo != null) minijogo.receberResposta(resposta); }
    public void adicionaFichaEspecialJogadorAtual() { jogadorLista.adicionaFichaEspecialJogadorAtual(); }

    public int getJogadaAutomatica() { return jogadorLista.getJogadaAutomatica(tabuleiro); }
    public boolean existeJogador(String nomeJogador) { return jogadorLista.existeJogador(nomeJogador); }
    public boolean isFullJogadores() { return jogadorLista.isFullJogadores(); }
    public int getNumJogadores() { return jogadorLista.getNumJogadores(); }
    public int getNumLinhas() { return tabuleiro.getNumLinhas(); }
    public int getNumColunas() { return tabuleiro.getNumColunas(); }
    public String getNomeJogadorAtual() { return jogadorLista.getNomeJogadorAtual(); }
    public String getNomeVencedor() { return jogadorLista.getNomeVencedor(); }
    public TipoFicha getFichaVencedor() { return jogadorLista.getFichaVencedor(); }
    public String getConfigJogadores() { return "Lista de jogadores:\n" + jogadorLista; }
    public List<TipoFicha> getTabuleiro() { return tabuleiro.getFichas(); }
    public boolean temMinijogoDisponivel() { return jogadorLista.getNumJogadasDesdeMinijogoCurrJogador() >= 4; }
    public boolean isComputadorAJogar() { return jogadorLista.isComputadorAJogar(); }
    public String getPerguntaMinijogo() { return minijogo != null ? minijogo.getPerguntaAtual() : ""; }
    public boolean isValidaRespostaMinijogo(String resposta) { return minijogo != null && minijogo.isValidaResposta(resposta); }
    public boolean ganhouUltimoMinijogo() { return minijogo != null && minijogo.isGanho(); }
    public boolean isAcabadoMinijogo() { return minijogo != null && minijogo.isAcabado(); }
    public int getPontuacaoAtualMinijogo() { return minijogo.getPontuacaoAtual(); }
    public int getNumFichasEspeciaisJogadorAtual() { return jogadorLista.getNumFichasEspeciaisJogadorAtual(); }
    public boolean jogoAcabou() { return tabuleiro.isEmpatado() || jogadorLista.haVencedor(); }
    public int getNumCreditosJogadorAtual() { return jogadorLista.getNumCreditosJogadorAtual(); }
    public boolean temCreditosJogadorAtual(int numCreditos) { return jogadorLista.getNumCreditosJogadorAtual() >= numCreditos; }
    public boolean temCreditosJogadorAtual() { return temCreditosJogadorAtual(1); }
    public List<TipoFicha> getColuna(int col) { return tabuleiro.getColuna(col); }
    public boolean isJogavelColuna(int coluna) { return !jogoAcabou() && tabuleiro.isJogavelColuna(coluna); }
    public boolean isEmpatado() { return tabuleiro.isEmpatado(); }
    public TipoFicha getFichaAtual() { return jogadorLista.getFichaAtual(); }
    public boolean jogoComecou() { return isFullJogadores(); }
}
