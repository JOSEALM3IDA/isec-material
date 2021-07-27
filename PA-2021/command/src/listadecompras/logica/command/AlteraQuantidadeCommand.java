package listadecompras.logica.command;

import listadecompras.logica.dados.ListaDeCompras;
import listadecompras.logica.dados.Produto;

public class AlteraQuantidadeCommand extends CommandAdapter {
    // membros com informacao necessaria
    // a execucao do comando
    // que pode ser recebida no construtor
    private int indice;
    private int quantidade;
    private int quantidadeAnterior;
    private String nome;

    public AlteraQuantidadeCommand(ListaDeCompras receiver, int indice, int quantidade ) {
        super(receiver);
        this.indice = indice;
        this.quantidade = quantidade;
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
        quantidadeAnterior =prod.getQuantidade();
        return receiver.alteraQuantidade(indice, quantidade);
    }

    // undo correspondente a esta operacao
    // retorna true se o undo teve sucesso
    @Override
    public boolean undo() {
        if(quantidade == 0){
            receiver.acrescentaProduto(nome, quantidadeAnterior);
            return true;
        }
        return receiver.alteraQuantidade(indice, quantidadeAnterior);
    }

    @Override
    public String toString() {
        return "\n\tAlteraQuantidadeCommand { indice= " + indice + ", quantidade=" + quantidade + '}';
    }

}

