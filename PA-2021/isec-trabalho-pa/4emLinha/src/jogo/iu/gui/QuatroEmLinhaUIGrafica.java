package jogo.iu.gui;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.stage.Stage;
import jogo.iu.gui.resources.ImageLoader;
import jogo.iu.gui.stage.PaneOrganizer;
import jogo.logica.QuatroEmLinhaMaquinaEstados;
import jogo.logica.QuatroEmLinhaObservable;
import jogo.utils.Constantes;

public class QuatroEmLinhaUIGrafica extends Application {
    @Override
    public void start(Stage stage) {

        QuatroEmLinhaMaquinaEstados maquinaEstados = new QuatroEmLinhaMaquinaEstados();
        QuatroEmLinhaObservable observable = new QuatroEmLinhaObservable(maquinaEstados);

        PaneOrganizer root = new PaneOrganizer(observable);

        Scene scene = new Scene(root, Constantes.LARG_SCENE, Constantes.ALT_SCENE); // 16:9
        stage.setScene(scene);
        stage.setTitle("Quatro em Linha");
        stage.getIcons().add(ImageLoader.getImage("icon.png"));
        stage.setResizable(true);
        stage.setOnCloseRequest(windowEvent -> Platform.exit());
        stage.show();
    }
}
