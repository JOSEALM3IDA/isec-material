package pt.isec.ans.biblioteca.modelo;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Livro implements Comparable<Livro>, Serializable {
    private static final long serialVersionUID = 1L;

    private static int contador = 0;

    private static int geraCodigo() {
        return ++contador;
    }

    public void verificaContador() {
        if (this.codigo > contador)
            contador = codigo;
    }

    private int codigo;
    private String titulo;
    private List<String> autores;
    private transient int variavel_que_nao_fica_gravada = 0;

    public Livro(int codigo) {
        this.codigo = codigo;
        titulo = null;
        autores = null;
    }

    public Livro(String titulo, List<String> autores) {
        this.codigo = geraCodigo();
        this.titulo = titulo;
        this.autores = new ArrayList<>(autores);
    }

    public Livro (String info) {
        Scanner bookScanner = new Scanner(info);
        bookScanner.useDelimiter(",");
        this.codigo = Integer.parseInt(bookScanner.next());

        verificaContador();

        this.titulo = bookScanner.next();

        autores = new ArrayList<>();
        while (bookScanner.hasNext())
            this.autores.add(bookScanner.next());

        bookScanner.close();
    }

    public int getCodigo() {
        return codigo;
    }

    public String getTitulo() {
        return titulo;
    }

    public List<String> getAutores() {
        return autores;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(String.format("%d,%s",codigo,titulo));
        for(String a : autores)
            sb.append(String.format(",%s",a));
        return sb.toString();
    }

    public String toStringFormatdo() {
        StringBuilder sb = new StringBuilder(String.format("[%d] \"%s\"",codigo,titulo));
        for(String a : autores)
            sb.append(String.format(", %s",a));
        return sb.toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        //if (!(o instanceof Livro) ) return false;
        Livro livro = (Livro) o;

        return codigo == livro.codigo;
    }

    @Override
    public int hashCode() {
        return codigo;
    }

    @Override
    public int compareTo(Livro o) {
        return codigo - o.codigo;
    }

    public static class ComparaTitulo implements Comparator<Livro> {

        @Override
        public int compare(Livro o1, Livro o2) {
            return o1.getTitulo().compareTo(o2.getTitulo());
        }
    }

    public static class ComparaCodigo implements Comparator<Livro> {

        @Override
        public int compare(Livro o1, Livro o2) {
            return Integer.valueOf(o1.getCodigo()).compareTo(o2.getCodigo());
        }
    }

}

