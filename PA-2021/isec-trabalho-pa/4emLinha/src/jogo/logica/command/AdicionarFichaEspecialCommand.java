package jogo.logica.command;

import jogo.logica.dados.QuatroEmLinha;

public class AdicionarFichaEspecialCommand extends CommandAdapter {

    public AdicionarFichaEspecialCommand(QuatroEmLinha receiver) { super(receiver); }

    @Override
    public boolean execute() {
        if (receiver == null) return false;

        receiver.adicionaFichaEspecialJogadorAtual();
        return true;
    }

    @Override
    public TipoJogada getTipoJogada() { return TipoJogada.GANHAR_MINIJOGO; }

    @Override
    public String toString() { return nomeJogador + " recebe ficha especial"; }
}
