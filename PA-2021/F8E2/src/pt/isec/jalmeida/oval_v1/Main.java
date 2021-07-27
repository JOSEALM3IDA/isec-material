package pt.isec.jalmeida.oval_v1;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import pt.isec.jalmeida.oval_v1.logica.Figura;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        PaneOrganizer root = new PaneOrganizer(new Figura());
        Scene scene = new Scene(root, 800, 600);
        stage.setScene(scene);
        stage.setTitle("Exercicio 2");
        stage.setMinWidth(300); stage.setMinHeight(300);
        stage.show();
    }
}
