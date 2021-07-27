package listadecompras.logica.memento;

public interface ICareTaker {
    void saveMemento();
    void undo();
    void redo();
}
