package listadecompras.logica.memento.dados;

import java.io.Serializable;

public class Produto implements Serializable {
    private  final String nome;
    private int quantidade;

    public Produto(String nome, int quantidade){
        this.nome = nome;
        this.quantidade = quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    @Override
    public String toString() {
        return String.format("%-10s -> %2d", nome, quantidade);
    }
}
