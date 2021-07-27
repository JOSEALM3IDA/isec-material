package jogo.logica.estados;

import jogo.logica.dados.QuatroEmLinhaGestor;

public class JogaMinijogo extends EstadoAdapter {

    protected JogaMinijogo(QuatroEmLinhaGestor quatroEmLinhaGestor) { super(quatroEmLinhaGestor); }

    @Override
    public Estado jogarMinijogo(String resposta) {
        quatroEmLinhaGestor.enviarRespostaMinijogo(resposta);

        if (quatroEmLinhaGestor.isAcabadoMinijogo()) {
            if (quatroEmLinhaGestor.ganhouUltimoMinijogo()) {
                quatroEmLinhaGestor.adicionaFichaEspecialJogadorAtual();
                return new PedeDecisaoJogada(quatroEmLinhaGestor);
            }

            quatroEmLinhaGestor.perdeuMinijogo();

            return new PedeDecisaoJogada(quatroEmLinhaGestor);
        }

        return this;
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
    public Situacao getSituacao() { return Situacao.JogaMinijogo; }
}
