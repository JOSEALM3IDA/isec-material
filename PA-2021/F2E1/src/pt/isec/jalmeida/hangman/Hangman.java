package pt.isec.jalmeida.hangman;

public class Hangman {
    public static void main(String[] args) {
        HangmanModel game = new HangmanModel();
        HangmanUI gameUI = new HangmanUI(game);

        gameUI.jogar();
    }
}
