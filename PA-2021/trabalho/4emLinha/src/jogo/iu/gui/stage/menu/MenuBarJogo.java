package jogo.iu.gui.stage.menu;

import javafx.application.Platform;
import javafx.scene.control.*;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.input.KeyCombination;

import javafx.stage.FileChooser;
import jogo.logica.QuatroEmLinhaObservable;
import jogo.utils.Constantes;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.net.URI;
import java.util.Optional;

public class MenuBarJogo extends MenuBar {

    private final QuatroEmLinhaObservable observable;

    private Menu jogoMenu;
    private MenuItem novoJogoMItem;
    private MenuItem continuarJogoMItem;
    private MenuItem verReplayMItem;
    private MenuItem gravarJogoMItem;
    private MenuItem voltarMItem;
    private MenuItem sairMItem;

    private Menu ajudaMenu;
    private MenuItem comoJogarMItem;
    private MenuItem aboutMItem;

    public MenuBarJogo(QuatroEmLinhaObservable observable) {
        this.observable = observable;
        createMenus();
    }

    private void createMenus() {
        // JOGO
        jogoMenu = new Menu("_Jogo");

        novoJogoMItem = new MenuItem("Novo Jogo");
        novoJogoMItem.setAccelerator(new KeyCodeCombination(KeyCode.N, KeyCombination.CONTROL_DOWN));

        continuarJogoMItem = new MenuItem("Continuar Jogo");
        continuarJogoMItem.setAccelerator(new KeyCodeCombination(KeyCode.L, KeyCombination.CONTROL_DOWN));

        verReplayMItem = new MenuItem("Ver Replay");
        verReplayMItem.setAccelerator(new KeyCodeCombination(KeyCode.R, KeyCombination.CONTROL_DOWN));

        gravarJogoMItem = new MenuItem("Gravar Jogo");
        gravarJogoMItem.setAccelerator(new KeyCodeCombination(KeyCode.G, KeyCombination.CONTROL_DOWN));

        voltarMItem = new MenuItem("Voltar ao Menu");
        voltarMItem.setAccelerator(new KeyCodeCombination(KeyCode.V, KeyCombination.CONTROL_DOWN));

        sairMItem = new MenuItem("Sair");
        sairMItem.setAccelerator(new KeyCodeCombination(KeyCode.S, KeyCombination.CONTROL_DOWN));

        jogoMenu.getItems().addAll(novoJogoMItem, continuarJogoMItem, verReplayMItem, gravarJogoMItem,
                new SeparatorMenuItem(), voltarMItem, sairMItem);

        novoJogoMItem.setOnAction(e -> novoJogoAction());
        continuarJogoMItem.setOnAction(e -> continuarJogoAction());
        verReplayMItem.setOnAction(e -> verReplayAction());
        gravarJogoMItem.setOnAction(e -> gravarJogoAction());
        voltarMItem.setOnAction(e -> voltarAction());
        sairMItem.setOnAction(e -> sairAction());

        // AJUDA
        ajudaMenu = new Menu("_Ajuda");

        comoJogarMItem = new MenuItem("Instruções");
        comoJogarMItem.setAccelerator(new KeyCodeCombination(KeyCode.J, KeyCombination.CONTROL_DOWN));

        aboutMItem = new MenuItem("About");
        aboutMItem.setAccelerator(new KeyCodeCombination(KeyCode.A, KeyCombination.CONTROL_DOWN));

        ajudaMenu.getItems().addAll(comoJogarMItem, aboutMItem);

        comoJogarMItem.setOnAction(e -> comoJogarAction());
        aboutMItem.setOnAction(e -> aboutAction());

        this.getMenus().addAll(jogoMenu,ajudaMenu);
    }

    private void comoJogarAction() {
        try {
            Desktop.getDesktop().browse(URI.create("https://www.youtube.com/watch?v=dQw4w9WgXcQ"));
        } catch (IOException ignored) { /* ignored */ }
    }

    private void aboutAction() {
        try {
            Desktop.getDesktop().browse(URI.create("https://github.com/JOSEALM3IDA"));
        } catch (IOException ignored) { /* ignored */ }
    }

    private void novoJogoAction() { observable.iniciarJogo(); }

    private void continuarJogoAction() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Escolher Save");
        fileChooser.setInitialDirectory(new File(Constantes.SAVE_PATH));
        fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Todos", "*.*"));
        File hFile = fileChooser.showOpenDialog(getScene().getWindow());
        if (hFile != null) { observable.continuarJogo(hFile.getAbsolutePath()); }
    }

    private void verReplayAction() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Escolher Replay");
        fileChooser.setInitialDirectory(new File(Constantes.REPLAY_PATH));
        fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Todos", "*.*"));
        File hFile = fileChooser.showOpenDialog(getScene().getWindow());
        if (hFile != null) { observable.verReplay(hFile.getAbsolutePath()); }
    }

    private void gravarJogoAction() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Gravar Jogo");
        fileChooser.setInitialDirectory(new File(Constantes.SAVE_PATH));
        fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Todos", "*.*"));
        File hFile = fileChooser.showSaveDialog(getScene().getWindow());
        if (hFile != null) { observable.gravarJogo(hFile.getAbsolutePath()); }
    }

    private void voltarAction() { observable.voltar(); }

    private void sairAction() {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        alert.setTitle("Confirmar");
        alert.setHeaderText("Sair da Aplicação");
        alert.setContentText("Vai perder todos os dados não guardados - pretende continuar?");

        Optional<ButtonType> result = alert.showAndWait();

        if (result.isEmpty()) return;

        if (result.get() != ButtonType.OK) return;

        Platform.exit();
    }


}
