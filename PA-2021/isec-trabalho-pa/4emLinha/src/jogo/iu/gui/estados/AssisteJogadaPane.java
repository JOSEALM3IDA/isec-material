package jogo.iu.gui.estados;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import jogo.iu.gui.resources.MusicPlayer;
import jogo.iu.gui.stage.JogadorInfoBox;
import jogo.iu.gui.stage.menu.FooterBox;
import jogo.iu.gui.stage.menu.MenuBarJogo;
import jogo.iu.gui.stage.menu.button.NormalMenuButton;
import jogo.iu.gui.stage.tabuleiro.TabuleiroPane;
import jogo.logica.Propriedade;
import jogo.logica.QuatroEmLinhaObservable;
import jogo.logica.command.TipoJogada;
import jogo.logica.estados.Situacao;
import jogo.utils.Constantes;

public class AssisteJogadaPane extends BorderPane {
    private final QuatroEmLinhaObservable observable;

    private MenuBarJogo menuBarJogo;

    private TabuleiroPane tabuleiroPane;

    private Text listaJogadores;
    private JogadorInfoBox jogadorInfoBox;

    private Text infoJogadaText;
    private NormalMenuButton avancarButton;

    public AssisteJogadaPane(QuatroEmLinhaObservable observable) {
        this.observable = observable;
        criarLayout();
        registarListeners();
        registarObservadores();
        atualizarVisibilidade();
    }

    private void criarLayout() {
        setBackground(new Background(new BackgroundFill(Color.web(Constantes.BACKGROUND_COLOR_HEX), CornerRadii.EMPTY, Insets.EMPTY)));

        HBox listaBox = new HBox();
        listaJogadores = new Text();
        listaJogadores.setTextAlignment(TextAlignment.CENTER);
        listaJogadores.setFill(Color.WHITE);
        listaJogadores.setStyle("-fx-font-size: 20");
        listaBox.setAlignment(Pos.CENTER);
        listaBox.setPadding(new Insets(100));
        listaBox.getChildren().add(listaJogadores);
        listaBox.setMinWidth(Constantes.LARG_SIDEBAR); listaBox.setMaxWidth(Constantes.LARG_SIDEBAR);
        setLeft(listaBox);

        tabuleiroPane = new TabuleiroPane(observable);
        setCenter(tabuleiroPane);

        jogadorInfoBox = new JogadorInfoBox(observable);
        setRight(jogadorInfoBox);

        menuBarJogo = new MenuBarJogo(observable);
        setTop(menuBarJogo);

        FooterBox footerBox = new FooterBox();
        BorderPane footerPane = new BorderPane();
        footerPane.setMinWidth(footerBox.getMinWidth());
        footerPane.setPadding(new Insets(28, 50, 0, 50));

        avancarButton = new NormalMenuButton("Avançar");
        footerPane.setRight(avancarButton);

        infoJogadaText = new Text();
        infoJogadaText.setStyle("-fx-font-size: 22; -fx-fill: white");
        footerPane.setLeft(infoJogadaText);

        footerBox.getChildren().addAll(footerPane);

        setBottom(footerBox);
    }

    void registarListeners() {
        avancarButton.setOnAction(e -> {
            infoJogadaText.setText(observable.getDescricaoComandoAtual());
            executarSomJogada(observable.getTipoJogadaAtual());
            observable.avancar();
        });

        setOnKeyReleased(e -> {
            if (e.getCode() != KeyCode.ENTER) return;
            avancarButton.fire();
        });
    }

    private void registarObservadores() {
        observable.addPropertyChangeListener(Propriedade.ATUALIZAR_LISTA_JOGADORES, evt -> atualizarListaJogadores());
        observable.addPropertyChangeListener(Propriedade.COMECAR_REPLAY, evt -> resetInfoReplay());
        observable.addPropertyChangeListener(Propriedade.ATUALIZAR_ESTADO, evt -> atualizarVisibilidade());
    }

    private void executarSomJogada(TipoJogada tipoJogada) {
        String som = switch (tipoJogada) {
            case JOGAR_FICHA -> Constantes.SOM_FICHA_DROP;
            case JOGAR_FICHA_ESPECIAL -> Constantes.SOM_FICHA_ESPECIAL;
            case PERDER_MINIJOGO -> Constantes.SOM_PERDE_MINIJOGO;
            case GANHAR_MINIJOGO -> Constantes.SOM_GANHA_MINIJOGO;
            case NONE -> null;
        };

        if (som == null) return;

        MusicPlayer.playMusic(som);
    }

    private void atualizarListaJogadores() { listaJogadores.setText(observable.getConfigJogadores()); }

    private void resetInfoReplay() {
        infoJogadaText.setText("");
        jogadorInfoBox.setVisible(false);
    }

    private void atualizarVisibilidade() { this.setVisible(observable.getSituacao() == Situacao.AssisteJogada); }
}
