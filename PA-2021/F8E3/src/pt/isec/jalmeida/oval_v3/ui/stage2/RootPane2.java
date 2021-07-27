package pt.isec.jalmeida.oval_v3.ui.stage2;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import pt.isec.jalmeida.oval_v3.logica.DesenhoObservable;
import pt.isec.jalmeida.oval_v3.logica.Figura;

import java.util.List;

public class RootPane2 extends BorderPane {
    DesenhoObservable desenhoObservable;
    ListView<Figura> lista;
    HBox toolbar;
    Button btnLer, btnGravar;

    public RootPane2(DesenhoObservable desenhoObservable) {
        this.desenhoObservable = desenhoObservable;
        createLayout();
        registerListeners();

        desenhoObservable.addObserver(DesenhoObservable.DESENHO, e -> {
            if (lista == null) return;
            List<Figura> lstFig = desenhoObservable.getLista();
            lista.getItems().clear();
            lista.getItems().addAll(lstFig);

        });
    }

    private void createLayout() {
        toolbar = new HBox();
        btnLer = new Button("Ler");
        btnGravar = new Button("Gravar");
        toolbar.getChildren().addAll(btnLer, btnGravar);
        toolbar.setAlignment(Pos.CENTER);
        toolbar.setSpacing(20);
        toolbar.setPadding(new Insets(10));
        this.setTop(toolbar);
        lista = new ListView<>();
        //this.getChildren().add(lista);
        this.setCenter(lista);
    }

    private void registerListeners() {

        btnLer.setOnAction( e -> desenhoObservable.ler());

        btnGravar.setOnAction( e-> desenhoObservable.gravar());

        lista.setOnMouseClicked(e -> {
            Figura fig = lista.getSelectionModel().getSelectedItem();

            if (fig == null) return;

            System.out.println(fig);

            if (e.getClickCount() == 2) {
                fig.setRGB(0, 0, 0);
                desenhoObservable.atualizaTudo();
            }

        });

    }
}
