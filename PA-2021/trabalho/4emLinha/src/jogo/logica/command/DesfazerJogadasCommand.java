package jogo.logica.command;

import jogo.logica.dados.QuatroEmLinha;

import java.util.List;

public class DesfazerJogadasCommand extends CommandAdapter {

    List<Command> jogadas;

    public DesfazerJogadasCommand(List<Command> jogadas, QuatroEmLinha receiver) {
        super(receiver);
        this.jogadas = jogadas;
    }

    @Override
    public boolean execute() {
        for (var jogada : jogadas) jogada.undo();
        receiver.processaUndoJogadorAtual(jogadas.size());
        return false;
    }

    @Override
    public String toString() { return nomeJogador + " faz " + jogadas.size() + " undos"; }

}
