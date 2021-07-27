package jogo.logica.estados;

import jogo.logica.dados.QuatroEmLinhaGestor;
import jogo.logica.dados.jogadores.TipoJogador;

import java.io.Serializable;

public abstract class EstadoAdapter implements Estado, Serializable {

    protected QuatroEmLinhaGestor quatroEmLinhaGestor;

    protected EstadoAdapter(QuatroEmLinhaGestor quatroEmLinhaGestor) { this.quatroEmLinhaGestor = quatroEmLinhaGestor; }

    @Override
    public Estado iniciarJogo() { return this; }

    @Override
    public Estado continuarJogo(QuatroEmLinhaGestor quatroEmLinhaGestor) { return this; }

    @Override
    public Estado verReplay(QuatroEmLinhaGestor quatroEmLinhaGestor) { return this; }

    @Override
    public Estado voltar() { return this; }

    @Override
    public Estado adicionarJogador(TipoJogador tipoJogador, String nomeJogador) { return this; }

    @Override
    public Estado jogarFicha(int col) { return this; }

    @Override
    public Estado undoJogada(int numVezes) { return this; }

    @Override
    public Estado desistir() { return this; }

    @Override
    public Estado aceitarMinijogo() { return this; }

    @Override
    public Estado jogarFichaEspecial(int col) { return this; }

    @Override
    public Estado jogarMinijogo(String resposta) { return this; }

    @Override
    public Estado avancar() { return this; }
}
