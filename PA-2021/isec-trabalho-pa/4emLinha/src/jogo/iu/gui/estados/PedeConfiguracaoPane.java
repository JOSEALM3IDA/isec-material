package jogo.iu.gui.estados;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import jogo.iu.gui.resources.FontManager;
import jogo.iu.gui.stage.menu.MenuBackground;
import jogo.iu.gui.stage.menu.button.NormalMenuButton;
import jogo.logica.Propriedade;
import jogo.logica.QuatroEmLinhaObservable;
import jogo.logica.dados.jogadores.TipoJogador;
import jogo.logica.estados.Situacao;
import jogo.utils.Constantes;

public class PedeConfiguracaoPane extends BorderPane {
    private final QuatroEmLinhaObservable observable;

    private Text configText;

    private Text infoText;

    private Text jogadorAtualText;
    private Text nomeText;
    private TextField nomeField;
    private ComboBox<TipoJogador> tipoJogadorCombobox;
    private Text erroText;
    private NormalMenuButton adicionarButton;
    private NormalMenuButton voltarButton;

    public PedeConfiguracaoPane(QuatroEmLinhaObservable observable) {
        this.observable = observable;
        criarLayout();
        registarListeners();
        registarObservadores();
        atualizarVisibilidade();
    }

    private VBox getBoxConfig() {
        VBox configBox = new VBox(100);
        configBox.setId("side-box");
        configBox.setBackground(new Background(new BackgroundFill(
                Color.web(Constantes.COR_AZUL_HEX),
                CornerRadii.EMPTY, Insets.EMPTY)));

        configText = new Text("Configuração");
        configText.setFont(FontManager.loadFont(Constantes.FONT_MENU, 24));
        configText.setFill(Color.WHITE);
        configText.setStroke(Color.BLACK);
        configText.setStrokeWidth(1);
        configBox.setAlignment(Pos.CENTER);

        infoText = new Text();
        infoText.setFill(Color.WHITE);
        infoText.setStyle("-fx-font-size: 20");
        infoText.setTextAlignment(TextAlignment.CENTER);

        VBox buttonBox = new VBox(15);

        jogadorAtualText = new Text();
        jogadorAtualText.setFill(Color.WHITE);
        jogadorAtualText.setStyle("-fx-font-weight: bold");
        jogadorAtualText.setStyle("-fx-font-size: 20");

        VBox nomeBox = new VBox(5);
        nomeText = new Text("Nome");
        nomeText.setFill(Color.WHITE);

        HBox nomeTipoBox = new HBox(10);

        nomeField = new TextField();

        tipoJogadorCombobox = new ComboBox<>();
        tipoJogadorCombobox.getItems().addAll(TipoJogador.values());
        tipoJogadorCombobox.setMinWidth(130);

        nomeTipoBox.getChildren().addAll(nomeField, tipoJogadorCombobox);
        nomeTipoBox.setAlignment(Pos.CENTER);

        nomeBox.getChildren().addAll(nomeText, nomeTipoBox);
        nomeBox.setPadding(new Insets(50));

        erroText = new Text();
        erroText.setFill(Color.RED);
        erroText.setStroke(Color.RED);
        erroText.setStrokeWidth(1);
        erroText.setStyle("-fx-font-size: 12");

        VBox vBox = new VBox(15);
        adicionarButton = new NormalMenuButton("Adicionar Jogador");
        voltarButton = new NormalMenuButton("Voltar");
        vBox.getChildren().addAll(adicionarButton, voltarButton);
        vBox.setAlignment(Pos.CENTER);

        buttonBox.getChildren().addAll(jogadorAtualText, nomeBox, erroText, vBox);
        buttonBox.setAlignment(Pos.CENTER);

        configBox.getChildren().addAll(configText, infoText, buttonBox);

        configBox.setMaxWidth(Constantes.LARG_SIDEBAR);
        configBox.setMinWidth(Constantes.LARG_SIDEBAR);
        return configBox;
    }

    private void criarLayout() {
        setLeft(new MenuBackground());
        setRight(getBoxConfig());
    }

    private void registarListeners() {
        adicionarButton.setOnAction(e -> {
            String nomeJogador = nomeField.getText();
            TipoJogador tipoJogador = tipoJogadorCombobox.getSelectionModel().getSelectedItem();

            if (nomeJogador.isBlank()) {
                erroText.setText("O nome do jogador não pode estar vazio!");
                return;
            }

            if (observable.existeJogador(nomeJogador)) {
                erroText.setText("Esse nome já está a ser utilizado!");
                return;
            }

            observable.adicionarJogador(tipoJogador, nomeJogador);
            erroText.setText("");
        });

        voltarButton.setOnAction(e -> observable.voltar());

        setOnKeyReleased(e -> {
            if (e.getCode() != KeyCode.ENTER) return;
            adicionarButton.fire();
        });
    }

    private void registarObservadores() {
        observable.addPropertyChangeListener(Propriedade.ATUALIZAR_LISTA_JOGADORES, evt -> atualizarListaJogadores());
        observable.addPropertyChangeListener(Propriedade.ATUALIZAR_ESTADO, evt -> atualizarVisibilidade());
    }

    private void atualizarListaJogadores() {
        nomeField.setText("");
        nomeField.requestFocus();
        tipoJogadorCombobox.getSelectionModel().select(TipoJogador.HUMANO);
        jogadorAtualText.setText("Jogador " + (observable.getNumJogadores() + 1));
        infoText.setText(observable.getConfigJogadores());
    }

    private void atualizarVisibilidade() { this.setVisible(observable.getSituacao() == Situacao.PedeConfiguracao); }
}
