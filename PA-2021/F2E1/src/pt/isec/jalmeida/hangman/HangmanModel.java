package pt.isec.jalmeida.hangman;

import java.util.Random;

public class HangmanModel {
    public static final int MAX_TRIES = 7;

    private String word; // Word to find
    private StringBuffer situation; // State of the discovery of the word
    private StringBuilder used; // Letters used at the moment
    private int tries, successes;

    public HangmanModel() {
        start();
    }

    private void start() {
        this.tries = this.successes = 0;
        Random rand = new Random();
        this.word = HangmanDictionary.getPalavra(rand.nextInt(HangmanDictionary.getTamanho()));

        assert this.word != null;
        this.word = this.word.toUpperCase();
        this.situation = new StringBuffer(".".repeat(word.length()));

        this.used = new StringBuilder();
    }

    public boolean gotItRight() {
        return situation.toString().equalsIgnoreCase(word);
    }

    public boolean finished() {
        return gotItRight() || getTriesLeft() <= 0;
    }

    public void tryLetter(String str) {
        if (finished() || str.isEmpty()) return;

        tries++;
        str = str.toUpperCase();

        if (str.length() > 1 && word.equals(str)) {
            situation = new StringBuffer(word);
            return;
        }

        char ch = str.charAt(0);
        used.append(ch);

        boolean found = false;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                situation.setCharAt(i, ch);
                found = true;
            }

        }

        if (found) successes++;
    }

    public String getSituation() {
        return situation.toString();
    }

    public int getTriesLeft() {
        return MAX_TRIES - tries + successes;
    }

    public int getTries() {
        return tries;
    }

    public int getSuccesses() {
        return successes;
    }

    public String getUsed() {
        return used.toString();
    }

    public String getWord() {
        return word;
    }
}
