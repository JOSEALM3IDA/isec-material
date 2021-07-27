package bw.logica.estados;


import bw.logica.dados.JogoDados;

public abstract class EstadoAdapter implements IEstado{
    private JogoDados jogoDados;

    protected EstadoAdapter(JogoDados j) {
        this.jogoDados = j;
    }

    public JogoDados getJogoDados() {
        return jogoDados;
    }
    @Override
    public IEstado comecarJogo(){ return this;}

    @Override
    public IEstado terminar() {
        return this;
    }

    @Override
    public IEstado apostar(int n) {
        return this;
    }

    @Override
    public IEstado escolherOpcaoPerderPontuacao() {
        return this;
    }

    @Override
    public IEstado escolherOpcaoRetirarDuasBolas() {
        return this;
    }
}
