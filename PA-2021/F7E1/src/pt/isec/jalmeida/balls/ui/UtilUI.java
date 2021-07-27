package pt.isec.jalmeida.balls.ui;

import java.util.Scanner;

public class UtilUI {

    static Scanner sc;

    static { sc = new Scanner(System.in); }

    public static int getInt(String question) {
        System.out.print(question);
        while (!sc.hasNextInt())
            sc.next();
        int valor = sc.nextInt();
        sc.nextLine();
        return valor;
    }


    public static String getString(String pergunta) {
        String resposta;
        do {
            System.out.print(pergunta);
            resposta = sc.nextLine().trim();
        } while (resposta.isEmpty());
        return resposta;
    }

    public static int getOpt(String... opts) {
        int opt;
        do {
            for (int i = 0; i < opts.length-1; i++)
                System.out.printf("%3d - %s\n", i+1, opts[i]);
            System.out.printf("\n%3d - %s\n", 0, opts[opts.length-1]);
            opt = getInt("\n> ");
        } while (opt <0 || opt >= opts.length);
        return opt;
    }
}
