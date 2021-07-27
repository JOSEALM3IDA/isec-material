package pt.isec.jalmeida.library.model;

import java.util.*;

public class LibrarySet implements Library {
    private String name;
    private Set<Book> books;

    public LibrarySet(String name) {
        this.name = name;
        this.books = new HashSet<>();
    }

    @Override
    public int addBook(Book b) {
        if (!books.add(b))
            return -1;
        return b.getCode();
    }

    @Override
    public int addBook(String title, List<String> authors) {
        Book newBook = new Book(title, authors);
        if (!books.add(newBook))
            return -1;
        return newBook.getCode();
    }

    @Override
    public Book searchBook(int code) {
        for (Book b : books) {
            if (b.getCode() == code)
                return b;
        }
        return null;
    }

    @Override
    public boolean rmBook(int code) {
        return books.remove(new Book(code));
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
        List<Book> list = new ArrayList<>(books);
        Collections.sort(list);

        Iterator<Book> it = list.iterator();
        while (it.hasNext()) {
            sb.append("\n\t- ");
            sb.append(it.next().toString());
        }

        return sb.toString();
    }
}
