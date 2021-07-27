package pt.isec.jalmeida.f8e1;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

class RootPane extends BorderPane {
    Stage stage;
    Button btnGreen, btnBlue;

    Label lblGreen, lblBlue;
    int nGreen = 0, nBlue = 0;


    public RootPane(Stage stage) {
        this.stage = stage;

        createLayout();
        registerListeners();
    }

    private void createLayout() {
        btnGreen = new Button("Green");
        btnBlue = new Button("Blue");

        HBox toolBar = new HBox();

        toolBar.getChildren().addAll(btnGreen, btnBlue);
        toolBar.setAlignment(Pos.CENTER);
        toolBar.setPadding(new Insets(10));
        toolBar.setSpacing(10);

        changeBackground(toolBar, Color.DARKGRAY);

        this.setTop(toolBar);

        GridPane grid = new GridPane();
        grid.setVgap(10.0); grid.setHgap(10);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                Pane pane = new Pane();
                pane.setPrefSize(50, 50);
                changeBackground(pane, Color.color(Math.random(), Math.random(), Math.random()));

                pane.setOnMouseClicked(mouseEvent -> changeBackground((Pane) mouseEvent.getTarget(), Color.color(Math.random(), Math.random(), Math.random())));

                grid.add(pane, i, j);
            }
        }

        grid.setAlignment(Pos.CENTER);

        this.setCenter(grid);

        lblGreen = new Label();
        lblBlue = new Label();
        AnchorPane labels = new AnchorPane();

        labels.getChildren().addAll(lblGreen, lblBlue);

        AnchorPane.setLeftAnchor(lblGreen, 10.0);
        AnchorPane.setBottomAnchor(lblGreen, 10.0);

        AnchorPane.setRightAnchor(lblBlue, 10.0);
        AnchorPane.setBottomAnchor(lblBlue, 10.0);

        updateLabels();
        this.setBottom(labels);
    }

    private void changeBackground(Region region, Color color) {
        region.setBackground(new Background(new BackgroundFill(color, CornerRadii.EMPTY, Insets.EMPTY)));
    }

    private void registerListeners() {
        btnGreen.setOnAction(new ProcBtnGreen());
        btnBlue.setOnAction(actionEvent -> {
            nBlue++;
            updateLabels();
            changeBackground(RootPane.this, Color.BLUE);
            lblBlue.setTextFill(Color.ORANGE);
            lblGreen.setTextFill(Color.ORANGE);
        });
    }

    private void updateLabels() {
        lblBlue.setText("#Blue: " + nBlue);
        lblGreen.setText("#Green: " + nGreen);
    }

    class ProcBtnGreen implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent actionEvent) {
            nGreen++;
            updateLabels();
            changeBackground(RootPane.this, Color.GREEN);
            lblBlue.setTextFill(Color.WHITE);
            lblGreen.setTextFill(Color.WHITE);
        }
    }
}



