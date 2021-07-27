package jogo.iu.gui.resources;

import javafx.scene.text.Font;

public class FontManager {
    private FontManager() {}

    public static Font loadFont(String nome, double tamanho) {
        return Font.loadFont(Resources.getResourceAsFileStream("fonts/" + nome), tamanho);
    }
}
