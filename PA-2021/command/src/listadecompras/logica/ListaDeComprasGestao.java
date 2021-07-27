package listadecompras.logica;

import listadecompras.logica.command.AcrescentaProdutoCommand;
import listadecompras.logica.command.AlteraQuantidadeCommand;
import listadecompras.logica.command.CommandManager;
import listadecompras.logica.command.EliminaProdutoCommand;
import listadecompras.logica.dados.ListaDeCompras;

public class ListaDeComprasGestao {
    private ListaDeCompras listaDeCompras;
    private CommandManager commandManager;

    public ListaDeComprasGestao() {
        this.listaDeCompras = new ListaDeCompras();
        this.commandManager = new CommandManager();
    }
    /*public CommandManager getCommandManager() {
        return commandManager;
    }*/

    public void acrescentaNovoProduto( String nome, int quantidade){
        commandManager.invokeCommand(new AcrescentaProdutoCommand(listaDeCompras, nome, quantidade));
    }

    public void eliminaProduto( int indice){
        commandManager.invokeCommand(new EliminaProdutoCommand(listaDeCompras, indice));
    }
    public void alteraQuantidade(int indice, int quantidade){
        commandManager.invokeCommand(new AlteraQuantidadeCommand(listaDeCompras,indice, quantidade));
    }

    public void undo() {
        commandManager.undo();
    }
    public void redo() {
        commandManager.redo();
    }


    public String toString(){
        return commandManager.toString() + "\n" + listaDeCompras.toString();
    }

}
