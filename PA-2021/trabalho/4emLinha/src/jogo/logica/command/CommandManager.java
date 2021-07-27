package jogo.logica.command;

import jogo.logica.dados.QuatroEmLinha;

import java.io.Serializable;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class CommandManager implements Serializable {

    private final Stack<Command> historico = new Stack<>();
    private final Stack<Command> fullHistorico = new Stack<>();

    public void invokeCommand(Command command) {
        if (!command.temUndo()) {
            fullHistorico.push(command);
            command.execute();
            return;
        }

        if (command.execute()) {
            fullHistorico.push(command);
            historico.push(command);
            return;
        }

        historico.clear();
    }

    public void undo(int numVezes, QuatroEmLinha receiver) {
        if (historico.size() < numVezes) return;

        List<Command> commandsToUndo = new LinkedList<>();
        for (int i = 0; i < numVezes; i++) commandsToUndo.add(historico.pop());

        Collections.reverse(commandsToUndo);

        invokeCommand(new DesfazerJogadasCommand(commandsToUndo, receiver));
    }

    public boolean temUndo() { return !historico.isEmpty(); }

    public int getNumUndosPossivel() { return historico.size(); }

    public boolean temProximo() { return !fullHistorico.isEmpty(); }

    public void executarProximo() {
        if (!temProximo()) return;

        Command primeiroDaLista = fullHistorico.remove(0);
        primeiroDaLista.execute();
    }

    public String getDescricaoComandoAtual() { return !fullHistorico.isEmpty() ? fullHistorico.get(0).toString() : ""; }

    public void resetHistorico() {
        historico.clear();
        fullHistorico.clear();
    }

    public TipoJogada getTipoJogadaAtual() { return !fullHistorico.isEmpty() ? fullHistorico.get(0).getTipoJogada() : TipoJogada.NONE; }
}
