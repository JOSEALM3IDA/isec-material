package listadecompras.logica.command;

import java.util.ArrayList;

public class CommandManager {
    private ArrayList<ICommand> historico = new ArrayList<ICommand>();
    private ArrayList<ICommand> redoLista = new ArrayList<ICommand>();
    
    // invoca um comando e faz a gestao dos historicos
    public void invokeCommand(ICommand command) {
        if (command.execute()) {
            // se o comando foi executado com sucesso
            // e se tem undo correspondente
            historico.add(command);
        } else {
            // nao tem undo 
            // esvazia-se o historico
            historico.clear();
        }
        // depois de se executar um comando 
        // esvazia-se o redo
        redoLista.clear();
    }

    public void undo() {
        if (historico.size() > 0) {
            // se o historico nao esta vazio
            ICommand commandoUndo = historico.remove(historico.size() - 1);
            commandoUndo.undo();
            redoLista.add(commandoUndo);
        }
    }

    public void redo() {
        if (redoLista.size() > 0) {
            // se a lista de comandos redo nao esta vazia
            ICommand commandoRedo = redoLista.remove(redoLista.size() - 1);
            commandoRedo.execute();
            historico.add(commandoRedo);
        }
    }

    public boolean isHistoricoVazio() {
        return historico.isEmpty();
    }

    public boolean isRedoVazio() {
        return redoLista.isEmpty();
    }

    @Override
    public String toString() {
        return "\nhistorico=" + historico + "\nredoLista=" + redoLista;
    }
    
}
