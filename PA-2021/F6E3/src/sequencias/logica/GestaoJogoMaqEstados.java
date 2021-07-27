package sequencias.logica;

import sequencias.logica.memento.CareTaker;
import sequencias.logica.memento.JogoMaqEstados;
import sequencias.logica.memento.dados.Situacao;

public class GestaoJogoMaqEstados {

    private final JogoMaqEstados jogoMaqEstados;
    private final CareTaker careTaker;

    public GestaoJogoMaqEstados() {
        jogoMaqEstados = new JogoMaqEstados();
        careTaker = new CareTaker(jogoMaqEstados);
    }

    public Situacao getSituacaoAtual() { return jogoMaqEstados.getSituacaoAtual(); }
    public int getNDadosLancados() { return jogoMaqEstados.getNDadosLancados(); }

    public void comecar() {
        careTaker.gravaMemento();
        jogoMaqEstados.comecar();
    }

    public void relancar() {
        careTaker.gravaMemento();
        jogoMaqEstados.relancar();
    }

    public void recolher(int indice) {
        careTaker.gravaMemento();
        jogoMaqEstados.recolher(indice);
    }

    public void avaliar() {
        careTaker.gravaMemento();
        jogoMaqEstados.avaliar();
    }

    public void undo() { careTaker.undo(); }

    public void redo() { careTaker.redo(); }

    public String toString() {
        return careTaker.toString() + "\n" + jogoMaqEstados.toString();
        //     info acerca das pilhas undo/redo  + info acerca da lista de compras
    }
}
