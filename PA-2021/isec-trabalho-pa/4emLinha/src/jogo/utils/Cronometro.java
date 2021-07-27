package jogo.utils;

public class Cronometro {

    private long tempoComeco = -1;
    private long tempoFinal = -1;

    public void comecar() {
        tempoComeco = System.currentTimeMillis();
        tempoFinal = -1;
    }
    public void acabar() { tempoFinal = System.currentTimeMillis() - tempoComeco; }

    public long getTempoTotal() { return tempoComeco != -1 && tempoFinal != -1 ? tempoFinal - tempoComeco : -1; }

    public boolean isAtivo() { return tempoComeco != -1 && tempoFinal == -1; }
    public boolean isAcabado() { return tempoComeco != -1 && tempoFinal != -1; }

    public boolean passouTempo(int segundos) {
        if (!isAtivo()) return false;

        if (isAcabado()) return getTempoTotal() > segundos;

        long tempoAtual = System.currentTimeMillis();

        return (tempoAtual - tempoComeco) > (segundos * 1000L);
    }
}
