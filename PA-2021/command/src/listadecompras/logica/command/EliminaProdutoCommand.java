package listadecompras.logica.command;

import listadecompras.logica.dados.ListaDeCompras;
import listadecompras.logica.dados.Produto;

public class EliminaProdutoCommand extends CommandAdapter {
    // membros com informacao necessaria
    // a execucao do comando
    // que pode ser recebida no construtor
    private int indice;
    private String nome;
    private int quantidade;

    public EliminaProdutoCommand(ListaDeCompras receiver, int indice ) {
        super(receiver);
        this.indice = indice;
    }

    // executa o comando encapsulado por este objecto
    // retorna true se a operacao for realizada com sucesso
    // e se a operacao de undo for possivel
    @Override
    public boolean execute() {
        Produto prod = receiver.getProduto(indice);
        if(prod == null){
            return false;
        }
        nome = prod.getNome();
        quantidade = prod.getQuantidade();
        return receiver.eliminaProduto(indice);
    }

    // undo correspondente a esta operacao
    // retorna true se o undo teve sucesso
    @Override
    public boolean undo() {
        receiver.acrescentaProduto(nome, quantidade);
        return true;
    }

    @Override
    public String toString() {
        return "\n\tEliminaProdutoCommand { nome= " + nome + ", quantidade=" + quantidade + '}';
    }

}

