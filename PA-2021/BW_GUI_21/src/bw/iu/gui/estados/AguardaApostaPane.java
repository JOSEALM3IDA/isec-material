package bw.iu.gui.estados;

import bw.logica.JogoObservavel;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;

import static bw.logica.Constantes.PROPRIEDADE_BOLAS;
import static bw.logica.Situacao.AGUARDA_APOSTA;

public class AguardaApostaPane extends HBox {
    private JogoObservavel jogoObservavel;
    private TextField apostaTextField;
    private Button apostarERetirarBolaButton;
    private Button terminarButton;
    private Label pontuacaoLabel;
    
    
    public AguardaApostaPane(JogoObservavel jogoObservavel) {
        this.jogoObservavel = jogoObservavel;
        criarVista();
        registarObservador();
        registarListeners();
        atualiza();
        
    }
    private void registarObservador(){
        // regista um observador do jogoObservavel
        jogoObservavel.addPropertyChangeListener(PROPRIEDADE_BOLAS, evt -> {
            atualiza();
        });
    }
    private void criarVista(){
        pontuacaoLabel = new Label("Valor a apostar [0" +
                (jogoObservavel.getPontuacao()>0 ? " - " + jogoObservavel.getPontuacao():"")+ "]");
        apostaTextField = new TextField("  ");
        apostaTextField.setMaxWidth(50);
        apostarERetirarBolaButton = new Button("Apostar e tirar uma bola do saco");
        terminarButton = new Button("Terminar");

        setAlignment(Pos.CENTER);
        setSpacing(10);
        getChildren().addAll(pontuacaoLabel, apostaTextField, apostarERetirarBolaButton, terminarButton);
    }

    private void registarListeners(){
        apostarERetirarBolaButton.setOnAction(new ApostarListener());

        terminarButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                jogoObservavel.terminar();
            }
        });
    }

    private void atualiza() {
        pontuacaoLabel.setText("Valor a apostar [0" +
            (jogoObservavel.getPontuacao()>0?" - " + jogoObservavel.getPontuacao():"")+ "]");
         apostaTextField.setText("0");
         this.setVisible(jogoObservavel.getSituacaoAtual() ==  AGUARDA_APOSTA );
         if (jogoObservavel.getSituacaoAtual() == AGUARDA_APOSTA)
             apostaTextField.requestFocus();
    }
    
    private class ApostarListener implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent e){
            
            int value = 0;
            
            try {
                value = getValue();
            } catch (NumberFormatException ex){
                return;
            }
            
            if (value >= 0){
                jogoObservavel.apostar(value);
            }
            
        }
        
    }

    private int getValue() throws NumberFormatException {
        
        String s1 = (apostaTextField.getText()).trim();
        
        if (s1.length() < 1){
            throw new NumberFormatException();
        }      
        int value = Integer.parseInt(s1);   
        return value;
    
    }
}
