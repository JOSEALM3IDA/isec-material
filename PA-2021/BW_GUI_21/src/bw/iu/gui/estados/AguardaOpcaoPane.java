package bw.iu.gui.estados;

import bw.logica.JogoObservavel;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.RadioButton;
import javafx.scene.control.Toggle;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.HBox;

import static bw.logica.Constantes.PROPRIEDADE_BOLAS;
import static bw.logica.Situacao.AGUARDA_OPCAO;

public class AguardaOpcaoPane extends HBox {
    private JogoObservavel jogoObservavel;
    
    private RadioButton perderPontRadioButton;
    private RadioButton remover2BolasRadioButton;
    private ToggleGroup radioGroup;
    private Button escolherOpcao;
    
    
    public AguardaOpcaoPane(JogoObservavel jogoObservavel) {
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
        perderPontRadioButton = new RadioButton("Perder um ponto");
        remover2BolasRadioButton = new RadioButton("Remover duas bolas do saco");
        escolherOpcao = new Button("Escolher Opcao");
        
        radioGroup = new ToggleGroup();
        radioGroup.getToggles().addAll(perderPontRadioButton, remover2BolasRadioButton);
        
        
        setAlignment(Pos.CENTER);
        setSpacing(10);
        getChildren().addAll(perderPontRadioButton, remover2BolasRadioButton, escolherOpcao);
      //  remover2BolasRadioButton.setSelected(true);

        escolherOpcao.setOnAction((e)->{
            if(perderPontRadioButton.isSelected()){
                jogoObservavel.escolherOpcaoPerderPontuacao();
            } else if(remover2BolasRadioButton.isSelected()){
                jogoObservavel.escolherOpcaoRetirarDuasBolas();
            }
        });
     }
    
    private void atualiza() {
        Toggle toggle = radioGroup.getSelectedToggle();
        if(toggle != null){
            toggle.setSelected(false);
        }
        if(jogoObservavel.getPontuacao() == 0){
            perderPontRadioButton.setDisable(true);
            remover2BolasRadioButton.setSelected(true);
        }
        perderPontRadioButton.setDisable(!(jogoObservavel.getPontuacao()>0));

        if (jogoObservavel.getSituacaoAtual() == AGUARDA_OPCAO) {
            if (jogoObservavel.getPontuacao() > 0) {
                perderPontRadioButton.setSelected(true);
            } else {
                remover2BolasRadioButton.setSelected(true);
            }
        }
        this.setVisible(jogoObservavel.getSituacaoAtual() ==  AGUARDA_OPCAO );
    }
}
