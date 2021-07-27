package pt.isec.jalmeida.hangman;

import java.util.Scanner;

public class HangmanUI {
    HangmanModel game;

    public HangmanUI(HangmanModel game) {
        this.game = game;
    }

    public void jogar() {
        Scanner sc = new Scanner(System.in);
        String ch;

        while(!game.finished()) {

            System.out.println(game.getSituation()); // se a palavra for CAFE, inicialmente mostrar ....
            System.out.println();
            System.out.println("Tries made: " + game.getTries());
            System.out.println("Tries left: " + game.getTriesLeft());
            System.out.println("Letters played: " + game.getUsed());
            System.out.println();

            System.out.print("Letter (or words complete with " + game.getSituation().length() + " letters to finish): ");
            ch = sc.next().toUpperCase();
            ch = ch.trim();
            game.tryLetter(ch);
            System.out.println();
        }

        if (game.gotItRight())
            System.out.println("Good job, you got the word \"" + game.getWord() + "\" in " + game.getTries() + " tries!");
        else
            System.out.println("After " + game.getTries() + " tries, you didn't get the word \"" + game.getWord() + "\" right :(");

        }
}
