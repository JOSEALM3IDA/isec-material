package listadecompras.logica;


// a UI vem bater a esta porta
// delega metade para a lista de compras, e metade para a CareTaker

import listadecompras.logica.dados.ListaDeCompras;
import listadecompras.logica.memento.ICareTaker;
import listadecompras.logica.memento.Memento;

import java.io.IOException;
import java.util.Stack;

public class GestaoListaCompras implements ICareTaker {
    private ListaDeCompras originator;

    public GestaoListaCompras() {
        originator = new ListaDeCompras();
    }

    public void acrescentaNovoProduto( String nome, int quantidade) {
        saveMemento();
        originator.acrescentaNovoProduto(nome, quantidade);
    }

    public void eliminaProduto( int indice) {
        saveMemento();
        originator.eliminaProduto(indice);
    }

    public void alteraQuantidade(int indice, int quantidade) {
        saveMemento();
        originator.alteraQuantidade(indice, quantidade);
    }

    // metodos que consultam

    public String toString() {
        return  "\nstackHist=" + stackHist.size() +
                "\nstackRedo=" + stackRedo.size() +
                "\n" + originator.toString();
        //     info acerca das pilhas undo/redo  + info acerca da lista de compras
    }

    // CareTaker

    private Stack<Memento> stackHist = new Stack<>();
    private Stack<Memento> stackRedo = new Stack<>();
    //private Deque<Memento> stackHist = new ArrayDeque<>();
    //private Deque<Memento> stackRedo = new ArrayDeque<>();

    @Override
    public void saveMemento() {
        stackRedo.clear();
        try{
            stackHist.push(originator.getMemento());
        } catch(IOException ex) {
            System.err.println("gravaMemento: " + ex);
            stackHist.clear();
            stackRedo.clear();
        }
    }

    @Override
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

    @Override
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

}
