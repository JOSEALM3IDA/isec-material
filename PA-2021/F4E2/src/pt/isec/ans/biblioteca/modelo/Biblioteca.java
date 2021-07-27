package pt.isec.ans.biblioteca.modelo;

import java.io.File;
import java.util.List;

public interface Biblioteca {
    @Override
    String toString();
    String toStringPorTitulo();
    String toStringPorCodigo();

    int acrescentaLivro(String titulo, List<String> autores);
    int acrescentaLivro(Livro livro);

    Livro pesquisaLivro(int codigo);

    boolean eliminaLivro(int codigo);

    void escreveFichTxt(File file);
}
