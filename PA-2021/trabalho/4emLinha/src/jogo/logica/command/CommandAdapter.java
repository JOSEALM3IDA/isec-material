package jogo.logica.command;

import jogo.logica.dados.QuatroEmLinha;

import java.io.Serializable;

public class CommandAdapter implements Command, Serializable {
    protected final QuatroEmLinha receiver;
    protected final String nomeJogador;

    protected CommandAdapter(QuatroEmLinha receiver) {
        this.receiver = receiver;
        this.nomeJogador = receiver.getNomeJogadorAtual();
    }

    @Override
    public boolean execute() { return false; }

    @Override
    public void undo() { /* deve ser overridden nos comandos */ }

    @Override
    public boolean temUndo() { return false; }

    @Override
    public TipoJogada getTipoJogada() { return TipoJogada.NONE; }

    @Override
    public String toString() { return nomeJogador + " fez algo indefinido"; }

}
