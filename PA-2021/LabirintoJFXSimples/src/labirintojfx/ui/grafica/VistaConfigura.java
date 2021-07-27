package labirintojfx.ui.grafica;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import labirintojfx.logica.LabirintoGameObs;
import labirintojfx.logica.PropsID;
import labirintojfx.logica.Situacao;

class VistaConfigura extends BorderPane {
    private LabirintoGameObs gameObs;
    private TextField tfNome;
    private TextField tfDificuldade;
    private Button btAvancar;

    public VistaConfigura(LabirintoGameObs g) {
        gameObs = g;
        criarComponentes();
        disporVista();
        registarListeners();

        gameObs.registaPropertyChangeListener(
                PropsID.PROP_ESTADO,
                (e) -> { this.setVisible(gameObs.getSituacao() == Situacao.AGUARDA_CONFIG); } );
    }

    public void criarComponentes() {
        tfNome = new TextField();
        tfDificuldade = new TextField();
        btAvancar = new Button("Avançar");
    }

    public void disporVista() {
        // estes tres componentes têm visibilidade interna a esta função - não servem para mais nada
        Pane pnTopPane = new Pane();
        Label lbTitle = new Label("Labirinto Game");
        GridPane gpConfigura = new GridPane();
        // topo: o título
        lbTitle.setAlignment(Pos.CENTER);
        pnTopPane.getChildren().add(lbTitle);
        // centro: botões e text field
        gpConfigura.setPadding(new Insets(25,25,25,25));
        //gpConfigura.setStyle("-fx-padding 25 25 25 25");
        gpConfigura.setAlignment(Pos.CENTER);
        gpConfigura.setVgap(10);
        gpConfigura.setHgap(10);
        gpConfigura.add(new Label("Configura isso"),0,0);
        gpConfigura.add(new Label("Nome:"), 0,2);
        gpConfigura.add(tfNome, 1,2);
        gpConfigura.add(new Label("Dificuldade:"), 0,3);
        gpConfigura.add(tfDificuldade, 1,3);
        gpConfigura.add(btAvancar,1,5);
        setTop(pnTopPane);
        setCenter(gpConfigura);
    }

    public void registarListeners() {
        btAvancar.setOnAction((e) -> {
            if (tfDificuldade.getText().matches("[0-9]+"))
                gameObs.configura(tfNome.getText(), Integer.parseInt(tfDificuldade.getText()));
            else
                tfDificuldade.setText("");
        } );
    }

}
