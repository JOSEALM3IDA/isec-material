package bw.iu.gui.resources;

import javafx.scene.image.Image;

import java.util.HashMap;
import java.util.Map;

public class ImageLoader {
    static Map<String,Image> imgCache = new HashMap<>();

    public static Image getImage(String name) {
        Image img = imgCache.get(name);
        if (img != null)
            return img;
        try {
            img = new Image(Resources.getResourceFileAsStream("images/"+name));
            imgCache.put(name,img);
            return img;
        } catch (Exception e) {
        }
        return null;
    }
}
