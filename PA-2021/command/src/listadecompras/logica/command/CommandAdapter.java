package listadecompras.logica.command;


import listadecompras.logica.dados.ListaDeCompras;

public abstract class CommandAdapter implements ICommand{
    protected final ListaDeCompras receiver;
    
    protected CommandAdapter(ListaDeCompras receiver){
        this.receiver = receiver;
    }

    @Override
    public boolean execute() {
        return false;
    }

    @Override
    public boolean undo() {
        return false;
    }

/*    ListaDeCompras getReceiver() {
        return receiver;
    }*/
    
}
