package labirintojfx.logica;

public enum Situacao {
    AGUARDA_CONFIG("Configura isso"),
    AGUARDA_MOVIMENTO("Joga"),
    AGUARDA_FINAL("Pontuaçao");
    String valor;
    Situacao(String s) { valor = s; }
    @Override
    public String toString() { return valor; }
}
