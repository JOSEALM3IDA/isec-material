package pt.isec.jalmeida.oval_v3.ui.stagebase;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.text.TextAlignment;
import pt.isec.jalmeida.oval_v3.logica.Desenho;
import pt.isec.jalmeida.oval_v3.logica.DesenhoObservable;
import pt.isec.jalmeida.oval_v3.logica.Figura;
import pt.isec.jalmeida.oval_v3.ui.resources.ImageLoader;

public class    AreaDesenho extends Canvas {
   DesenhoObservable desenhoObservable;

    public AreaDesenho(DesenhoObservable desenhoObservable) {
        super(400, 400);
        this.desenhoObservable = desenhoObservable;

        desenhoObservable.addObserver(DesenhoObservable.DESENHO, e -> atualiza());

        registarListeners();
        atualiza();
    }

    private void registarListeners() {
        this.addEventHandler(MouseEvent.MOUSE_PRESSED, e -> desenhoObservable.inicia(e.getX(), e.getY()));
        this.setOnMouseReleased(e -> desenhoObservable.termina(e.getX(), e.getY()));
        this.setOnMouseDragged(e -> desenhoObservable.altera(e.getX(), e.getY()));
    }

    public void clear(GraphicsContext gc) {
        gc.setFill(Color.rgb(255, 255, 240));
        gc.fillRect(0, 0, this.getWidth(), this.getHeight());
        //gc.drawImage(ImageLoader.getImage("img.png"),0, 0, this.getWidth(), this.getHeight());
    }

    public void atualiza() {
        if (desenhoObservable == null) return;
        GraphicsContext gc = this.getGraphicsContext2D();
        clear(gc);
        for (Figura figura : desenhoObservable.getLista()) desenhaFigura(gc, figura);
        desenhaFigura(gc, desenhoObservable.getAtual());
    }

    private void desenhaFigura(GraphicsContext gc, Figura figura) {
        if (figura == null) return;
        gc.setFill(Color.color(figura.getR(), figura.getG(), figura.getB()));
        gc.setStroke(Color.color(figura.getR(), figura.getG(), figura.getB()).darker());
        gc.setLineWidth(3);

        switch (figura.getTipoFigura()) {
            case LINHA -> gc.strokeLine(figura.getX1(), figura.getY1(), figura.getX2(), figura.getY2());
            case RETANGULO -> {
                gc.fillRect(figura.getX1(), figura.getY1(), figura.getLargura(), figura.getAltura());
                gc.strokeRect(figura.getX1(), figura.getY1(), figura.getLargura(), figura.getAltura());
            }
            case OVAL -> {
                gc.fillOval(figura.getX1(), figura.getY1(), figura.getLargura(), figura.getAltura());
                gc.strokeOval(figura.getX1(), figura.getY1(), figura.getLargura(), figura.getAltura());
            }
        }

        gc.setFill(Color.color(figura.getR(), figura.getG(), figura.getB()).darker());
        gc.fillText(figura.getTipoFigura().toString(), (figura.getX1()+ figura.getX2())/2,
                (figura.getY1()+figura.getY2())/2);
        gc.setTextAlign(TextAlignment.CENTER);
    }

    public void alteraDims(double width, double height) {
        setWidth(width);
        setHeight(height);
        atualiza();
    }
}
