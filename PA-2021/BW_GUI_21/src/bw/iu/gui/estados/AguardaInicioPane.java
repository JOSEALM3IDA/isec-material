package bw.iu.gui.estados;

import bw.logica.JogoObservavel;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;

import static bw.logica.Constantes.PROPRIEDADE_BOLAS;
import static bw.logica.Situacao.AGUARDA_INICIO;

public class AguardaInicioPane extends HBox {
    private JogoObservavel jogoObservavel;
    
    
    public AguardaInicioPane(JogoObservavel jogoObservavel) {
        this.jogoObservavel = jogoObservavel;
        criarVistaERegistarListeners();
        registarObservador();
        atualiza();
    }

    private void registarObservador(){
        // regista um observador do jogoObservavel
        jogoObservavel.addPropertyChangeListener(PROPRIEDADE_BOLAS, evt -> {
            atualiza();
        });
    }
    private void criarVistaERegistarListeners(){
        Button iniciarButton = new Button("Iniciar");

        setAlignment(Pos.CENTER);
        getChildren().add(iniciarButton);
        iniciarButton.setOnAction((e)->jogoObservavel.comecarJogo());
    }

    private void atualiza() {
        this.setVisible(jogoObservavel.getSituacaoAtual() ==  AGUARDA_INICIO );
    }
}
