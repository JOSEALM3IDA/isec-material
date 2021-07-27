package pt.isec.jalmeida.oval_v3.ui.stagebase;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import pt.isec.jalmeida.oval_v3.logica.DesenhoObservable;
import pt.isec.jalmeida.oval_v3.logica.Figura;
import pt.isec.jalmeida.oval_v3.ui.resources.ImageLoader;

import static pt.isec.jalmeida.oval_v3.ui.UIConstantes.TAM_BTN;

public class ToolBarPrinc extends HBox {
    DesenhoObservable desenhoObservable;
    Button btnApagaUlt,btnApagaTudo;
    Button btnLinha,btnRetangulo,btnOval;

    public ToolBarPrinc(DesenhoObservable desenhoObservable) {
        this.desenhoObservable = desenhoObservable;

        criarLayout();
        registarListeners();

        desenhoObservable.addObserver(DesenhoObservable.TIPO_FIGURA, e -> {
            atualizaBotaoTipoAtivo();
        });
        atualizaBotaoTipoAtivo();

    }
    class MyButton extends Button {
        public MyButton() {
            //super();
            this.setPrefSize(TAM_BTN, TAM_BTN);
        }
    }

    private void criarLayout() {
        Image imgTeste = ImageLoader.getImage("img.png");
        ImageView viewTeste = new ImageView(imgTeste);
        viewTeste.setFitWidth(TAM_BTN);
        viewTeste.setPreserveRatio(true);
        btnApagaUlt = new Button("Apaga ult.");
        btnApagaUlt.setPrefHeight(TAM_BTN);
        btnApagaTudo = new Button("Apaga tudo");
        btnApagaTudo.setPrefHeight(TAM_BTN);

        btnLinha = new MyButton();
        btnLinha.setGraphic(new Line(0,0,TAM_BTN-10,TAM_BTN - 10));
        btnRetangulo = new MyButton();
        btnRetangulo.setGraphic(new Rectangle(0,0,TAM_BTN-10,TAM_BTN - 10));
        btnOval = new MyButton();
        btnOval.setGraphic(new Ellipse(TAM_BTN >> 1, TAM_BTN >> 1, (TAM_BTN >> 1) - 4, (TAM_BTN >> 1) - 6));

        this.getChildren().addAll(
                btnLinha,btnRetangulo,btnOval,
                new Line(0,0,0,30),
                btnApagaUlt,btnApagaTudo,
                viewTeste);
        this.setAlignment(Pos.CENTER);
        this.setSpacing(20);
        this.setPadding(new Insets(10));

    }

    private void registarListeners() {
        btnApagaUlt.setOnAction(e -> desenhoObservable.apagaUltima());
        btnApagaTudo.setOnAction(e-> desenhoObservable.apagaTudo());
        btnLinha.setOnAction(e -> desenhoObservable.setTipo(Figura.TipoFigura.LINHA));
        btnRetangulo.setOnAction(e-> desenhoObservable.setTipo(Figura.TipoFigura.RETANGULO));
        btnOval.setOnAction(e-> desenhoObservable.setTipo(Figura.TipoFigura.OVAL));

    }

    void atualizaBotaoTipoAtivo() {
        Border border = new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID,
                CornerRadii.EMPTY,BorderWidths.DEFAULT));
        Figura.TipoFigura tipo = desenhoObservable.getTipo();
        btnLinha.setBorder(tipo == Figura.TipoFigura.LINHA ? border : null);
        btnRetangulo.setBorder(tipo == Figura.TipoFigura.RETANGULO ? border : null);
        btnOval.setBorder(tipo == Figura.TipoFigura.OVAL ? border : null);
    }

}
