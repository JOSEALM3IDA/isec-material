package listadecompras.logica.command;


import listadecompras.logica.dados.ListaDeCompras;

public class AcrescentaProdutoCommand extends CommandAdapter {
    // membros com informacao necessaria
    // a execucao do comando
    // que pode ser recebida no construtor
    private String nome;
    private int quantidade;

    public AcrescentaProdutoCommand(ListaDeCompras receiver, String nome, int quantidade ) {
        super(receiver);
        this.nome = nome;
        this.quantidade = quantidade;
    }

    // executa o comando encapsulado por este objecto
    // retorna true se a operacao for realizada com sucesso
    // e se a operacao de undo for possivel
    @Override
    public boolean execute() {
        receiver.acrescentaProduto( nome, quantidade);
        return true;
    }

    // undo correspondente a esta operacao
    // retorna true se o undo teve sucesso
    @Override
    public boolean undo() {
        return receiver.eliminaProduto(nome, quantidade);
    }
    
    @Override
    public String toString() {
        return "\n\tAcrescentaNovoProdutoCommand { nome= " + nome + ", quantidade=" + quantidade + '}';
    }
    
}
