
package bw;


import bw.iu.gui.BWRoot;
import bw.logica.JogoMaqEstados;
import bw.logica.JogoObservavel;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Bw20jfx extends Application {
    
    @Override
    public void start(Stage primaryStage) {

        JogoMaqEstados jogoMaqEstados = new JogoMaqEstados();
        JogoObservavel observableModel = new JogoObservavel(jogoMaqEstados);
        
        BWRoot bwRoot = new BWRoot(observableModel);

        Scene scene = new Scene(bwRoot);
//        primaryStage.setResizable(false);        
        primaryStage.setScene(scene); 
        primaryStage.setTitle("\"black & white\"");
        primaryStage.setOnCloseRequest(windowEvent -> Platform.exit());
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
    
}
