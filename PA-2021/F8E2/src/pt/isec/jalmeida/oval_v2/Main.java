package pt.isec.jalmeida.oval_v2;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import pt.isec.jalmeida.oval_v2.logica.Desenho;
import pt.isec.jalmeida.oval_v2.ui.PaneOrganizer;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Desenho desenho = new Desenho();
        PaneOrganizer root = new PaneOrganizer(desenho);
        Scene scene = new Scene(root, 800, 600);
        stage.setScene(scene);
        stage.setTitle("Exercicio 2");
        stage.setMinWidth(300); stage.setMinHeight(300);
        stage.show();
    }
}
