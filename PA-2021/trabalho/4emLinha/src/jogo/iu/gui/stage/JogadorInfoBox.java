package jogo.iu.gui.stage;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import jogo.logica.Propriedade;
import jogo.logica.QuatroEmLinhaObservable;
import jogo.utils.Constantes;

public class JogadorInfoBox extends VBox {
    private Text jogadorAtualText;
    private Text nomeJogadorAtualText;
    private Text creditosText;
    private Text fichasEspeciaisText;

    private final QuatroEmLinhaObservable observable;

    public JogadorInfoBox(QuatroEmLinhaObservable observable) {
        this.observable = observable;

        criarLayout();
        registarObservadores();
    }

    private void criarLayout() {
        jogadorAtualText = new Text("Jogador Atual:");
        jogadorAtualText.setStyle("-fx-font-size: 20");
        jogadorAtualText.setTextAlignment(TextAlignment.CENTER);
        jogadorAtualText.setFill(Color.WHITE);

        nomeJogadorAtualText = new Text();
        nomeJogadorAtualText.setStyle("-fx-font-size: 28; -fx-font-weight: bold");
        nomeJogadorAtualText.setStroke(Color.BLACK);
        nomeJogadorAtualText.setStrokeWidth(1);

        creditosText = new Text();
        creditosText.setStyle("-fx-font-size: 20");
        creditosText.setTextAlignment(TextAlignment.CENTER);
        creditosText.setFill(Color.WHITE);

        fichasEspeciaisText = new Text();
        fichasEspeciaisText.setStyle("-fx-font-size: 20");
        fichasEspeciaisText.setTextAlignment(TextAlignment.CENTER);
        fichasEspeciaisText.setFill(Color.WHITE);

        setAlignment(Pos.CENTER);
        getChildren().addAll(jogadorAtualText, nomeJogadorAtualText, creditosText, fichasEspeciaisText);
        setPadding(new Insets(100));
        setMinWidth(Constantes.LARG_SIDEBAR); setMaxWidth(Constantes.LARG_SIDEBAR);

    }

    private void atualizar() {
        if (!isVisible()) setVisible(true);

        nomeJogadorAtualText.setText(observable.getNomeJogadorAtual());
        creditosText.setText("Creditos: " + observable.getNumCreditos());
        fichasEspeciaisText.setText("Fichas Especiais: " + observable.getNumFichasEspeciaisJogadorAtual());
        nomeJogadorAtualText.setFill(Color.web(switch (observable.getFichaAtual()) {
            case FICHA_VERMELHA -> Constantes.COR_VERMELHA_HEX;
            case FICHA_AMARELA -> Constantes.COR_AMARELA_HEX;
            default -> Constantes.BACKGROUND_COLOR_HEX;
        }));
    }

    private void registarObservadores() { observable.addPropertyChangeListener(Propriedade.ATUALIZAR_JOGADOR_ATUAL, evt -> atualizar()); }
}
