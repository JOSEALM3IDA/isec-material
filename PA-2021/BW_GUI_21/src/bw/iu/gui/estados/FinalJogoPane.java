package bw.iu.gui.estados;

import bw.logica.JogoObservavel;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;

import static bw.logica.Constantes.PROPRIEDADE_BOLAS;
import static bw.logica.Situacao.FINAL_JOGO;

public class FinalJogoPane extends HBox {
    private JogoObservavel jogoObservavel;
    private Label pontuacaoLabel;
    
    
    public FinalJogoPane(JogoObservavel jogoObservavel) {
        this.jogoObservavel = jogoObservavel;
               
        criarVistaERegistarListeners();
        registarObservador();
               
        atualiza();
       
    }
    private void registarObservador(){
        // regista um observador do jogoObservavel
        jogoObservavel.addPropertyChangeListener(PROPRIEDADE_BOLAS,evt -> {
            atualiza();
        });
    }
    private void criarVistaERegistarListeners(){
        pontuacaoLabel = new Label("Pontuacao final "+ jogoObservavel.getPontuacao()+ " ponto(s)");
        Button jogarNovamenteButton = new Button("Jogar novamente");
        
        setAlignment(Pos.CENTER);
        setSpacing(10);
        getChildren().addAll(pontuacaoLabel, jogarNovamenteButton);
        
        jogarNovamenteButton.setOnAction((e)->jogoObservavel.comecarJogo());
    }


    private void atualiza(){
        pontuacaoLabel.setText("Pontuacao final: "+ jogoObservavel.getPontuacao()+ " point(s)");
        this.setVisible(jogoObservavel.getSituacaoAtual() ==  FINAL_JOGO );
    }
}
