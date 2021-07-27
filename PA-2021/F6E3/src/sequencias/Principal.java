package sequencias;


import sequencias.iu.texto.IUtexto;
import sequencias.logica.GestaoJogoMaqEstados;
import sequencias.logica.memento.JogoMaqEstados;

public class Principal {
    public static void main(String[] args) {
        GestaoJogoMaqEstados jogoMaqEstados = new GestaoJogoMaqEstados();
        IUtexto iuTexto = new IUtexto(jogoMaqEstados);
        iuTexto.corre();
    }
}
