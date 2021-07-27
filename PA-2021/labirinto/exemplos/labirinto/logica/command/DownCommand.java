package exemplos.labirinto.logica.command;

import exemplos.labirinto.logica.modelo.LabirintoGame;

public class DownCommand extends CommandAdapter {

    public DownCommand(LabirintoGame receiver) {
        super(receiver);
    }

    @Override
    public boolean execute() { return receiver.down(); }

    @Override
    public boolean undo() { return receiver.up(); }

}
