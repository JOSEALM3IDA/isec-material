package pt.isec.jalmeida.JFX01;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class Main extends Application {

    public static void main(String[] args) {
        System.out.println("main");
        launch(args);
    }

    @Override
    public void init() throws Exception {
        super.init();
        System.out.println("init");
    }

    @Override
    public void start(Stage stage) throws Exception {
        System.out.println("start");
        RootPane root = new RootPane();

        //Button b1 = new Button("Botão 1");
        //Button b2 = new Button("Botão 2");

        //root.getChildren().addAll(b1, b2);

        Scene scene = new Scene(root, 800, 600);
        stage.setScene(scene);
        stage.setResizable(false);
        stage.setTitle("Primeira Aplicacao");

        stage.show();
    }

    @Override
    public void stop() throws Exception {
        super.stop();
        System.out.println("stop");
        Platform.exit();
    }
}


