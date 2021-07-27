package labirintojfx.ui.grafica;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import labirintojfx.logica.LabirintoGameObs;
import labirintojfx.logica.PropsID;
import labirintojfx.logica.Situacao;

class VistaFinal extends VBox {
    private LabirintoGameObs gameObs;
    private Label lbParabens;
    Button btRecomeca;

    public VistaFinal(LabirintoGameObs g) {
        gameObs = g;
        criarComponentes();
        disporVista();
        registarListeners();

        gameObs.registaPropertyChangeListener(
                PropsID.PROP_ESTADO,
                (e) -> {
                    if (gameObs.getSituacao() == Situacao.AGUARDA_FINAL) {
                        this.setVisible(true);
                        if (lbParabens != null)
                            lbParabens.setText("Parabéns, " + gameObs.getNomeJogador());
                    }
                    else
                        this.setVisible(false);
                } );
    }

    private void criarComponentes() {
        lbParabens = new Label();
        btRecomeca = new Button("Recomeçar");
    }

    private void disporVista() {
        setAlignment(Pos.CENTER);
        setPadding(new Insets(25, 25, 25, 25));
        setSpacing(35);
        lbParabens.setAlignment(Pos.CENTER);
        getChildren().addAll(lbParabens, btRecomeca);

    }

    private void registarListeners() {
        btRecomeca.setOnAction( (e) -> { gameObs.recomeca(); } );
    }

}
