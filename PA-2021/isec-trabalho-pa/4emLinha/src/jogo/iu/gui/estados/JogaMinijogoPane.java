package jogo.iu.gui.estados;

import javafx.event.Event;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.TextField;
import javafx.scene.input.ContextMenuEvent;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import jogo.logica.Propriedade;
import jogo.logica.QuatroEmLinhaObservable;
import jogo.logica.estados.Situacao;
import jogo.utils.Constantes;

public class JogaMinijogoPane extends BorderPane {
    private final QuatroEmLinhaObservable observable;

    private Text infoText;
    private TextField respostaTextField;

    public JogaMinijogoPane(QuatroEmLinhaObservable observable) {
        this.observable = observable;
        criarLayout();
        registarListeners();
        registarObservadores();
        atualizarVisibilidade();
    }

    void criarLayout() {
        setBackground(new Background(new BackgroundFill(Color.web(Constantes.COR_AZUL_HEX), CornerRadii.EMPTY, Insets.EMPTY)));

        VBox minijogoBox = new VBox(30);
        infoText = new Text();
        infoText.setId("minijogo-info");

        respostaTextField = new TextField();
        respostaTextField.setId("minijogo-textfield");
        respostaTextField.setAlignment(Pos.CENTER);
        respostaTextField.addEventFilter(ContextMenuEvent.CONTEXT_MENU_REQUESTED, Event::consume);

        minijogoBox.setAlignment(Pos.CENTER);
        minijogoBox.getChildren().addAll(infoText, respostaTextField);

        setCenter(minijogoBox);
    }

    void registarListeners() {
        respostaTextField.setOnKeyReleased(e -> {
            if (e.getCode() != KeyCode.ENTER) return;

            observable.enviarRespostaMinijogo(respostaTextField.getText());
            respostaTextField.setText("");
        });
    }

    private void registarObservadores() {
        observable.addPropertyChangeListener(Propriedade.ATUALIZAR_PERGUNTA_MINIJOGO, evt -> atualizarPerguntaMinijogo());
        observable.addPropertyChangeListener(Propriedade.ATUALIZAR_ESTADO, evt -> atualizarVisibilidade());
    }

    private void atualizarPerguntaMinijogo() { infoText.setText(observable.getPerguntaMinijogo()); }

    private void atualizarVisibilidade() { this.setVisible(observable.getSituacao() == Situacao.JogaMinijogo); }
}
