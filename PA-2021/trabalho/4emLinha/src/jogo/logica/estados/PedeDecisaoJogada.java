package jogo.logica.estados;

import jogo.logica.dados.QuatroEmLinhaGestor;

public class PedeDecisaoJogada extends EstadoAdapter {

    protected PedeDecisaoJogada(QuatroEmLinhaGestor quatroEmLinhaGestor) { super(quatroEmLinhaGestor); }

    @Override
    public Estado jogarFicha(int col) {
        quatroEmLinhaGestor.jogarFicha(col);
        return quatroEmLinhaGestor.checkFimJogo() ? new FimJogo(quatroEmLinhaGestor) : new PedeDecisaoJogada(quatroEmLinhaGestor);
    }

    @Override
    public Estado undoJogada(int numVezes) {
        quatroEmLinhaGestor.undo(numVezes);
        return new PedeDecisaoJogada(quatroEmLinhaGestor);
    }

    @Override
    public Estado desistir() {
        quatroEmLinhaGestor.desistir();
        return new FimJogo(quatroEmLinhaGestor);
    }

    @Override
    public Estado aceitarMinijogo() {
        quatroEmLinhaGestor.comecarMinijogo();
        return new JogaMinijogo(quatroEmLinhaGestor);
    }

    @Override
    public Estado jogarFichaEspecial(int col) {
        quatroEmLinhaGestor.jogarFichaEspecial(col);
        return new PedeDecisaoJogada(quatroEmLinhaGestor);
    }

    @Override
    public Estado iniciarJogo() {
        quatroEmLinhaGestor.resetTotal();
        return new PedeConfiguracao(quatroEmLinhaGestor);
    }

    @Override
    public Estado continuarJogo(QuatroEmLinhaGestor quatroEmLinhaGestor) {
        this.quatroEmLinhaGestor = quatroEmLinhaGestor;
        return new PedeDecisaoJogada(quatroEmLinhaGestor);
    }

    @Override
    public Estado verReplay(QuatroEmLinhaGestor quatroEmLinhaGestor) {
        this.quatroEmLinhaGestor = quatroEmLinhaGestor;
        return new AssisteJogada(quatroEmLinhaGestor);
    }

    @Override
    public Estado voltar() { return new PedeDecisaoInicio(quatroEmLinhaGestor); }

    @Override
    public Situacao getSituacao() { return Situacao.PedeDecisaoJogada; }
}
