package bw.iu.gui;

import bw.iu.gui.resources.ImageLoader;
import bw.logica.JogoObservavel;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

import java.util.List;

import static bw.iu.gui.ConstantesGUI.*;
import static bw.logica.Constantes.PROPRIEDADE_BOLAS;
public class SacoBolasPane extends GridPane {

    private JogoObservavel jogoObservavel;

    public SacoBolasPane(JogoObservavel jogoObservavel) {
        this.jogoObservavel = jogoObservavel; this.
        criarVista();
        registarObservador();
        atualiza();
    }

    private void registarObservador(){
        // regista um observador do jogoObservavel
        jogoObservavel.addPropertyChangeListener(PROPRIEDADE_BOLAS, evt -> {
            atualiza();
        });
    }

    private void criarVista(){
//        setMaxSize(DIM_X_BAG, DIM_Y_BAG);
        setPrefSize(DIM_X_SACO, DIM_Y_SACO);
//        setMinSize(DIM_X_BAG, DIM_Y_BAG);
        setBorder(new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID,
                null, new BorderWidths(1))));

        setBackground(new Background(
                new BackgroundFill(Color.GREY, null, null)));

        this.setPadding(new Insets(30, 30, 30, 30));
        this.setAlignment(Pos.CENTER);
        this.setHgap(GAP_X_BOLAS);
        this.setVgap(GAP_Y_BOLAS);
    }

    private void atualiza() {

        List<String> bag = jogoObservavel.getSaco();

        this.getChildren().clear();

        int x = 0; int y = 0;
        for (String bola : bag) {

            if (x >= N_COL_SACO) {
                x = 0;
                y += 1;
            }

            ImageView imageView = new ImageView();
            imageView.setFitHeight(DIM_Y_BOLA);
            imageView.setFitWidth(DIM_X_BOLA);
            Image imagem = null;
            if (bola.equals("B")) {
                imagem = ImageLoader.getImage(BOLA_BRANCA);
            } else if (bola.equals("P")) {
                imagem = ImageLoader.getImage(BOLA_PRETA);
            }
            if (imagem != null) {
                imageView.setImage(imagem);
            } else {
                System.err.println(" imagem = null");
            }
            add(imageView, x, y);
            x += 1;
        }
    }
}
