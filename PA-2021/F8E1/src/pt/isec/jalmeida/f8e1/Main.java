package pt.isec.jalmeida.f8e1;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        RootPane root = new RootPane(stage);
        Scene scene = new Scene(root, 800, 600);

        stage.setScene(scene);
        stage.setMinHeight(200);
        stage.setMinWidth(200);
        stage.setTitle("Exercicio");

        stage.show();
    }
}

