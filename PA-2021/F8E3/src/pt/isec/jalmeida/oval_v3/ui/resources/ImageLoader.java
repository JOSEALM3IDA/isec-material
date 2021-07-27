package pt.isec.jalmeida.oval_v3.ui.resources;

import javafx.scene.image.Image;

import java.util.HashMap;

public class ImageLoader {

    static HashMap<String, Image> imgCache;

    static {
        imgCache = new HashMap<>();
    }

    public static Image getImage(String name) {

        Image img = imgCache.get(name);
        if (img != null) return img;

        try {
            return new Image(Resources.getResourceAsFileStream("images/" + name));
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Erro a ler imagem");
        }
        return null;
    }

    public static Image getImageForce(String name) {
        imgCache.remove(name);
        return getImage(name);
    }

}
