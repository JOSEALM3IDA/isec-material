package listadecompras.logica.memento;

import listadecompras.logica.memento.dados.ListaDeCompras;

import java.io.IOException;

// reencaminha a LIstaDe Compras
// acrescenta a funcionalidade de get/set Memento
// Lista de compras + capacidade de se gravar/reconstruir

public class ListaDeComprasOriginator implements IMementoOriginator {
    ListaDeCompras listaCompras;

    // --- fincionalidade do "save/load" é externa À lista de compras
    // o resto é reencaminhado para lista de compras por delegação
    // (como já acontece nos exemplos de FSM

    public ListaDeComprasOriginator() {
        this.listaCompras = new ListaDeCompras();
    }

    // fabrica o snapshot e retorna-o (=save)
    @Override
    public Memento getMemento() throws IOException {  // save
        Memento m = new Memento(listaCompras);
        return m;
    }

    // repõe os dados com base no snapshot
    @Override
    public void setMemento(Memento m) throws IOException, ClassNotFoundException {
        listaCompras = (ListaDeCompras) m.getSnapshot();   // load
    }


    // --- delegação na lista de compras ---

    public void acrescentaNovoProduto( String nome, int quantidade) {
        listaCompras.acrescentaNovoProduto(nome, quantidade);
    }

    public void eliminaProduto( int indice) {
        listaCompras.eliminaProduto(indice);
    }

    public void alteraQuantidade(int indice, int quantidade){
        listaCompras.alteraQuantidade(indice, quantidade);
    }

    @Override
    public String toString() {
        return listaCompras.toString();
    }

    public int getN() {
        return listaCompras.getN();
    }

}
