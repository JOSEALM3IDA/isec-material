package bw.iu.gui.resources;

import java.io.InputStream;

public class Resources  {
    private Resources() {}
    public static InputStream getResourceFileAsStream(String name){
        return Resources.class.getResourceAsStream(name);
    }
    public static String getResourceFilename(String name){
        return Resources.class.getResource(name).toExternalForm();
    }
}
