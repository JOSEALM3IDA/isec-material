package pt.isec.jalmeida.f3e4;

public class Main {
    public static void main(String[] args) {
        Dictionary d = new Dictionary();
        d.add("english", "LIVRO", "Book");
        d.add("french", "LIVRO", "livre");
        d.add("portuguese", "LIVRO", "livro");
        d.add("english", "ANO", "year");
        d.add("french", "ANO", "an");
        d.add("portuguese", "ANO", "ano");

        if (d.defineLang("english"))
            System.out.println(d.get("ANO")); // year
        if (d.defineLang("portuguese"))
            System.out.println(d.get("ANO")); // ano
        if (d.defineLang("french"))
            System.out.println(d.get("LIVRO")); // livre
    }
}