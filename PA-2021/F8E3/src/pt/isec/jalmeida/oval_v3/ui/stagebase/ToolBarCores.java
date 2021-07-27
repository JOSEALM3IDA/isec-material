package pt.isec.jalmeida.oval_v3.ui.stagebase;

import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.ColorPicker;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import pt.isec.jalmeida.oval_v3.logica.DesenhoObservable;

public class ToolBarCores extends AnchorPane {

    DesenhoObservable desenhoObservable;
    Button btnRed, btnGreen, btnBlue, btnRandom;
    ColorPicker escolheCor;
    Label lblCoords;
    HBox hCores;

    public ToolBarCores(DesenhoObservable desenhoObservable) {
        this.desenhoObservable = desenhoObservable;

        criarLayout();
        registarListeners();

        desenhoObservable.addObserver(DesenhoObservable.COR, e -> atualizaBotaoCorAtiva());

        atualizaBotaoCorAtiva();

    }

    void criarLayout() {
        hCores = new HBox();

        btnRed = new MyButton();
        btnRed.setBackground(new Background(new BackgroundFill(Color.rgb(255, 0, 0), CornerRadii.EMPTY, Insets.EMPTY)));

        btnGreen = new MyButton();
        btnGreen.setBackground(new Background(new BackgroundFill(Color.rgb(0, 255, 0), CornerRadii.EMPTY, Insets.EMPTY)));

        btnBlue = new MyButton();
        btnBlue.setBackground(new Background(new BackgroundFill(Color.rgb(0, 0, 255), CornerRadii.EMPTY, Insets.EMPTY)));

        btnRandom = new MyButton("?");

        escolheCor = new ColorPicker(Color.BLACK);

        hCores.getChildren().addAll(btnRed, btnGreen, btnBlue, btnRandom, escolheCor);

        hCores.setSpacing(20);
        hCores.setPadding(new Insets(10));

        lblCoords = new Label("Ponto = (xxx,yyy)");
        lblCoords.setFont(Font.font("Monospaced", FontWeight.BOLD, 16));

        this.getChildren().addAll(hCores, lblCoords);
        AnchorPane.setLeftAnchor(hCores, 0.0);
        AnchorPane.setBottomAnchor(hCores, 0.0);

        AnchorPane.setRightAnchor(lblCoords, 0.0);
        AnchorPane.setBottomAnchor(lblCoords, 0.0);
    }

    void registarListeners() {
        btnRed.setOnAction(e -> desenhoObservable.setRGB(1, 0, 0));
        btnGreen.setOnAction(e -> desenhoObservable.setRGB(0, 1, 0));
        btnBlue.setOnAction(e -> desenhoObservable.setRGB(0, 0, 1));
        btnRandom.setOnAction(e -> desenhoObservable.setRGB(Math.random(), Math.random(), Math.random()));

        escolheCor.setOnAction( e -> {
            Color cor = escolheCor.getValue();
            desenhoObservable.setRGB(cor.getRed(), cor.getGreen(), cor.getBlue());
        });
    }

    private void atualizaBotaoCorAtiva() {
        Border border = new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID, CornerRadii.EMPTY, BorderWidths.DEFAULT));

        double r = desenhoObservable.getR();
        double g = desenhoObservable.getG();
        double b = desenhoObservable.getB();

        btnRed.setBorder(r > 0 && g == 0 && b == 0 ? border : null);
        btnGreen.setBorder(g > 0 && r == 0 && b == 0 ? border : null);
        btnBlue.setBorder(b > 0 && r == 0 && g == 0 ? border : null);
        btnRandom.setBorder(r * g != 0 || r * b != 0 || g * b != 0 ? border : null);

        escolheCor.setValue(Color.color(r, g, b));
    }

    public void atualizaCoords(int x, int y) {
        String str = String.format("Ponto = (%04d, %04d)", x, y);
        lblCoords.setText(str);
    }
}
