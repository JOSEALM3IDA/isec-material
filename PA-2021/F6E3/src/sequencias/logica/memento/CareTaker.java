package sequencias.logica.memento;

import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Deque;

public class CareTaker {
    private final IMementoOriginator originator;

    //private Stack<Memento> stackHist = new Stack<>();
    //private Stack<Memento> stackRedo = new Stack<>();
    private Deque<Memento> stackHist = new ArrayDeque<>();
    private Deque<Memento> stackRedo = new ArrayDeque<>();

    public CareTaker(IMementoOriginator org) { this.originator = org; }

    public void gravaMemento() {
        stackRedo.clear();
        try{
            stackHist.push(originator.getMemento());
        } catch(IOException ex) {
            System.err.println("gravaMemento: " + ex);
            stackHist.clear();
            stackRedo.clear();
        }
    }

    public void undo() {
        if (stackHist.isEmpty()) {
            return;
        }

        try {
            Memento atual = originator.getMemento();
            stackRedo.push(atual);
            Memento anterior = stackHist.pop();
            originator.setMemento(anterior);
        } catch(IOException | ClassNotFoundException ex) {
            System.err.println("undo: " + ex);
            stackHist.clear();
            stackRedo.clear();
        }

    }

    public void redo() {
        if (stackRedo.isEmpty()) {
            return;
        }

        try {
            Memento sredo = stackRedo.pop();
            stackHist.push(originator.getMemento());
            originator.setMemento(sredo);
        } catch(IOException | ClassNotFoundException ex) {
            System.err.println("redo: " + ex);
            stackHist.clear();
            stackRedo.clear();
        }
    }

    // metodos que consultam
    // isto é só para debug
    public String toString(){
        return "\nstackHist=" + stackHist.size() +
                "\nstackRedo=" + stackRedo.size();
    }

}


