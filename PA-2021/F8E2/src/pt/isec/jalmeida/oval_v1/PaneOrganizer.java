package pt.isec.jalmeida.oval_v1;

import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import pt.isec.jalmeida.oval_v1.logica.Figura;


public class PaneOrganizer extends Pane {
    Figura figura;
    Ellipse ellipse;

    public PaneOrganizer(Figura figura) {
        this.figura = figura;
        criarLayout();
        registarListeners();
    }

    void criarLayout() {
        ellipse = new Ellipse(100, 100, 80, 50);
        ellipse.setFill(Color.GREEN);
        this.getChildren().add(ellipse);
    }

    void registarListeners() {
        this.addEventHandler(MouseEvent.MOUSE_PRESSED, e -> {
            figura.setP1(e.getX(), e.getY());
            figura.setP2(e.getX(), e.getY());
            figura.setRGB(Math.random(), Math.random(), Math.random());

            atualiza();
        });

        this.setOnMouseReleased(e -> {
            figura.setP2(e.getX(), e.getY());
            atualiza();
        });

        this.setOnMouseDragged(e -> {
            figura.setP2(e.getX(), e.getY());
            atualiza();
        });
    }

    void atualiza() {
        if (ellipse == null || figura == null) return;
        ellipse.setCenterX(figura.getCX());
        ellipse.setCenterY(figura.getCY());
        ellipse.setRadiusX(figura.getLargura() / 2);
        ellipse.setRadiusY(figura.getAltura() / 2);
        ellipse.setFill(Color.color(figura.getR(), figura.getG(), figura.getB()));
    }
}
