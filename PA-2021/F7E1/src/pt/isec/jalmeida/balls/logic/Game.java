package pt.isec.jalmeida.balls.logic;

import java.util.ArrayList;
import java.util.Collections;

public class Game {
    public static final int NR_WHITE = 10;
    public static final int NR_BLACK  = 10;
    ArrayList<BallType> bag;
    int nrWhiteBallsWon, nrBlackBallsOut, nrWhiteBallsOut;
    int bet;

    public Game() {
        startGame();
    }

    public void startGame() {
        bag = new ArrayList<>();
        bag.addAll(Collections.nCopies(NR_WHITE, BallType.White));
        bag.addAll(Collections.nCopies(NR_BLACK, BallType.Black));
        nrWhiteBallsWon = 0;
        nrBlackBallsOut = 0;
        nrWhiteBallsOut = 0;
        bet = 0;
        Collections.shuffle(bag);
    }

    public int getNrWhiteBallsWon() { return nrWhiteBallsWon; }
    public int getNrBlackBallsOut() { return nrBlackBallsOut; }
    public int getNrWhiteBallsOut() { return nrWhiteBallsOut; }
    public int getBet() { return bet; }

    public boolean isBagEmpty() { return bag.isEmpty(); }

    public boolean bet(int balls) {
        if (balls > nrWhiteBallsWon) { return false; }

        nrWhiteBallsWon -= balls;
        bet = balls;
        return true;
    }

    public void loseBet() {
        // nrBolasBrancasGanhas -= aposta; //se não fossem antes retiradas
    }

    public void recoverBet() { nrWhiteBallsWon += bet; }
    public void winWhiteBall() { nrWhiteBallsWon++; }

    public boolean loseWhite() {
        if (nrWhiteBallsWon < 1)
            return false;
        nrWhiteBallsWon--;
        return true;
    }

    public void rmBlack() { nrBlackBallsOut++; }
    public void rmWhite() { nrWhiteBallsOut++; }

    public void returnBalls(int nr, BallType type) {
        if (nr > 0)
            bag.addAll(Collections.nCopies(nr, type));
        Collections.shuffle(bag);
    }

    public BallType getBallFromBag() {
        if (bag.isEmpty()) { return BallType.none; }

        return bag.remove(0);
    }

    @Override
    public String toString() {
        return "Game{" +
                "bag=" + bag +
                ", nrWhiteBallsWon=" + nrWhiteBallsWon +
                ", nrBlackBallsOut=" + nrBlackBallsOut +
                ", nrWhiteBallsOut=" + nrWhiteBallsOut +
                ", bet=" + bet +
                '}';
    }
}
