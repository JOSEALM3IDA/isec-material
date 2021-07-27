package pt.isec.jalmeida.f1e2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int menor = 1, maior = 100, hipotese, ans;

        do {
            hipotese = (maior + menor)/2;

            System.out.println("O número é o " + hipotese + " ? [ 0 - SIM; 1 - NÃO, É MENOR; 2 - NÃO, É MAIOR ]");

            try {
                ans = sc.nextInt();
            } catch (Exception e) {
                ans = -1;
            }

            switch (ans) {
                case 1 -> maior = hipotese - 1;
                case 2 -> menor = hipotese + 1;
                default -> System.out.println("Erro desconhecido!");
            }
        } while (ans != 0 && maior >= menor);

        if (ans == 0)
            System.out.println("Ok... descobri... o numero era: " + hipotese);
        else
            System.out.println("Mentiroso!!!!!");
    }
}
