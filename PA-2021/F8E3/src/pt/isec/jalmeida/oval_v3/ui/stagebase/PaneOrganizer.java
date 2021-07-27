package pt.isec.jalmeida.oval_v3.ui.stagebase;

import javafx.beans.value.ChangeListener;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import pt.isec.jalmeida.oval_v3.logica.DesenhoObservable;

public class PaneOrganizer extends BorderPane {
    DesenhoObservable desenhoObservable;
    AreaDesenho areaDesenho;
    HBox toolBar;
    ToolBarCores toolBarCores;
    Pane centro;

    public PaneOrganizer(DesenhoObservable desenhoObservable) {
        this.desenhoObservable = desenhoObservable;
        criarLayout();
        registarListeners();;
    }

    void criarLayout() {
        toolBar = new ToolBarPrinc(desenhoObservable);
        this.setTop(toolBar);

        this.setCenter(areaDesenho);

        centro = new Pane();
        areaDesenho = new AreaDesenho(desenhoObservable);
        centro.getChildren().add(areaDesenho);
        this.setCenter(centro);

        toolBarCores = new ToolBarCores(desenhoObservable);
        this.setBottom(toolBarCores);
    }

    ChangeListener procSize = (observableValue, o, t1) -> areaDesenho.alteraDims(centro.getWidth(), centro.getHeight());

    void registarListeners() {
        areaDesenho.addEventHandler(MouseEvent.MOUSE_MOVED, e -> toolBarCores.atualizaCoords((int) e.getX(), (int) e.getY()));
        
        areaDesenho.addEventHandler(MouseEvent.MOUSE_DRAGGED, e -> toolBarCores.atualizaCoords((int) e.getX(), (int) e.getY()));
        
        centro.widthProperty().addListener(procSize);
        centro.heightProperty().addListener(procSize);
    }

}

