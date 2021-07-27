package bw.iu.gui;

import bw.iu.gui.estados.AguardaApostaPane;
import bw.iu.gui.estados.AguardaInicioPane;
import bw.iu.gui.estados.AguardaOpcaoPane;
import bw.iu.gui.estados.FinalJogoPane;
import bw.logica.JogoObservavel;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

import static bw.iu.gui.ConstantesGUI.*;
import static bw.logica.Constantes.PROPRIEDADE_BOLAS;

public class PrincipalPane extends BorderPane  {
    private JogoObservavel jogoObservavel;

    private Label sacoBolasLabel;
    private Label pontuacaoLabel;
    
    
    public PrincipalPane(JogoObservavel jogoObservavel) {
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
 
    private void criarVista(){
        
//        setMaxSize(DIM_X_FRAME, DIM_Y_FRAME);
        setPrefSize(DIM_X_FRAME, DIM_Y_FRAME);
        setMinSize(DIM_X_FRAME, DIM_Y_FRAME);

        setBorder(new Border(new BorderStroke(Color.BLUE, BorderStrokeStyle.SOLID,
                null, new BorderWidths(2))));

        // BOX ESQUERDA
        sacoBolasLabel =new Label("Saco de bolas");
        sacoBolasLabel.setFont(LETRA);

        SacoBolasPane sacoBolasPane = new SacoBolasPane(jogoObservavel);

        VBox leftBox = new VBox(10);

        leftBox.setPrefSize(LEFT_VBOX_X, LEFT_VBOX_Y);
        leftBox.setMinSize(LEFT_VBOX_X, LEFT_VBOX_Y);
        leftBox.setPadding(new Insets(10, 10, 10, 10));
        leftBox.getChildren().addAll(sacoBolasLabel, sacoBolasPane);

        // BOX DIREITA
        
        pontuacaoLabel =new Label("Pontuacao");
        pontuacaoLabel.setFont(LETRA);

        PontuacaoPane pontuacaoPane = new PontuacaoPane(jogoObservavel);

        Label bolasRemovidasLabel =new Label("Bolas removidas do jogo");
        bolasRemovidasLabel.setFont(LETRA);

        BolasRemovidasPane bolasRemovidasPane = new BolasRemovidasPane(jogoObservavel);

        VBox rightBox = new VBox(10);
        rightBox.setPadding(new Insets(10, 10, 10, 10));
        rightBox.getChildren().addAll(pontuacaoLabel, pontuacaoPane,  bolasRemovidasLabel, bolasRemovidasPane);

        // BOX CENTRAL ENVOLVENTE CONTENDO A ESQUERDA E A DIREITA
        HBox center = new HBox(10);
        center.setBorder(new Border(new BorderStroke(Color.DARKGRAY, BorderStrokeStyle.SOLID,
                null, new BorderWidths(2))));
        center.setAlignment(Pos.CENTER);
        center.getChildren().addAll(leftBox, rightBox);
        setCenter(center);

        // PAINEIS DOS ESTADOS
        AguardaInicioPane aguardaInicioPane = new AguardaInicioPane(jogoObservavel);
        AguardaApostaPane aguardaApostaPane = new AguardaApostaPane(jogoObservavel);
        AguardaOpcaoPane aguardaOpcaoPane = new AguardaOpcaoPane(jogoObservavel);
        FinalJogoPane finalJogoPane = new FinalJogoPane(jogoObservavel);

        // STACKPANE COM OS PAINEIS DOS ESTADOS
        StackPane bottom = new StackPane(aguardaInicioPane, aguardaApostaPane, aguardaOpcaoPane, finalJogoPane);
        bottom.setBorder(new Border(new BorderStroke(Color.DARKGRAY, BorderStrokeStyle.SOLID,
                null, new BorderWidths(2))));
        bottom.setPrefSize(DIM_X_BOTTOM_PANEL, DIM_Y_BOTTOM_PANEL);
        bottom.setMinSize(DIM_X_BOTTOM_PANEL, DIM_Y_BOTTOM_PANEL);

        setBottom(bottom);
    }

    
    private void atualiza() {
        int nb = jogoObservavel.getNBolasBrancasNoSaco();
        int np = jogoObservavel.getNBolasPretasNoSaco();

        sacoBolasLabel.setText("Bolas brancas: "+ nb + "   Bolas pretas: " + np);
        pontuacaoLabel.setText("Pontuacao: " + jogoObservavel.getPontuacao());
    }
}
