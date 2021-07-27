package jogo.logica.estados;

import jogo.logica.dados.QuatroEmLinhaGestor;
import jogo.logica.dados.jogadores.TipoJogador;

public class PedeConfiguracao extends EstadoAdapter {

    protected PedeConfiguracao(QuatroEmLinhaGestor quatroEmLinhaGestor) { super(quatroEmLinhaGestor); }

    @Override
    public Estado adicionarJogador(TipoJogador tipoJogador, String nomeJogador) {
        quatroEmLinhaGestor.addJogador(tipoJogador, nomeJogador);
        return quatroEmLinhaGestor.isFullJogadores() ?
                new PedeDecisaoJogada(quatroEmLinhaGestor)
                :
                new PedeConfiguracao(quatroEmLinhaGestor);
    }

    @Override
    public Estado voltar() { return new PedeDecisaoInicio(quatroEmLinhaGestor); }

    @Override
    public Situacao getSituacao() { return Situacao.PedeConfiguracao; }
}
