package bw.iu.gui;

import bw.iu.gui.resources.ImageLoader;
import bw.logica.JogoObservavel;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.input.KeyCombination;
import javafx.scene.layout.*;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;

import java.io.File;

import static bw.iu.gui.ConstantesGUI.*;
import static bw.logica.Constantes.PROPRIEDADE_BOLAS;
import static bw.logica.Situacao.AGUARDA_APOSTA;

public class BWRoot extends BorderPane {
    private JogoObservavel jogoObservavel;
    private MenuItem novoJogoMI;
    private PrincipalPane principalPane;

    public BWRoot(JogoObservavel jogoObservavel) {
        this.jogoObservavel = jogoObservavel;
        criarVistaCentral();
        menus();
        registarObservador();
        atualiza();
    }
    private void registarObservador(){
        // regista um observador do jogoObservavel
        jogoObservavel.addPropertyChangeListener(PROPRIEDADE_BOLAS, evt -> {
            atualiza();
        });
    }

    private void criarVistaCentral(){
        int dimMin = Math.min(DIM_X_FRAME, DIM_Y_FRAME)- 2 * BORDER_Y;

        Image img = ImageLoader.getImage(ConstantesGUI.BACKGROUND_BALL);
        if(img != null) {
            BackgroundSize backgroundSize = new BackgroundSize(dimMin, dimMin, false, false, false, false);
            BackgroundImage myBI = new BackgroundImage(img,
                    BackgroundRepeat.NO_REPEAT, BackgroundRepeat.NO_REPEAT, BackgroundPosition.CENTER,
                    backgroundSize);

            setBackground(new Background(myBI));
        }
        principalPane = new PrincipalPane(jogoObservavel);
        setCenter(principalPane);
    }

    private void menus() {
        MenuBar menuBar = new MenuBar();
        setTop(menuBar);

        // menu Jogo
        Menu jogoMenu = new Menu("_Jogo");  // underscore: abre com alt + j

        novoJogoMI = new MenuItem("Novo jogo");
        novoJogoMI.setAccelerator(new KeyCodeCombination(KeyCode.N, KeyCombination.CONTROL_DOWN));

        MenuItem lerObjMI = new MenuItem("Ler jogo");
        lerObjMI.setAccelerator(new KeyCodeCombination(KeyCode.L, KeyCombination.CONTROL_DOWN));
        
        MenuItem gravarObjMI = new MenuItem("Gravar");
        gravarObjMI.setAccelerator(new KeyCodeCombination(KeyCode.G, KeyCombination.CONTROL_DOWN));
        
        MenuItem sairMI = new MenuItem("Sair");
        sairMI.setAccelerator(new KeyCodeCombination(KeyCode.S, KeyCombination.CONTROL_DOWN));

        jogoMenu.getItems().addAll( novoJogoMI, lerObjMI, gravarObjMI,new SeparatorMenuItem(), sairMI);

        novoJogoMI.setOnAction((e)-> jogoObservavel.terminar());

        lerObjMI.setOnAction(new LerObjMenuBarListener());

        gravarObjMI.setOnAction(new GravarObjMenuBarListener());

        sairMI.setOnAction((ActionEvent e)-> {
            Stage janela2 = (Stage) this.getScene().getWindow();
            fireEvent( new WindowEvent(janela2, WindowEvent.WINDOW_CLOSE_REQUEST));
        });

        
        // menu ajuda
        Menu ajudaMenu = new Menu("_Ajuda");
        
        MenuItem comoJogarMI = new MenuItem("Como jogar");
        comoJogarMI.setAccelerator(new KeyCodeCombination(KeyCode.J, KeyCombination.CONTROL_DOWN));

        MenuItem acercaMI = new MenuItem("Acerca");
        acercaMI.setAccelerator(new KeyCodeCombination(KeyCode.A, KeyCombination.CONTROL_DOWN));
       
        ajudaMenu.getItems().addAll(comoJogarMI, acercaMI);

        comoJogarMI.setOnAction(new AjudaListener());
        acercaMI.setOnAction(new AcercaListener());

        menuBar.getMenus().addAll(jogoMenu,ajudaMenu);
    }

    
    class LerObjMenuBarListener implements EventHandler<ActionEvent>  {
        @Override
        public void handle(ActionEvent e) {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setInitialDirectory(new File("./jogosgravados"));
            File selectedFile = fileChooser.showOpenDialog(null);
            if (selectedFile != null) {
                   jogoObservavel.ler(selectedFile);
            } else {
                System.err.println("Leitura cancelada ");
            }
        }
    }

    class GravarObjMenuBarListener implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent e) {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setInitialDirectory(new File("./jogosgravados"));
            File selectedFile = fileChooser.showSaveDialog(null);           
            if (selectedFile != null) {
                    jogoObservavel.gravar(selectedFile);
            } else {
                System.err.println("Gravacao cancelada ");
            }
        }
    }



    class AjudaListener implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent e) {
            Alert dialogoResultado = new Alert(Alert.AlertType.INFORMATION);
            dialogoResultado.setHeaderText("Ajuda");
            dialogoResultado.setContentText("Retire duas bolas do saco e tente boas opcoes");
            dialogoResultado.showAndWait();
        }
    }

    class AcercaListener implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent e) {
            Alert dialogoResultado = new Alert(Alert.AlertType.INFORMATION);
            dialogoResultado.setHeaderText("Acerca");
            dialogoResultado.setContentText("Programacao Avancada");
            dialogoResultado.showAndWait();
        }
    }
    private void atualiza() {
        novoJogoMI.setDisable(!(jogoObservavel.getSituacaoAtual() ==  AGUARDA_APOSTA ));
    }
}
