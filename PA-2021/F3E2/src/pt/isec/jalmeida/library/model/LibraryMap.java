package pt.isec.jalmeida.library.model;

import java.util.*;

public class LibraryMap implements Library {
    private String name;
    private Map<Integer, Book> books;

    public LibraryMap(String name) {
        this.name = name;
        this.books = new HashMap<>();
    }

    @Override
    public int addBook(Book b) {
        if (books.containsValue(b))
            return -1;

        books.put(b.getCode(), b);
        return b.getCode();
    }

    @Override
    public int addBook(String title, List<String> authors) {
        Book newBook = new Book(title, authors);
        books.put(newBook.getCode(), newBook);
        return newBook.getCode();
    }

    @Override
    public Book searchBook(int code) {
        return books.get(code);
    }

    @Override
    public boolean rmBook(int code) {
        return books.remove(code) != null;
    }

    class CompareTitle implements Comparator<Book> {
        @Override
        public int compare(Book o1, Book o2) {
            return o1.getTitle().compareTo(o2.getTitle());
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(String.format("Library %s: ", name));
        List<Book> list = new ArrayList<>(books.values());
        Collections.sort(list);

        Iterator<Book> it = list.iterator();
        while (it.hasNext()) {
            sb.append("\n\t- ");
            sb.append(it.next().toString());
        }

        return sb.toString();
    }
}
