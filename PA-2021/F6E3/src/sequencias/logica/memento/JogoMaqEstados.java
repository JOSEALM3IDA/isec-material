package sequencias.logica.memento;


import sequencias.logica.memento.dados.Situacao;
import sequencias.logica.memento.dados.JogoDados;
import sequencias.logica.memento.dados.estados.AguardaInicio;
import sequencias.logica.memento.dados.estados.IEstado;
import sequencias.logica.memento.dados.JogoMaqEstadosSaver;

import java.io.IOException;
import java.io.Serializable;

public class JogoMaqEstados implements Serializable, IMementoOriginator {

    private JogoDados jogoDados;
    private IEstado estado;

    public JogoMaqEstados() {
        jogoDados = new JogoDados();
        estado = new AguardaInicio(jogoDados);
    }

    //  metodos que consultam

    public int getNDadosLancados() { return jogoDados.getNDadosLancados(); }

    public String toString()    {
        return estado.getSituacaoAtual() + "\n" +jogoDados.toString();
    }

    public Situacao getSituacaoAtual() { return estado.getSituacaoAtual(); }

    // regista novo estado activo
    private void setEstado(IEstado estado) {
        this.estado = estado;
    }

    // acoes delegadas no estado
    public void comecar() { setEstado(estado.comecar()); }
    public void recolher(int indice) { setEstado(estado.recolher(indice)); }
    public void relancar() {
        setEstado(estado.relancar());
    }
    public void avaliar() {
        setEstado(estado.avaliar());
    }
    public void terminar() {
        setEstado(estado.terminar());
    }

    @Override
    public Memento getMemento() throws IOException { return new Memento(new JogoMaqEstadosSaver(jogoDados, estado)); }

    @Override
    public void setMemento(Memento m) throws IOException, ClassNotFoundException {
        JogoMaqEstadosSaver save = (JogoMaqEstadosSaver) m.getSnapshot();
        jogoDados = save.getJogoDados();
        estado = save.getEstado();
    }
}
