package sequencias.logica.memento.dados;

import sequencias.logica.memento.dados.estados.IEstado;

import java.io.Serializable;

public class JogoMaqEstadosSaver implements Serializable {
    private final JogoDados jogoDados;
    private final IEstado estado;

    public JogoMaqEstadosSaver(JogoDados jogoDados, IEstado estado) {
        this.jogoDados = jogoDados;
        this.estado = estado;
    }

    public JogoDados getJogoDados() { return jogoDados; }

    public IEstado getEstado() { return estado; }
}
