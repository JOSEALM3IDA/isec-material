package sequencias.logica.memento.dados;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class JogoDados implements Serializable {
    private static final int N_DADOS = 10;
    private static final int MAX_RELANCAMENTOS = 3;
    private List<Dado> dadosLancados;
    private List<Dado> mao;
    private int pontuacao;
    private int nRelancamentos;

    public JogoDados() {
        inicia();
    }

    public void inicia(){
        pontuacao = 0;
        nRelancamentos = MAX_RELANCAMENTOS + 1; // +1 => lancamento inicial
        dadosLancados = new ArrayList<>();
        mao = new ArrayList<>();

        for (int i = 0; i < N_DADOS; ++i) {
            mao.add(new Dado());
        }
    }

    public int getnRelancamentos() {
        return nRelancamentos;
    }

    // lanca os dados que tem na mao
    public boolean lancaDados() {
        if (mao.isEmpty()) return false;

        if (nRelancamentos <= 0) {
            dadosLancados.addAll(mao);
            mao.clear();
            return false;
        }

        nRelancamentos--;
        while (!mao.isEmpty()) {
            Dado dado = mao.remove(0);
            dado.lanca();
            dadosLancados.add(dado);
        }

        return true;
    }

    //recolhe o dado correspondente a indice para relancar
    // ou para formar sequencias (o dado passa para a mao)
    public void recolheDado(int indice) {
        if (indice < 0 || indice >= dadosLancados.size()) {
            return;
        }
        mao.add(dadosLancados.remove(indice));
    }

    private boolean avaliaSequenciaConstante (int d2) {
        int pontSeqNaMao = 1;
        if (mao.size() > 3) {
            for (int i = 3; i < mao.size(); i++) {
                if (mao.get(i).getValor() != d2) return false;

                pontSeqNaMao++;
            }
        }
        pontuacao += pontSeqNaMao;
        return true;
    }
    private boolean avaliaSequenciaCrescente (int d) {
        int pontSeqNaMao = 1;
        if (mao.size() > 3) {
            for (int i = 3; i < mao.size(); i++){
                if (mao.get(i).getValor() != d + 1) return false;

                //pontSeqMao = 0;

                pontSeqNaMao++;
                d++;
            }
        }
        pontuacao += pontSeqNaMao;
        return true;
    }

    public void avaliaSequencia() {
        if (mao.size() < 3) {
            dadosLancados.addAll(mao);
            mao.clear();
            return;
        }

        int d0 = mao.get(0).getValor();
        int d1 = mao.get(1).getValor();
        int d2 = mao.get(2).getValor();

        boolean isSequenciaConstante = d0 == d1 && d1 == d2 && avaliaSequenciaConstante(d2);
        boolean isSequenciaCrescente = d2 == d1 + 1 && d1 == d0 + 1 && avaliaSequenciaCrescente(d2);

        if (isSequenciaConstante || isSequenciaCrescente) mao.clear();
    }

    // verifica se o jogo terminou (verificar regras)
    public boolean jogoTerminou() {
        return false;
    }

    public int getNDadosLancados() { return dadosLancados.size(); }

    public int getnDadosMao() { return mao.size(); }

    public int getPontuacao() { return pontuacao; }

    public String toString() {
        return  " pontuacao = " + pontuacao +
                "\n dados na mao = " + mao +
                "\n dados lancados = " + dadosLancados;
    }
}
