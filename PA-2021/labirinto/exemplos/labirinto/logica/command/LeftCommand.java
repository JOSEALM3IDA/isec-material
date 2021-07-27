package exemplos.labirinto.logica.command;

import exemplos.labirinto.logica.modelo.LabirintoGame;

public class LeftCommand extends CommandAdapter {

    public LeftCommand(LabirintoGame receiver) {
        super(receiver);
    }

    @Override
    public boolean execute() { return receiver.left(); }

    @Override
    public boolean undo() { return receiver.right(); }

}
