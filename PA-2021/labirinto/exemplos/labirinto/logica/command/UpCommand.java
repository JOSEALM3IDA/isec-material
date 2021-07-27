package exemplos.labirinto.logica.command;

import exemplos.labirinto.logica.modelo.LabirintoGame;

public class UpCommand extends CommandAdapter {

    public UpCommand(LabirintoGame receiver) {
        super(receiver);
    }

    @Override
    public boolean execute() { return receiver.up(); }

    @Override
    public boolean undo() { return receiver.down(); }

}
