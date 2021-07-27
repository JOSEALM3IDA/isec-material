package pt.isec.jalmeida.oval_v2.ui;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import pt.isec.jalmeida.oval_v2.logica.Desenho;
import pt.isec.jalmeida.oval_v2.logica.Figura;

public class AreaDesenho extends Canvas {
   Desenho desenho;

    public AreaDesenho(Desenho desenho) {
        super(400, 400);
        this.desenho = desenho;
        registarListeners();
        atualiza();
    }

    private void registarListeners() {
        this.addEventHandler(MouseEvent.MOUSE_PRESSED, e -> {
            desenho.inicia(e.getX(), e.getY());
            atualiza();
        });

        this.setOnMouseReleased(e -> {
            desenho.termina(e.getX(), e.getY());
            atualiza();
        });

        this.setOnMouseDragged(e -> {
            desenho.altera(e.getX(), e.getY());
            atualiza();
        });
    }

    public void clear(GraphicsContext gc) {
        gc.setFill(Color.rgb(255, 255, 240));
        gc.fillRect(0, 0, this.getWidth(), this.getHeight());
    }

    public void atualiza() {
        if (desenho == null) return;
        GraphicsContext gc = this.getGraphicsContext2D();
        clear(gc);
        for (Figura figura : desenho.getLista()) desenhaFigura(gc, figura);
        desenhaFigura(gc, desenho.getAtual());
    }

    private void desenhaFigura(GraphicsContext gc, Figura figura) {
        if (figura == null) return;
        gc.setFill(Color.color(figura.getR(), figura.getG(), figura.getB()));
        gc.fillOval(figura.getX1(), figura.getY1(), figura.getLargura(), figura.getAltura());

        gc.setLineWidth(3);
        gc.fillOval(figura.getX1(), figura.getY1(), figura.getLargura(), figura.getAltura());
        gc.strokeOval(figura.getX1(), figura.getY1(), figura.getLargura(), figura.getAltura());
    }

    public void alteraDims(double width, double height) {
        setWidth(width);
        setHeight(height);
        atualiza();
    }
}
