package pt.isec.jalmeida.oval_v2.logica;

public class Figura {
    double x1, y1;
    double x2, y2;
    double r, g, b;

    public double getX1() {
        return Math.min(x1, x2);
    }

    public double getY1() {
        return Math.min(y1, y2);
    }

    public double getX2() {
        return x2;
    }

    public double getY2() {
        return y2;
    }

    public double getR() {
        return r;
    }

    public double getG() {
        return g;
    }

    public double getB() {
        return b;
    }

    public double getCX() { return (x1 + x2) / 2; }

    public double getCY() { return (y1 + y2) / 2; }

    public double getLargura() {
        return Math.abs(x1 - x2);
    }

    public double getAltura() {
        return Math.abs(y1 - y2);
    }

    public void setP1(double x, double y) {
        this.x1 = x;
        this.y1 = y;
    }

    public void setP2(double x, double y) {
        this.x2 = x;
        this.y2 = y;
    }

    public void setRGB(double r, double g, double b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }
}
