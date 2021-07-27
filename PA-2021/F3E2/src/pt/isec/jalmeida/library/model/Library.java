package pt.isec.jalmeida.library.model;

import java.util.Comparator;
import java.util.List;

public interface Library {
    int addBook(Book b);

    int addBook(String title, List<String> authors);

    Book searchBook(int code);

    boolean rmBook(int code);

    @Override
    String toString();
}
