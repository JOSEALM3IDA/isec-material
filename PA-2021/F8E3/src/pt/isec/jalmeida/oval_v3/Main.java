package pt.isec.jalmeida.oval_v3;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import pt.isec.jalmeida.oval_v3.logica.DesenhoObservable;
import pt.isec.jalmeida.oval_v3.ui.stagebase.PaneOrganizer;
import pt.isec.jalmeida.oval_v3.ui.stage2.RootPane2;

public class Main extends Application {

    boolean exiting = false;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        DesenhoObservable desenhoObservable = new DesenhoObservable();

        PaneOrganizer root = new PaneOrganizer(desenhoObservable);

        Scene scene = new Scene(root, 800, 600);
        stage.setScene(scene);
        stage.setTitle("Exercicio 2");
        stage.setMinWidth(300); stage.setMinHeight(300);
        stage.show();

        Stage stage2 = new Stage();
        RootPane2 root2 = new RootPane2(desenhoObservable);
        Scene scene2 = new Scene(root2, 300, 800);
        stage2.setScene(scene2);
        stage2.setX(stage.getX() + stage.getWidth());
        stage2.setY(stage.getY());
        stage2.setTitle("Janela 2");
        stage2.show();

        stage.setOnCloseRequest( e -> {
            if (exiting)
                return;
            exiting = true;

            if (stage != null) stage2.close();
            //Platform.exit();
        });

        stage2.setOnCloseRequest( e -> {
            if (exiting)
                return;
            exiting = true;

            if (stage != null) stage.close();
        });
    }
}

