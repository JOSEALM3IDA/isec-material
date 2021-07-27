package listadecompras.logica.dados;

import java.io.Serializable;
import java.util.Objects;

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
       //return "{" + nome + ", quantidade=" + quantidade +'}';
        return String.format("%-10s -> %2d", nome, quantidade);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Produto produto = (Produto) o;
        return quantidade == produto.quantidade && nome.equals(produto.nome);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nome, quantidade);
    }

    public String getNome() {
        return nome;
    }

    public int getQuantidade() {
        return quantidade;
    }
}
