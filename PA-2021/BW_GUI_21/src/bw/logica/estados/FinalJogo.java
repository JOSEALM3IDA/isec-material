package bw.logica.estados;


import bw.logica.Situacao;
import bw.logica.dados.JogoDados;

public class FinalJogo extends EstadoAdapter{

    public FinalJogo(JogoDados jogoDados) {
        super(jogoDados);
    }

    @Override
    public IEstado comecarJogo() {
        getJogoDados().inicia();
        return new AguardaAposta(getJogoDados());
    }
    public Situacao getSituacaoAtual() {
        return Situacao.FINAL_JOGO;
    }

}
