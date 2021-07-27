package jogo.iu.gui.stage.menu;

import javafx.geometry.Pos;
import javafx.scene.layout.HBox;
import jogo.utils.Constantes;

public class FooterBox extends HBox {

    public FooterBox() { this(0); }

    public FooterBox(double v) {
        super(v);

        setId("footer-box");

        setAlignment(Pos.CENTER);
        setMinSize(Constantes.LARG_SCENE, Constantes.ALT_FOOTER);
    }
}
