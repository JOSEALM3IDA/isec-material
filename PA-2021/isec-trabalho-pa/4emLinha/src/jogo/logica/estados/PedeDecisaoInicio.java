package jogo.logica.estados;

import jogo.logica.dados.QuatroEmLinhaGestor;

public class PedeDecisaoInicio extends EstadoAdapter {

    public PedeDecisaoInicio(QuatroEmLinhaGestor quatroEmLinhaGestor) { super(quatroEmLinhaGestor); }

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
    public Situacao getSituacao() { return Situacao.PedeDecisaoInicio; }

}
