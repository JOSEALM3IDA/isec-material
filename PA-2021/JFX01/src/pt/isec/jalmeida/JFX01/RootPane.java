package pt.isec.jalmeida.JFX01;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;

class RootPane extends BorderPane {

    HBox toolBar, statusBar;
    Button btnNew, btnOpen, btnClose;
    Label msgStatus;

    public RootPane() {
        createLayout();
        registerListeners();
    }

    void createLayout() {
        toolBar = new HBox();
        statusBar = new HBox();
        btnNew = new Button("New");
        btnOpen = new Button("Open");
        btnClose = new Button("Close");
        btnClose.setOnAction(e -> msgStatus.setText("Abri!!!!"));

        toolBar.getChildren().addAll(btnNew, btnOpen, btnClose);
        this.setTop(toolBar);

        msgStatus = new Label("Mensagem");
        statusBar.getChildren().add(msgStatus);
        this.setBottom(statusBar);
    }

    void registerListeners() {
        btnNew.setOnAction(new ProcBotao());
    }

    class ProcBotao implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent actionEvent) {
            msgStatus.setText("Carreguei!!!!");
        }
    }

}
