package bw.logica.dados;

public class BolaBranca extends Bola {
    @Override
    public boolean reagirASerRetiradaDoSaco(JogoDados jogoDados) {
        return jogoDados.sairBolaBranca();
    }

    @Override
    public void removerSeBranca(JogoDados jogoDados) {
        jogoDados.removerDoSaco(this);
        jogoDados.incrementaBrancasRemovidas();
        jogoDados.addMsgLog("removeu bola branca  na b b");
    }

    @Override
    public void removerSePreta(JogoDados jogoDados) {
    }
    public String toString()    {
        return "B";
    }
}
