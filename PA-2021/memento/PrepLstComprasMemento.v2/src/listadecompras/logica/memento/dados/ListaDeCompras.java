package listadecompras.logica.memento.dados;

import listadecompras.logica.memento.IMementoOriginator;
import listadecompras.logica.memento.Memento;

import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;

public class ListaDeCompras implements Serializable, IMementoOriginator {

    private ArrayList<Produto> produtos;

    public ListaDeCompras() {
        produtos = new ArrayList<>();
        //preenche();
    }

    private boolean isIndiceValido(int indice){
        return indice >=0 && indice < produtos.size();
    }

    public void acrescentaNovoProduto(String nome, int quantidade){
        if (quantidade > 0) {
            produtos.add(new Produto(nome, quantidade));
        }
    }

    public void eliminaProduto(int indice){
        if( isIndiceValido(indice)){
            produtos.remove(indice);
        }
    }

    public void alteraQuantidade(int indice, int quantidade){
        if( !isIndiceValido(indice) || quantidade < 0){
            return;
        }
        if(quantidade == 0){
            eliminaProduto( indice);
        } else {
            produtos.get(indice).setQuantidade(quantidade);
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for ( int i = 0 ; i < produtos.size() ; ++i){
            sb.append("(").append(i).append(") ").append(produtos.get(i)).append("\n");
        }
        return sb.toString();
    }

    public int getN(){
        return produtos.size();
    }

    @Override
    public Memento getMemento() throws IOException {
        Memento m = new Memento(produtos);
        return m;
    }

    @Override
    public void setMemento(Memento m) throws IOException, ClassNotFoundException {
        produtos = (ArrayList<Produto>) m.getSnapshot();
    }
}

