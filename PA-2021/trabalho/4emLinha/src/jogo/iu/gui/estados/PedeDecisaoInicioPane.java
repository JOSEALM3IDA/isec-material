package jogo.iu.gui.estados;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.FileChooser;
import jogo.iu.gui.resources.FontManager;
import jogo.iu.gui.stage.menu.button.MainMenuButton;
import jogo.iu.gui.stage.menu.MenuBackground;
import jogo.logica.Propriedade;
import jogo.logica.QuatroEmLinhaObservable;
import jogo.logica.estados.Situacao;
import jogo.utils.Constantes;

import java.io.File;

public class PedeDecisaoInicioPane extends BorderPane {
    private final QuatroEmLinhaObservable observable;

    private Text tituloText;

    private MainMenuButton iniciarButton;
    private MainMenuButton continuarButton;
    private MainMenuButton replayButton;
    private MainMenuButton sairButton;

    public PedeDecisaoInicioPane(QuatroEmLinhaObservable observable) {
        this.observable = observable;
        criarLayout();
        registarListeners();
        registarObservadores();
        atualizarVisibilidade();
    }

    void criarLayout() {
        VBox verticalBox = new VBox(100);
        verticalBox.setId("side-box");
        verticalBox.setBackground(new Background(new BackgroundFill(
                Color.web(Constantes.COR_AZUL_HEX),
                CornerRadii.EMPTY, Insets.EMPTY)));

        tituloText = new Text("QUATRO\nEM\nLINHA");
        tituloText.setTextAlignment(TextAlignment.CENTER);
        tituloText.setFill(Color.WHITE);
        tituloText.setStroke(Color.BLACK);
        tituloText.setStrokeWidth(1);
        tituloText.setFont(FontManager.loadFont(Constantes.FONT_MENU, 40));
        tituloText.setLineSpacing(-20);

        VBox buttonBox = new VBox(15);

        iniciarButton = new MainMenuButton("Iniciar Jogo");
        continuarButton = new MainMenuButton("Continuar Jogo");
        replayButton = new MainMenuButton("Ver Replay");
        sairButton = new MainMenuButton("Sair");

        buttonBox.getChildren().addAll(iniciarButton, continuarButton, replayButton, sairButton);

        buttonBox.setAlignment(Pos.CENTER);

        verticalBox.getChildren().addAll(tituloText, buttonBox);

        verticalBox.setAlignment(Pos.CENTER);
        verticalBox.setPadding(new Insets(50));

        verticalBox.setMaxWidth(Constantes.LARG_SIDEBAR);
        verticalBox.setMinWidth(Constantes.LARG_SIDEBAR);

        setRight(verticalBox);
        setLeft(new MenuBackground());
    }

    void registarListeners() {
        iniciarButton.setOnAction(e -> observable.iniciarJogo());

        continuarButton.setOnAction(e -> {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Escolher Save");
            fileChooser.setInitialDirectory(new File(Constantes.SAVE_PATH));
            fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Todos", "*.*"));
            File hFile = fileChooser.showOpenDialog(getScene().getWindow());
            if (hFile != null) { observable.continuarJogo(hFile.getAbsolutePath()); }
        });

        replayButton.setOnAction(e -> {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Escolher Replay");
            fileChooser.setInitialDirectory(new File(Constantes.REPLAY_PATH));
            fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Todos", "*.*"));
            File hFile = fileChooser.showOpenDialog(getScene().getWindow());
            if (hFile != null) { observable.verReplay(hFile.getAbsolutePath()); }
        });

        sairButton.setOnAction(e -> Platform.exit());
    }

    private void registarObservadores() { observable.addPropertyChangeListener(Propriedade.ATUALIZAR_ESTADO, evt -> atualizarVisibilidade()); }

    private void atualizarVisibilidade() { this.setVisible(observable.getSituacao() == Situacao.PedeDecisaoInicio); }
}
