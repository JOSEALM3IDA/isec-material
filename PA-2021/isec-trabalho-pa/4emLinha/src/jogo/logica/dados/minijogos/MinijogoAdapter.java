package jogo.logica.dados.minijogos;

import jogo.utils.Cronometro;

public abstract class MinijogoAdapter implements Minijogo {

    protected String perguntaAtual = "";
    protected Cronometro cronometro = new Cronometro();
    protected boolean isComecado = false;
    protected boolean isAcabado = false;
    protected boolean isGanho = false;
    protected int numPontos = 0;

    @Override
    public boolean isValidaResposta(String resposta) { return true; }

    @Override
    public String getPerguntaAtual() { return perguntaAtual; }

    @Override
    public boolean isGanho() { return isGanho; }

    @Override
    public boolean isAcabado() { return isAcabado; }

    @Override
    public int getPontuacaoAtual() { return numPontos; }

    protected abstract void gerarNovaPergunta();





}
