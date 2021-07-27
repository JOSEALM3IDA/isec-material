package bw.logica.dados;

public class BolaPreta extends Bola {
    @Override
    public boolean reagirASerRetiradaDoSaco(JogoDados jogoDados) {
        return jogoDados.sairBolaPreta();
    }

    @Override
    public void removerSeBranca(JogoDados jogoDados) {
    }

    @Override
    public void removerSePreta(JogoDados jogoDados) {
        jogoDados.removerDoSaco(this);
        jogoDados.incrementaPretasRemovidas();
        jogoDados.addMsgLog("removeu bola preta  na b p");
    }
    public String toString()    {
        return "P";
    }
}