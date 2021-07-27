package jogo.iu.gui.stage.menu;

import javafx.geometry.Pos;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.VBox;
import jogo.iu.gui.resources.ImageLoader;
import jogo.utils.Constantes;


public class MenuBackground extends VBox {
    public MenuBackground() {
        this.setMinHeight(100.0);

        ImageView imageView = new ImageView();
        Image menuBackground = ImageLoader.getImage(Constantes.IMG_BACKGROUND_MENU);
        imageView.setImage(menuBackground);
        imageView.setPreserveRatio(true);
        imageView.fitWidthProperty().bind(this.widthProperty());
        imageView.fitHeightProperty().bind(this.heightProperty());

        this.getChildren().add(imageView);
        this.setAlignment(Pos.CENTER_LEFT);
    }
}
