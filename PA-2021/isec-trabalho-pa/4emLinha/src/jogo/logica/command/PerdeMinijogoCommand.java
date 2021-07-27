package jogo.logica.command;

import jogo.logica.dados.QuatroEmLinha;

public class PerdeMinijogoCommand extends CommandAdapter {

    public PerdeMinijogoCommand(QuatroEmLinha receiver) { super(receiver); }

    @Override
    public boolean execute() {
        if (receiver == null) return false;

        receiver.proxJogador();
        return true;
    }

    @Override
    public TipoJogada getTipoJogada() { return TipoJogada.PERDER_MINIJOGO; }

    @Override
    public String toString() { return nomeJogador + " perde minijogo"; }
}
