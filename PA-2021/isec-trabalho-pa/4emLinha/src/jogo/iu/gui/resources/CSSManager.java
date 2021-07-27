package jogo.iu.gui.resources;

import javafx.scene.Parent;

public class CSSManager {
    private CSSManager() {}

    public static void setCss(Parent parent, String fileName) {
        parent.getStylesheets().add(Resources.getResourceFileName("css/" + fileName));
    }
}
