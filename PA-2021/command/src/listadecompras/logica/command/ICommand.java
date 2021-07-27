
package listadecompras.logica.command;

public interface ICommand {
    
    // operacao representada por este comando
    // retorna true se a operacao foi realizada com sucesso
    // e se a operacao de undo for possivel
    boolean execute();  
    
    // undo correspondente a esta operacao
    // retorna true se o undo teve sucesso
    boolean undo();
}
