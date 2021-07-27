package labirintojfx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import labirintojfx.logica.LabirintoGameObs;
import labirintojfx.ui.grafica.LabUIGrafica;

public class LabirintoJFX extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        LabirintoGameObs gameObs = new LabirintoGameObs();
        LabUIGrafica gui = new LabUIGrafica(gameObs);
        primaryStage.setTitle("Labirinto UI Gráfica");
        primaryStage.setScene(new Scene(gui.obtemRootPane(), 320, 240));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
