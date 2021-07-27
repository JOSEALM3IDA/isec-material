package jogo.logica.command;

import jogo.logica.dados.QuatroEmLinha;

public class DesistirCommand extends CommandAdapter {

    public DesistirCommand(QuatroEmLinha receiver) { super(receiver); }

    @Override
    public boolean execute() {
        if (receiver == null) return false;

        receiver.desistirJogadorAtual();
        return true;
    }

    @Override
    public String toString() { return nomeJogador + " desiste"; }
}
