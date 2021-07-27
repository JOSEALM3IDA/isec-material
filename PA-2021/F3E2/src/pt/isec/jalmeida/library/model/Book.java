package pt.isec.jalmeida.library.model;

import java.util.ArrayList;
import java.util.List;

public class Book implements Comparable<Book> {
    private static int next = 0;

    private static int generateCode() {
        return ++next;
    }

    private int code;
    private String title;
    private List<String> authors;

    public Book(int code) {
        this.code = code;
        title = null;
        authors = null;
    }

    public Book(String titulo, List<String> authors) {
        this.code = generateCode();
        this.title = titulo;
        this.authors = new ArrayList<>(authors);
    }

    public int getCode() {
        return code;
    }

    public String getTitle() {
        return title;
    }

    public List<String> getAuthors() {
        return authors;
    }

    @Override
    public int compareTo(Book o) {
        return code - o.code;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        //if (!(o instanceof Book) ) return false;

        Book book = (Book) o;

        return code == book.code;
    }

    @Override
    public int hashCode() {
        return code;
    }

    @Override
    public String toString() {
        return "Book{" +
                "code=" + code +
                ", titulo='" + title + '\'' +
                ", autors=" + authors +
                '}';
    }
}
