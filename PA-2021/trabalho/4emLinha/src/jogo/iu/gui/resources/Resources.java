package jogo.iu.gui.resources;

import java.io.InputStream;
import java.util.Objects;

public class Resources {

    private Resources() {}

    public static InputStream getResourceAsFileStream(String name) {
        return Resources.class.getResourceAsStream(name);
    }

    public static String getResourceFileName(String name) {
        return Objects.requireNonNull(Resources.class.getResource(name)).toExternalForm();
    }
}
