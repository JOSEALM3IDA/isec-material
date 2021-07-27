package bw.iu.gui;

import bw.iu.gui.resources.ImageLoader;
import bw.logica.JogoObservavel;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

import static bw.iu.gui.ConstantesGUI.*;
import static bw.logica.Constantes.PROPRIEDADE_BOLAS;

public class BolasRemovidasPane extends GridPane {
    private JogoObservavel jogoObservavel;
    
    
    public BolasRemovidasPane(JogoObservavel jogoObservavel) {
        this.jogoObservavel = jogoObservavel;
        criarVista();
        registarObservador();
        atualiza();
    }

    private  void criarVista() {
//        setMaxSize(REMOVED_BALLS_X, REMOVED_BALLS_Y);
        setPrefSize(BOLAS_REMOVIDAS_X, BOLAS_REMOVIDAS_Y);
//        setMinSize(REMOVED_BALLS_X, REMOVED_BALLS_Y);
        setBorder(new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID,
                null, new BorderWidths(1))));
        setBackground(new Background(
                new BackgroundFill(Color.LIGHTGREY, null, null)));
        this.setPadding(new Insets(10, 10, 10, 10));
        this.setAlignment(Pos.CENTER);
        this.setHgap(GAP_X_BOLAS);
        this.setVgap(GAP_Y_BOLAS);
    }

    private void registarObservador(){
        // regista um observador do jogoObservavel
        jogoObservavel.addPropertyChangeListener(PROPRIEDADE_BOLAS, evt -> {
            atualiza();
        });
    }
    
    private void atualiza() {

        int nBrancasRemovidas = jogoObservavel.getNBrancasRemovidas();
        int nPretasRemovidas = jogoObservavel.getNPretasRemovidas();

        int x = 0; int y = 0;

        this.getChildren().clear();
        
        for (int i = 0; i < nBrancasRemovidas; i++) {

            if (x >= N_COL_PONTUACAO) {
                x = 0;
                y += 1;
            }
            ImageView imageView = new ImageView();
            imageView.setFitHeight(DIM_Y_BOLA);
            imageView.setFitWidth(DIM_X_BOLA);

            Image imagem = ImageLoader.getImage(BOLA_BRANCA);
            if (imagem != null) {
                imageView.setImage(imagem);
            } else {
                System.err.println(" imagem = null");
            }
            add(imageView, x, y);
            x += 1;

        }

        x = 0;
        y += 1;

        for (int i = 0; i < nPretasRemovidas; i++) {

            if (x >= N_COL_PONTUACAO) {
                x = 0;
                y += 1;
            }
            ImageView imageView = new ImageView();
            imageView.setFitHeight(DIM_Y_BOLA);
            imageView.setFitWidth(DIM_X_BOLA);

            Image imagem = ImageLoader.getImage(BOLA_PRETA);
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
