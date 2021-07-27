package pt.isec.jalmeida.library;

import pt.isec.jalmeida.library.model.Library;
import pt.isec.jalmeida.library.model.LibraryList;
import pt.isec.jalmeida.library.model.LibrarySet;
import pt.isec.jalmeida.library.ui.LibUI;

public class Main {
    public static void main(String[] args) {
        //Library lib = new LibraryList("DEIS-ISEC");
        Library lib = new LibrarySet("DEIS-ISEC-Set");
        LibUI libUI = new LibUI(lib);
        libUI.start();
    }
}
