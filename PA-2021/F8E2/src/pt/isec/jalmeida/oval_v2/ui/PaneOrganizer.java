package pt.isec.jalmeida.oval_v2.ui;

import javafx.beans.value.ChangeListener;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import pt.isec.jalmeida.oval_v2.logica.Desenho;


public class PaneOrganizer extends BorderPane {
    private static final int TAM_BTN = 30;

    Desenho desenho;
    AreaDesenho areaDesenho;
    HBox toolBar;
    Button btnApagaUlt, btnApagaTudo;
    Button btnRed, btnGreen, btnBlue, btnRandom;

    public PaneOrganizer(Desenho desenho) {
        this.desenho = desenho;
        criarLayout();
        registarListeners();
    }

    void criarLayout() {
        toolBar = new HBox();

        btnApagaUlt = new Button("Apaga ult.");
        btnApagaUlt.setPrefHeight(TAM_BTN);

        btnApagaTudo = new Button("Apaga tudo");
        btnApagaTudo.setPrefHeight(TAM_BTN);

        btnRed = new Button();
        btnRed.setBackground(new Background(new BackgroundFill(Color.rgb(255, 0, 0), CornerRadii.EMPTY, Insets.EMPTY)));
        btnRed.setPrefSize(TAM_BTN, TAM_BTN);

        btnGreen = new Button();
        btnGreen.setBackground(new Background(new BackgroundFill(Color.rgb(0, 255, 0), CornerRadii.EMPTY, Insets.EMPTY)));
        btnGreen.setPrefSize(TAM_BTN, TAM_BTN);

        btnBlue = new Button();
        btnBlue.setBackground(new Background(new BackgroundFill(Color.rgb(0, 0, 255), CornerRadii.EMPTY, Insets.EMPTY)));
        btnBlue.setPrefSize(TAM_BTN, TAM_BTN);

        btnRandom = new Button("?");
        btnRandom.setPrefSize(TAM_BTN, TAM_BTN);

        toolBar.getChildren().addAll(btnApagaUlt, btnApagaTudo, new Line(0, 0, 0, 30) , btnRed, btnGreen, btnBlue, btnRandom);
        toolBar.setAlignment(Pos.CENTER);
        toolBar.setSpacing(20);
        toolBar.setPadding(new Insets(10));
        this.setTop(toolBar);

        areaDesenho = new AreaDesenho(desenho);
        this.setCenter(areaDesenho);
    }

    ChangeListener procSize = (observableValue, o, t1) -> areaDesenho.alteraDims(PaneOrganizer.this.getWidth(),
    PaneOrganizer.this.getHeight());

    void registarListeners() {
        btnApagaTudo.setOnAction(e -> {
            desenho.apagaTudo();
            areaDesenho.atualiza();
        });

        btnApagaUlt.setOnAction(e -> {
            desenho.apagaUltima();
            areaDesenho.atualiza();
        });

        btnRed.setOnAction(e -> {
            desenho.setRGB(1, 0, 0);
            atualizaBotaoAtivo();
        });

        btnGreen.setOnAction(e -> {
            desenho.setRGB(0, 1, 0);
            atualizaBotaoAtivo();
        });

        btnBlue.setOnAction(e -> {
            desenho.setRGB(0, 0, 1);
            atualizaBotaoAtivo();
        });

        btnRandom.setOnAction(e -> {
            desenho.setRGB(Math.random(), Math.random(), Math.random());
            atualizaBotaoAtivo();
        });

        widthProperty().addListener(procSize);
        heightProperty().addListener(procSize);
    }

    void atualizaBotaoAtivo() {
        Border border = new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID, CornerRadii.EMPTY, BorderWidths.DEFAULT));
        double r = desenho.getR();
        double g = desenho.getG();
        double b = desenho.getB();

        btnRed.setBorder(r > 0 && g == 0 && b == 0 ? border : null);
        btnGreen.setBorder(g > 0 && r == 0 && b == 0 ? border : null);
        btnBlue.setBorder(b > 0 && r == 0 && g == 0 ? border : null);
        btnRandom.setBorder(r * g != 0 || r * b != 0 || g * b != 0 ? border : null);
    }
}

