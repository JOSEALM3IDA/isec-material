package jogo.logica.dados.minijogos;

public interface Minijogo {

    void comecar();
    void receberResposta(String resposta);
    boolean isValidaResposta(String resposta);
    String getPerguntaAtual();
    boolean isGanho();
    boolean isAcabado();
    int getPontuacaoAtual();

}
