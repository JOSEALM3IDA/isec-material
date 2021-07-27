package sequencias.logica.memento.dados.estados;

import sequencias.logica.memento.dados.Situacao;
import sequencias.logica.memento.dados.JogoDados;

import java.io.Serializable;

public class AguardaInicio extends EstadoAdapter implements Serializable {
    public AguardaInicio(JogoDados j) {
        super(j);
    }

    @Override
    public IEstado comecar() {
        jogoDados.inicia();
        jogoDados.lancaDados();

        return new AguardaRelancamento(jogoDados);
    }

    @Override
    public Situacao getSituacaoAtual() {
        return Situacao.AGUARDA_INICIO;
    }
}
