package labirintojfx.ui.grafica;

import javafx.scene.Parent;
import javafx.scene.layout.*;
import labirintojfx.logica.LabirintoGameObs;

public class LabUIGrafica {

    private VistaConfigura aguardaConfigura;
    private VistaMovimento aguardaMovimento;
    private VistaFinal aguardaFinal;

    private StackPane rootPane;

    private LabirintoGameObs gameObs;

    public LabUIGrafica(LabirintoGameObs g) {
        gameObs = g;
        criarComponentes();
        disporVista();
        registarListeners();
    }

    public Parent obtemRootPane() {
        return rootPane;
    }

    private void criarComponentes() {
        rootPane = new StackPane();
        aguardaConfigura = new VistaConfigura(gameObs);
        aguardaMovimento = new VistaMovimento(gameObs);
        aguardaFinal = new VistaFinal(gameObs);
    }

    private void disporVista() {
        // presume um determinado estado inicial
        // resolver isto no gameObs
        aguardaConfigura.setVisible(true);
        aguardaMovimento.setVisible(false);
        aguardaFinal.setVisible(false);
        rootPane.getChildren().addAll(aguardaConfigura, aguardaMovimento, aguardaFinal);
    }

    private void registarListeners() {
        // Regista Listeners -------------------
        // mudanca de estado -> cada vista regista-se e faz o que quer.
        // listener de movimento -> a vista do estado de movimento que se registe e trate disso
        // listener de botões etc -> quais botões etc? cada vista que trate de si
        // Não sobra nada para esta fazer aqui - talvez um listener para redimensionamento
        // Aqui, faria sentido, se houvesse, configurar menus
    }


}