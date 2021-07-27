package jogo.logica.estados;

import jogo.logica.dados.QuatroEmLinhaGestor;

public class AssisteJogada extends EstadoAdapter {

    protected AssisteJogada(QuatroEmLinhaGestor quatroEmLinhaGestor) {
        super(quatroEmLinhaGestor);
        quatroEmLinhaGestor.setReplayAtivo(true);
    }

    @Override
    public Estado avancar() {
        quatroEmLinhaGestor.executarProximo();

        if (quatroEmLinhaGestor.temProximo()) return new AssisteJogada(quatroEmLinhaGestor);

        return new FimJogo(quatroEmLinhaGestor);
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
    public Situacao getSituacao() { return Situacao.AssisteJogada; }
}
