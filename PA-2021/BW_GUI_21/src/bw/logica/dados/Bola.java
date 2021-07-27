package bw.logica.dados;

import java.io.Serializable;

public abstract class Bola implements Serializable {

        public abstract boolean reagirASerRetiradaDoSaco(JogoDados jogoDados);

        public abstract void removerSeBranca(JogoDados jogoDados);

        public abstract void removerSePreta(JogoDados jogoDados);

}
