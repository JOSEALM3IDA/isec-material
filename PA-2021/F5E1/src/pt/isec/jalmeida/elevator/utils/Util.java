package pt.isec.jalmeida.elevator.utils;

import java.util.Scanner;

public final class Util {
    static Scanner sc;

    static { sc = new Scanner(System.in); }

    private Util() {}

    public static int getInt(String question) {
        System.out.print(question);
        while (!sc.hasNextInt())
            sc.next();
        int value = sc.nextInt();
        sc.nextLine();
        return value;
    }

    public static String getString(String question) {
        String ans;
        do {
            System.out.print(question);
            ans = sc.nextLine().trim();
        } while (ans.isEmpty());
        return ans;
    }

    public static int chooseOpt(String... opts) {
        int opt;
        do {
            for (int i = 0; i < opts.length-1; i++)
                System.out.printf("%3d - %s\n",i+1, opts[i]);
            System.out.printf("\n%3d - %s\n",0,opts[opts.length-1]);
            opt = getInt("\n> ");
        } while (opt<0 || opt>=opts.length);
        return opt;
    }
}

