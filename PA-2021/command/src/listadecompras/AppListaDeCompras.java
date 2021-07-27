package listadecompras;

import listadecompras.iu.texto.IUTexto;
import listadecompras.logica.ListaDeComprasGestao;

public class AppListaDeCompras {
    public static void main(String[] args) {
        ListaDeComprasGestao listaDeComprasGestao = new ListaDeComprasGestao();
        IUTexto iu = new IUTexto(listaDeComprasGestao);
        iu.corre();
    }

}
