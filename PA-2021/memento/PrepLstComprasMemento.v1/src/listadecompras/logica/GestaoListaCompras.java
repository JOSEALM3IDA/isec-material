package listadecompras.logica;


// a UI vem bater a esta porta
// delega metade para a lista de compras, e metade para a CareTaker

import listadecompras.logica.memento.CareTaker;
import listadecompras.logica.memento.ListaDeComprasOriginator;

public class GestaoListaCompras {
    private ListaDeComprasOriginator originator;
    private CareTaker careTaker;

    public GestaoListaCompras() {
        originator = new ListaDeComprasOriginator();
        careTaker = new CareTaker(originator);
    }

    public void acrescentaNovoProduto( String nome, int quantidade) {
        careTaker.gravaMemento();
        originator.acrescentaNovoProduto(nome, quantidade);
    }

    public void eliminaProduto( int indice) {
        careTaker.gravaMemento();
        originator.eliminaProduto(indice);
    }

    public void alteraQuantidade(int indice, int quantidade) {
        careTaker.gravaMemento();
        originator.alteraQuantidade(indice, quantidade);
    }


    public void undo() {
        careTaker.undo();
    }

    public void redo() {
        careTaker.redo();
    }

    // metodos que consultam

    public String toString() {
        return careTaker.toString() + "\n" + originator.toString();
        //     info acerca das pilhas undo/redo  + info acerca da lista de compras
    }
}
