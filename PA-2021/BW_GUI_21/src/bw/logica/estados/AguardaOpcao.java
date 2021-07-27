package bw.logica.estados;


import bw.logica.Situacao;
import bw.logica.dados.JogoDados;

public class AguardaOpcao extends EstadoAdapter {

    public AguardaOpcao(JogoDados jogoDados) {
        super(jogoDados);
    }


    public IEstado escolherOpcaoPerderPontuacao() {
         if(getJogoDados().escolherOpcaoPerderPontuacao()){
             return new AguardaAposta(getJogoDados());
         } else {
             return this;
         }
    }

    public IEstado escolherOpcaoRetirarDuasBolas() {
        getJogoDados().escolherOpcaoRetirarDuasBolas();

        if (getJogoDados().isSacoVazio()) {
            return new FinalJogo(getJogoDados());
        }
        return new AguardaAposta(getJogoDados());
    }
    public Situacao getSituacaoAtual() {
        return Situacao.AGUARDA_OPCAO;
    }


}
