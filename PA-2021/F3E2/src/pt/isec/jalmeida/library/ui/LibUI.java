package pt.isec.jalmeida.library.ui;

import pt.isec.jalmeida.library.model.Book;
import pt.isec.jalmeida.library.model.Library;

import java.util.ArrayList;
import java.util.Scanner;

public class LibUI {
    Library lib;
    Scanner sc;

    public LibUI(Library lib) {
        this.lib = lib;
        sc = new Scanner(System.in);
    }

    int getInt(String question) {
        System.out.print(question);
        while (!sc.hasNextInt())
            sc.next();
        int val = sc.nextInt();
        sc.nextLine();
        return val;
    }

    String getStr(String question) {
        String ans;
        do {
            System.out.print(question);
            ans = sc.nextLine().trim();
        } while (ans.isEmpty());
        return ans;
    }

    void addBook() {
        String title = getStr("Book title: \n> ");
        String author;
        ArrayList<String> authors = new ArrayList<>();
        do {
            author = getStr("Author ['exit' to exit]:\n> ");
            if (author != null && !author.equalsIgnoreCase("exit"))
                authors.add(author);
        } while (!author.equalsIgnoreCase("exit"));

        System.out.println("Book created with code " + lib.addBook(title, authors));
    }

    void searchBook() {
        int code = getInt("Code of the book to search: ");
        Book book = lib.searchBook(code);
        if (book == null)
            System.out.println("Book code not found");
        else
            System.out.println("Book found: " + book);
    }

    void rmBook() {
        int code = getInt("Code of book to remove: ");
        boolean rmd = lib.rmBook(code);
        if (!rmd)
            System.out.println("Book code not found");
        else
            System.out.println("Book removed");
    }

    int chooseOpt(String... opts) {
        int opt;
        do {
            for (int i = 0; i < opts.length; i++)
                System.out.printf("%3d - %s\n", i+1, opts[i]);
            opt = getInt("\n> ");
        } while (opt < 1 || opt > opts.length);
        return opt;
    }

    public void start() {
        while (true) {
            System.out.print('\n');
            switch (chooseOpt("Add Book", "Search Book",
                    "Remove Book", "List", "Add duplicated book", "Exit")) {
                case 1:
                    addBook();
                    break;
                case 2:
                    searchBook();
                    break;
                case 3:
                    rmBook();
                    break;
                case 4:
                    System.out.println(lib.toString());
                    break;
                case 5:
                    Book b = lib.searchBook(1);
                    if (b != null) {
                        if (lib.addBook(b) < 0)
                            System.out.println("Error adding book");
                        else
                            System.out.println("Book added successfully");
                    }
                    break;
                case 6:
                    return;
            }
        }
    }

}
