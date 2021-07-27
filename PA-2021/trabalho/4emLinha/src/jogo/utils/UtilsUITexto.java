package jogo.utils;

import java.util.Scanner;

public class UtilsUITexto {

    private UtilsUITexto() {}

    static Scanner sc = new Scanner(System.in);

    public static int getInteiro(String pergunta) {
        System.out.print(pergunta);

        while (!sc.hasNextInt()) { sc.next(); }

        int valor = sc.nextInt();

        sc.nextLine();

        return valor;
    }

    public static String getResposta(String pergunta) {
        String resposta;
        System.out.println("\n" + pergunta);

        System.out.print("> ");
        resposta = sc.nextLine().trim();

        return resposta;
    }

    public static int getOpcao(String titulo, String... opts) {
        int opt;

        do {
            System.out.println('\n' + titulo);
            for (int i = 0; i < opts.length - 1; i++) {
                if (opts[i].isEmpty()) continue;

                System.out.printf("%3d - %s%n", i + 1, opts[i]);
            }

            System.out.printf("%n%3d - %s%n", 0, opts[opts.length - 1]);

            opt = getInteiro("\n> ");
        } while (opt < 0 || opt >= opts.length);

        return opt;
    }
}
