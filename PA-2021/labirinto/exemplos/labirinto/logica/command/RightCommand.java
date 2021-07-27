package exemplos.labirinto.logica.command;

import exemplos.labirinto.logica.modelo.LabirintoGame;

public class RightCommand extends CommandAdapter {

    public RightCommand(LabirintoGame receiver) {
        super(receiver);
    }

    @Override
    public boolean execute() { return receiver.right(); }

    @Override
    public boolean undo() { return receiver.left(); }

}
