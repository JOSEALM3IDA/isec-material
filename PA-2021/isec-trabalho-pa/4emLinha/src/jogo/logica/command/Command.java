package jogo.logica.command;

public interface Command {
    boolean execute();
    void undo();
    boolean temUndo();

    TipoJogada getTipoJogada();
}
