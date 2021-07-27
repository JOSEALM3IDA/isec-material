package exemplos.labirinto.logica.modelo;

import exemplos.labirinto.logica.command.*;

import java.util.List;

public class GestaoLabirintoGame {
    private final LabirintoGame labirintoGame;
    private final CommandManager commandManager;

    public GestaoLabirintoGame(double vr) {
        this.labirintoGame = new LabirintoGame(vr);
        this.commandManager = new CommandManager();
    }

    public void up() { commandManager.invokeCommand(new UpCommand(labirintoGame)); }
    public void down() { commandManager.invokeCommand(new DownCommand(labirintoGame)); }
    public void left() { commandManager.invokeCommand(new LeftCommand(labirintoGame)); }
    public void right() { commandManager.invokeCommand(new RightCommand(labirintoGame)); }

    public void inicializa() { labirintoGame.inicializa(); }
    public boolean isGameFinished() { return labirintoGame.isGameFinished(); }
    public List<String> getVisibleMap() { return labirintoGame.getVisibleMap(); }

    public void undo() { commandManager.undo(); }
    public void redo() { commandManager.redo(); }

}
