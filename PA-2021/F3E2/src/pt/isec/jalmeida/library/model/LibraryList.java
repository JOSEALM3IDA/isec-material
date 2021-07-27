package pt.isec.jalmeida.library.model;

import java.util.ArrayList;
import java.util.List;

public class LibraryList implements Library {
    private String name;
    private List<Book> books;

    public LibraryList(String name) {
        this.name = name;
        this.books = new ArrayList<>();
    }

    @Override
    public int addBook(Book b) {
        books.add(b);
        return b.getCode();
    }

    @Override
    public int addBook(String title, List<String> authors) {
        Book newBook = new Book(title, authors);
        books.add(newBook);
        return newBook.getCode();
    }

    @Override
    public Book searchBook(int code) {
        int idx = books.indexOf(new Book(code));
        return idx < 0 ? null : books.get(idx);
    }

    @Override
    public boolean rmBook(int code) {
        int idx = books.indexOf(new Book(code));
        if (idx < 0)
            return false;

        books.remove(idx);
        return true;
    }

    @Override
    public String toString() {
        return "Library{" +
                "name='" + name + '\'' +
                ", books=" + books +
                '}';
    }
}
