package pt.isec.ans.biblioteca;

import pt.isec.ans.biblioteca.iu.BiblioIU;
import pt.isec.ans.biblioteca.modelo.BibliotecaSet;

public class Main {
    public static void main(String[] args) {
        BibliotecaSet biblioteca = new BibliotecaSet("DEIS-ISEC-Set");
        BiblioIU biblioIU = new BiblioIU(biblioteca);
        biblioIU.comeca();
    }
}
