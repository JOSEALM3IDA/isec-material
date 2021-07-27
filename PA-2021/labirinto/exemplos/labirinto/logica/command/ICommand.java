package exemplos.labirinto.logica.command;

public interface ICommand {
    boolean execute();
    boolean undo();
}
