package pt.isec.jalmeida.oval_v3.logica;

public class Retangulo extends Figura {

    public double getX1() { return Math.min(x1, x2); }

    public double getY1() { return Math.min(y1, y2); }

    public double getX2() { return Math.max(x1, x2); }

    public double getY2() { return Math.max(y1, y2); }

    @Override
    public TipoFigura getTipoFigura() {
        return TipoFigura.RETANGULO;
    }

}
