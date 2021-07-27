package pt.isec.ans.biblioteca.modelo;

import java.io.*;
import java.util.*;

public class BibliotecaSet implements Biblioteca, Serializable {
    private static final long serialVersionUID = 1L;

    private String nome;
    private Set<Livro> livros;

    private static final String FILENAME = "biblio.bin";

    public BibliotecaSet(String nome) {
        this.nome = nome;
        livros = new HashSet<>();
    }

    public BibliotecaSet(File f) {
        try {
            Scanner lineScanner = new Scanner(f);

            this.nome = lineScanner.nextLine();

            livros = new HashSet<>();
            while (lineScanner.hasNext())
                livros.add(new Livro(lineScanner.next().trim()));

            lineScanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Ficheiro nao encontrado!");
        }
    }


    public String toStringPorTitulo() {
        StringBuilder sb = new StringBuilder(String.format("Biblioteca %s:",nome));
        List<Livro> lista = new ArrayList<>();
        lista.addAll(livros);
        Collections.sort(lista,new Livro.ComparaTitulo());
        Iterator<Livro> it = lista.iterator();
        while (it.hasNext()) {
            Livro livro= it.next();
            sb.append("\n\t- ");
            sb.append(livro.toStringFormatdo());
        }
        return sb.toString();
    }

    public String toStringPorCodigo() {
        StringBuilder sb = new StringBuilder(String.format("Biblioteca %s:",nome));
        List<Livro> lista = new ArrayList<>();
        lista.addAll(livros);
        Collections.sort(lista,new Livro.ComparaCodigo());
        Iterator<Livro> it = lista.iterator();
        while (it.hasNext()) {
            Livro livro= it.next();
            sb.append("\n\t- ");
            sb.append(livro.toStringFormatdo());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(nome);
        sb.append('\n');
        for(Livro l : livros) {
            sb.append(l.toString());
            sb.append('\n');
        }
        return sb.toString();
    }

    @Override
    public int acrescentaLivro(String titulo, List<String> autores) {
        Livro novo = new Livro(titulo,autores);
        if (!livros.add(novo))
            return -1;
        return novo.getCodigo();
    }

    @Override
    public int acrescentaLivro(Livro livro) {
        if (!livros.add(livro))
            return -1;
        return livro.getCodigo();
    }

    @Override
    public Livro pesquisaLivro(int codigo) {
        //Livro base = new Livro(codigo);
        Iterator<Livro> it = livros.iterator();
        while (it.hasNext()) {
            Livro livro = it.next();
            //if (livro.equals(base))
            //    return livro;
            if (livro.getCodigo() == codigo)
                return livro;
        }
        //for (Livro livro : livros)
        //    if (livro.getCodigo() == codigo)
        //        return livro;

        return null;
    }

    @Override
    public boolean eliminaLivro(int codigo) {
        return livros.remove(new Livro(codigo));
    }

    @Override
    public void escreveFichTxt(File file) {
        try {
            FileWriter wr = new FileWriter(file);
            wr.write(this.toString());
            wr.close();
        } catch (IOException E) {
            System.out.println("Erro IO!");
        }
    }

    public boolean gravar() {
        int erro = 1;
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILENAME));
            erro = 2;
            oos.writeObject(this);
            erro = 3;
            oos.close();
            erro = 0;
        } catch (IOException e) {
            System.err.println("Erro a gravar: " + erro);
        }

        return erro == 0;
    }

    public static BibliotecaSet lerGenerico() {
        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILENAME));
            BibliotecaSet obj = (BibliotecaSet) ois.readObject();
            ois.close();

            for (Livro l : obj.livros)
                l.verificaContador();

            return obj;
        } catch (Exception e) {
            System.err.println("Erro a ler");
        }

        return null;
    }

    public boolean ler() {
        BibliotecaSet biblio = BibliotecaSet.lerGenerico();
        if (biblio != null) {
            this.nome = biblio.nome;
            this.livros = biblio.livros;
            return true;
        }

        return false;
    }
}
