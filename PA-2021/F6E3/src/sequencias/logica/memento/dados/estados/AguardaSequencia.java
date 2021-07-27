package sequencias.logica.memento.dados.estados;

import sequencias.logica.memento.dados.Situacao;
import sequencias.logica.memento.dados.JogoDados;

import java.io.Serializable;

public class AguardaSequencia extends EstadoAdapter implements Serializable {
    public AguardaSequencia(JogoDados j) {
        super(j);
    }

    @Override
    public IEstado recolher(int indice) {
        jogoDados.recolheDado(indice);
        return new AguardaRelancamento(jogoDados);
    }

    @Override
    public IEstado avaliar() {
        if (jogoDados.getnDadosMao() == 0) return this;

        jogoDados.avaliaSequencia();

        if (jogoDados.jogoTerminou()) return new AguardaInicio(jogoDados);
        return new AguardaSequencia(jogoDados);
    }

    @Override
    public IEstado terminar() {
        if (jogoDados.getnDadosMao() > 0) return this;
        return new AguardaInicio(jogoDados);
    }

    @Override
    public Situacao getSituacaoAtual() {
        return Situacao.AGUARDA_SEQUENCIA;
    }
}
