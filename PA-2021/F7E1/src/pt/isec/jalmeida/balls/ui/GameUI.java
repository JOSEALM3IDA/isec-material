package pt.isec.jalmeida.balls.ui;

import pt.isec.jalmeida.balls.logic.states.StateMachine;

public class GameUI {
    StateMachine sm;
    boolean leave;

    public GameUI(StateMachine sm) {
        this.sm = sm;
    }

    public void start() {
        leave = false;
        while (!leave) {
            switch (sm.getSituation()) {
                case Start -> startUI();
                case WaitForBet -> waitForBetUI();
                case WaitForLoseDecision -> waitForLoseDecisionUI();
                case End -> endUI();
            }
        }

    }


    private void startUI() {
        int opt = UtilUI.getOpt("Start", "Exit");
        switch (opt) {
            case 1 -> sm.start();
            default -> leave = true;
        }
    }

    private void waitForBetUI() {
        int opt = UtilUI.getOpt("Bet", "End", "Exit");
        switch (opt) {
            case 1 -> {
                int amount;
                do {
                    amount = UtilUI.getInt("Insert the number of white balls you want to bet [0 ... "
                            + sm.getNrWhiteBallsWon() + "]: ");
                } while (amount < 0 || amount > sm.getNrWhiteBallsWon());

                sm.bet(amount);
            }
            case 2 -> sm.end();
            case 3 -> leave = true;
        }
    }

    private void waitForLoseDecisionUI() {
        System.out.println("A black ball was drawn. You lost the bet.");
        switch (UtilUI.getOpt("Lose white", "Remove 2 balls from bag", "Exit")) {
            case 1 -> sm.rmWhiteBallWon();
            case 2 -> sm.rm2BallsBag();
            default -> leave = true;
        }
    }

    private void endUI() {
        System.out.println("The game ended.");
        System.out.println("You won " + sm.getNrWhiteBallsWon() + " white balls!\n\n");

        switch (UtilUI.getOpt("Start", "Exit")) {
            case 1 -> sm.start();
            default -> leave = true;
        }
    }


}
