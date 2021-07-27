package listadecompras.logica.dados;

import java.io.Serializable;
import java.util.ArrayList;

public class ListaDeCompras implements Serializable {
    private ArrayList<Produto> produtos;

    public ListaDeCompras() {
        produtos = new ArrayList<>();
       // preenche();
    }
    private void preenche(){
        produtos.add( new Produto("Laranja", 2));
        produtos.add( new Produto("Morango", 1));
        produtos.add( new Produto("Batata", 5));
    }

    private boolean isIndiceValido(int indice){
        return indice >=0 && indice < produtos.size();
    }

    public void acrescentaProduto(String nome, int quantidade){
        if (quantidade > 0) {
            produtos.add(new Produto(nome, quantidade));
        }
    }

    public boolean eliminaProduto(String nome, int quantidade){
        return produtos.remove(new Produto(nome, quantidade));
    }

    public boolean eliminaProduto( int indice){
        if( !isIndiceValido(indice)){
            return false;
        }
        produtos.remove(indice);
        return true;
    }
    public Produto getProduto(int indice){
        if( !isIndiceValido(indice)){
            return null;
        }
        return produtos.get(indice);
    }
    public boolean alteraQuantidade(int indice, int quantidade){
        if( !isIndiceValido(indice) || quantidade < 0){
            return false;
        }
        if(quantidade == 0){
            eliminaProduto( indice);
        } else {
            produtos.get(indice).setQuantidade(quantidade);
        }
        return true;
    }
    @Override
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
}
