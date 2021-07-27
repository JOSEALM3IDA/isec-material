package labirintojfx.logica;

public enum PropsID {
    PROP_ESTADO("prop_estado"),
    PROP_MOVE("prop_move");
    String valor;
    PropsID(String s) { valor = s; }
    @Override
    public String toString() { return valor; }
}