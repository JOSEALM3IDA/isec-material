package bw.logica.estados;


import bw.logica.Situacao;
import bw.logica.dados.JogoDados;

public class AguardaInicio extends EstadoAdapter {

    public AguardaInicio(JogoDados jogoDados) {
        super(jogoDados);
    }

    @Override
    public IEstado comecarJogo() {
        getJogoDados().inicia();
        return new AguardaAposta(getJogoDados());
    }
    public Situacao getSituacaoAtual() {
        return Situacao.AGUARDA_INICIO;
    }

}
