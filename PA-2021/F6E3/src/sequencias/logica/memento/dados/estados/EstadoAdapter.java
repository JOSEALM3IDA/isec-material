package sequencias.logica.memento.dados.estados;


import sequencias.logica.memento.dados.JogoDados;

import java.io.Serializable;

public abstract class EstadoAdapter implements IEstado, Serializable {
    protected JogoDados jogoDados;

    protected EstadoAdapter(JogoDados j) {
        this.jogoDados = j;
    }

    @Override
    public IEstado comecar() {
        return this;
    }

    @Override
    public IEstado recolher(int indice) {
        return this;
    }

    @Override
    public IEstado relancar() {
        return this;
    }

    @Override
    public IEstado avaliar() {
        return this;
    }

    @Override
    public IEstado terminar() {
        return this;
    }

    // implementações por omissão dos métodos/transições de estado
}
