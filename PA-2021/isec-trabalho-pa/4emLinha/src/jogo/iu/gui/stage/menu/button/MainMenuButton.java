package jogo.iu.gui.stage.menu.button;

import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.input.MouseButton;
import jogo.iu.gui.resources.MusicPlayer;
import jogo.utils.Constantes;

public class MainMenuButton extends Button {

    public MainMenuButton(String s) {
        super(s);

        this.setId("menu-button");
        this.setPrefSize(Constantes.LARG_MENU_BTN, Constantes.ALT_MENU_BTN);
        setAlignment(Pos.CENTER);

        registerListeners();
    }

    public void registerListeners() {
        this.setOnMouseClicked(e -> {
            if (e.getButton() != MouseButton.PRIMARY) return;
            MusicPlayer.playMusic(Constantes.SOM_CLICK_BTN);
        });

        this.setOnMouseEntered(e -> MusicPlayer.playMusic(Constantes.SOM_HOVER_BTN));
    }
}
