package bw.logica.estados;


import bw.logica.Situacao;
import bw.logica.dados.JogoDados;

public class AguardaAposta extends EstadoAdapter {

    public AguardaAposta(JogoDados jogoDados) {
        super(jogoDados);
    }

    public IEstado apostar(int n) {
        boolean apostaValida = getJogoDados().apostar(n);
        if(!apostaValida){
            return this;
        }
        if (getJogoDados().isSacoVazio()) {
            return new FinalJogo(getJogoDados());
        }
        boolean ganha = getJogoDados().tiraBolaDoSaco();
        if (getJogoDados().isSacoVazio()) {
            return new FinalJogo(getJogoDados());
        }
        if(ganha) {
            return new AguardaAposta(getJogoDados());
        } else {
            return new AguardaOpcao(getJogoDados());
        }
    }

    @Override
    public IEstado terminar() {
        return new FinalJogo(getJogoDados());
    }
    public Situacao getSituacaoAtual() {
        return Situacao.AGUARDA_APOSTA;
    }

}
