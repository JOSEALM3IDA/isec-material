package listadecompras;

import listadecompras.logica.GestaoListaCompras;
import listadecompras.ui.texto.UITextoListaCompras;

import java.io.IOException;

public class AppListaDeCompras {
    public static void main(String[] args) throws IOException {
        GestaoListaCompras gestaolistaDeCompras = new GestaoListaCompras();
        UITextoListaCompras ui = new UITextoListaCompras(gestaolistaDeCompras);
        ui.corre();
    }
}
