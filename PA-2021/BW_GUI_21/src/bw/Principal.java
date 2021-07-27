package bw;


import bw.iu.texto.IUTexto;
import bw.logica.JogoMaqEstados;

public class Principal {

        public static void main(String[] args) {
            JogoMaqEstados jogoMaqEstados = new JogoMaqEstados();
            IUTexto iu = new IUTexto(jogoMaqEstados);
            iu.corre();
        }

}
