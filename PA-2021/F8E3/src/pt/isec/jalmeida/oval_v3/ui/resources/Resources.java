package pt.isec.jalmeida.oval_v3.ui.resources;

import java.io.InputStream;

public class Resources {

    private Resources() {}

    public static InputStream getResourceAsFileStream(String name) {
        return Resources.class.getResourceAsStream(name);
    }

    public static String getResourceFileName(String name) {
        return Resources.class.getResource(name).toExternalForm();
    }
}
