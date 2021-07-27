package bw.iu.gui;

import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

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

public class PontuacaoPane extends GridPane {
    private JogoObservavel jogoObservavel;
    
    
    public PontuacaoPane(JogoObservavel jogoObservavel) {
        this.jogoObservavel = jogoObservavel;

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
    private  void criarVista() {
//       setMaxSize(DIM_X_SCORE, DIM_Y_SCORE);
        setPrefSize(DIM_X_PONTUACAO, DIM_Y_PONTUACAO);
//       setMinSize(DIM_X_SCORE, DIM_Y_SCORE);
        setBackground(new Background(
                new BackgroundFill(Color.WHITE, null, null)));
        setBorder(new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID,
                null, new BorderWidths(1))));

        this.setPadding(new Insets(10, 10, 10, 10));
        this.setAlignment(Pos.CENTER);
        this.setHgap(GAP_X_BOLAS);
        this.setVgap(GAP_Y_BOLAS);
    }

    private void atualiza(){
        int score = jogoObservavel.getPontuacao();
        int x = 0; int y = 0;

        this.getChildren().clear();

        for( int i = 0 ; i < score ; i++){

            if (x >= N_COL_PONTUACAO) {
                x = 0;
                y += 1;
            }
            ImageView imageView = new ImageView();
            imageView.setFitHeight(DIM_Y_BOLA);
            imageView.setFitWidth(DIM_X_BOLA);

            Image imagem = null;
            imagem = ImageLoader.getImage(BOLA_BRANCA);
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
