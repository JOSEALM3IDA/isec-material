package jogo.logica.dados.minijogos;

public class MinijogoFactory {

    private MinijogoFactory() {}

    public static Minijogo getMinijogo(int numMinijogosPassados) {
        if (numMinijogosPassados % 2 == 0) return new Calculos();
        return new Palavras();
    }
}
