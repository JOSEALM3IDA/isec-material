package exemplos.labirinto.logica.command;

import java.util.Stack;

public class CommandManager {
    private final Stack<ICommand> historico = new Stack<>();
    private final Stack<ICommand> redoLista = new Stack<>();

    // invoca um comando e faz a gestao dos historicos
    public void invokeCommand(ICommand command) {
        if (command.execute()) {
            // se o comando foi executado com sucesso
            // e se tem undo correspondente
            historico.push(command);
        } else {
            System.out.println("Nao executou / nao tem undo. Esvaziar historico. Isto gera um problema, o undo nao fica disponivel.");
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
            ICommand commandUndo = historico.pop();
            commandUndo.undo();
            redoLista.push(commandUndo);
        }
    }

    public void redo() {
        if (redoLista.size() > 0) {
            // se a lista de comandos redo nao esta vazia
            ICommand commandRedo = redoLista.pop();
            commandRedo.execute();
            historico.push(commandRedo);
        }
    }

    public boolean isHistoricoVazio() { return historico.isEmpty(); }

    public boolean isRedoVazio() { return redoLista.isEmpty(); }

    @Override
    public String toString() {
        return "\nhistorico=" + historico + "\nredoLista=" + redoLista;
    }
}
