package labirintojfx.ui.grafica;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import labirintojfx.logica.LabirintoGameObs;
import labirintojfx.logica.PropsID;
import labirintojfx.logica.Situacao;

import java.util.List;

class VistaMovimento extends Canvas {
    private LabirintoGameObs gameObs;
    private GraphicsContext gc;

    public VistaMovimento(LabirintoGameObs g) {
        super(320,240);  // valors martelados - usar binding para melhorar isto
        gameObs = g;            // (o gajo do github que faça isso)
        criarComponentes();
        disporVista();
        registarListeners();

        gameObs.registaPropertyChangeListener(
                PropsID.PROP_ESTADO,
                (e) -> {
                    if (gameObs.getSituacao() == Situacao.AGUARDA_MOVIMENTO) {
                        this.setVisible(true);
                        desenhaMapa();
                        requestFocus();
                    }
                    else
                        this.setVisible(false);
                } );
        gameObs.registaPropertyChangeListener(PropsID.PROP_MOVE,
                (e) -> {
                    if (gameObs.getSituacao() == Situacao.AGUARDA_MOVIMENTO)
                        desenhaMapa();
                });

    }

    public void criarComponentes() {
        gc = getGraphicsContext2D();
    }

    public void disporVista() {
        // Não há nada a configurar aqui
    }

    public void registarListeners() {
        setOnKeyPressed( (e) -> {
            switch (e.getCode()) {
                case UP -> { gameObs.up(); }
                case DOWN -> { gameObs.down(); }
                case LEFT -> { gameObs.left(); }
                case RIGHT -> { gameObs.right(); }
            }
        });
    }

    private void desenhaMapa() {
        gc = getGraphicsContext2D();

        gc.setFill(Color.BLANCHEDALMOND);
        gc.setLineWidth(0);
        gc.setFill(Color.BLUE);
        List<String> mapavis = gameObs.getVisibleMap();
        for (int l = 0; l < mapavis.size(); ++l) {
            String s = mapavis.get(l);
            for (int c = 0; c < s.length(); ++c) {
                switch (s.charAt(c)) {
                    case '.' -> {
                        gc.setFill(Color.DARKSALMON);
                        gc.fillRect(c * 16, l * 16, 16, 16);
                    }
                    case '#' -> {
                        gc.setFill(Color.BLACK);
                        gc.fillRect(c * 16, l * 16, 16, 16);
                    }
                    case ' ' -> {
                        gc.setFill(Color.BLANCHEDALMOND);
                        gc.fillRect(c * 16, l * 16, 16, 16);
                    }
                    case 'X' -> {
                        gc.setFill(Color.BLUE);
                        gc.fillOval(c * 16, l * 16, 16, 16);
                    }
                }
            }
            System.out.println(s);
        }
    }

}
