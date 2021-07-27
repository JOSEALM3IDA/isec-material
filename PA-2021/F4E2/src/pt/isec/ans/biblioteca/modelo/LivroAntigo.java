package pt.isec.ans.biblioteca.modelo;

import java.util.List;

public class LivroAntigo extends Livro {
    int nrCopias;

    public LivroAntigo(String titulo, List<String> autores, int copias) {
        super(titulo, autores);
        nrCopias = copias;
    }

    public int getNrCopias() {
        return nrCopias;
    }

    public void setNrCopias(int nrCopias) {
        this.nrCopias = nrCopias;
    }

    @Override
    public String toString() {
        return super.toString()+" => LivroAntigo{" +
                "nrCopias=" + nrCopias +
                "}";
    }
}
