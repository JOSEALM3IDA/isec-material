package jogo.logica.dados;

import jogo.logica.command.*;
import jogo.logica.dados.tabuleiro.TipoFicha;
import jogo.logica.dados.jogadores.TipoJogador;

import java.io.Serializable;
import java.util.List;

public class QuatroEmLinhaGestor implements Serializable {

    protected QuatroEmLinha quatroEmLinha;
    private final CommandManager commandManager;

    private boolean isReplayAtivo = false;

    public QuatroEmLinhaGestor() {
        this.quatroEmLinha = new QuatroEmLinha();
        this.commandManager = new CommandManager();
    }

    public void addJogador(TipoJogador tipoJogador, String nomeJogador) { quatroEmLinha.addJogador(tipoJogador, nomeJogador); }
    public void jogarFicha(int col) { commandManager.invokeCommand(new JogarFichaCommand(quatroEmLinha, col)); }
    public void jogarFichaEspecial(int col) { commandManager.invokeCommand(new JogarFichaEspecialCommand(quatroEmLinha, col)); }
    public void adicionaFichaEspecialJogadorAtual() { commandManager.invokeCommand(new AdicionarFichaEspecialCommand(quatroEmLinha)); }
    public void perdeuMinijogo() { commandManager.invokeCommand(new PerdeMinijogoCommand(quatroEmLinha)); }
    public void desistir() { commandManager.invokeCommand(new DesistirCommand(quatroEmLinha)); }
    public void executarProximo() { commandManager.executarProximo(); quatroEmLinha.checkFimJogo(); }
    public void comecarMinijogo() { quatroEmLinha.comecarMinijogo(); }
    public void enviarRespostaMinijogo(String resposta) { quatroEmLinha.enviarRespostaMinijogo(resposta); }
    public void resetTotal() { setReplayAtivo(false); quatroEmLinha.resetJogo(); commandManager.resetHistorico(); }
    public void resetJogo() { quatroEmLinha.resetTabuleiro(); quatroEmLinha.resetEstadoJogadores(); }

    public int getJogadaAutomatica() { return quatroEmLinha.getJogadaAutomatica(); }
    public boolean existeJogador(String nomeJogador) { return quatroEmLinha.existeJogador(nomeJogador); }
    public boolean isFullJogadores() { return quatroEmLinha.isFullJogadores(); }
    public int getNumJogadores() { return quatroEmLinha.getNumJogadores(); }
    public int getNumLinhas() { return quatroEmLinha.getNumLinhas(); }
    public int getNumColunas() { return quatroEmLinha.getNumColunas(); }
    public String getNomeJogadorAtual() { return quatroEmLinha.getNomeJogadorAtual(); }
    public String getNomeVencedor() { return quatroEmLinha.getNomeVencedor(); }
    public TipoFicha getFichaVencedor() { return quatroEmLinha.getFichaVencedor(); }
    public String getConfigJogadores() { return quatroEmLinha.getConfigJogadores(); }
    public List<TipoFicha> getTabuleiro() { return quatroEmLinha.getTabuleiro(); }
    public boolean temMinijogoDisponivel() { return quatroEmLinha.temMinijogoDisponivel(); }
    public boolean isComputadorAJogar() { return quatroEmLinha.isComputadorAJogar(); }
    public boolean checkFimJogo() { return quatroEmLinha.checkFimJogo(); }
    public String getPerguntaMinijogo() { return quatroEmLinha.getPerguntaMinijogo(); }
    public boolean isValidaRespostaMinijogo(String resposta) { return quatroEmLinha.isValidaRespostaMinijogo(resposta); }
    public boolean ganhouUltimoMinijogo() { return quatroEmLinha.ganhouUltimoMinijogo(); }
    public boolean isAcabadoMinijogo() { return quatroEmLinha.isAcabadoMinijogo(); }
    public int getPontuacaoAtualMinijogo() { return quatroEmLinha.getPontuacaoAtualMinijogo(); }
    public int getNumFichasEspeciaisJogadorAtual() { return quatroEmLinha.getNumFichasEspeciaisJogadorAtual(); }
    public boolean jogoAcabou() { return quatroEmLinha.jogoAcabou(); }
    public int getNumCreditosJogadorAtual() { return quatroEmLinha.getNumCreditosJogadorAtual(); }
    public TipoFicha getFichaAtual() { return quatroEmLinha.getFichaAtual(); }
    public boolean podeVoltarAtrasJogadorAtual() { return commandManager.temUndo() && quatroEmLinha.temCreditosJogadorAtual(); }
    public int getNumCreditosJogaveisJogadorAtual() { return Math.min(commandManager.getNumUndosPossivel(), quatroEmLinha.getNumCreditosJogadorAtual()); }
    public boolean temProximo() { return commandManager.temProximo(); }
    public boolean isJogavelColuna(int coluna) { return quatroEmLinha.isJogavelColuna(coluna); }
    public boolean isEmpatado() { return quatroEmLinha.isEmpatado(); }
    public String getDescricaoComandoAtual() { return commandManager.getDescricaoComandoAtual(); }
    public TipoJogada getTipoJogadaAtual() { return commandManager.getTipoJogadaAtual(); }
    public void setReplayAtivo(boolean val) { isReplayAtivo = val; }
    public boolean isReplayAtivo() { return isReplayAtivo; }
    public boolean jogoComecou() { return quatroEmLinha.jogoComecou(); }

    public void undo(int numVezes) {
        if (jogoAcabou()) return;

        if (!quatroEmLinha.temCreditosJogadorAtual(numVezes)) return;
        commandManager.undo(numVezes, quatroEmLinha);
    }
}
