package exemplos.labirinto.logica.command;

import exemplos.labirinto.logica.modelo.LabirintoGame;

public class CommandAdapter implements ICommand {
    protected LabirintoGame receiver;

    protected CommandAdapter(LabirintoGame receiver) { this.receiver = receiver; }

    @Override
    public boolean execute() { return false; }

    @Override
    public boolean undo() { return false; }
}
