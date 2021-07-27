package pt.isec.jalmeida.balls.logic.states;

import pt.isec.jalmeida.balls.logic.Game;

public class StateMachine {
    State actual;
    Game game;

    public StateMachine() {
        this.game = new Game();
        this.actual = new Start(game);
        System.out.println(game.toString());
        System.out.println(actual.toString());
    }

    public void start() { actual = actual.start(); }
    public void bet(int nBalls) { actual = actual.bet(nBalls); }
    public void rm2BallsBag() { actual = actual.rm2BallsFromBag(); }
    public void rmWhiteBallWon() { actual = actual.rmWhiteBallWon(); }
    public void end() { actual = actual.end(); }
    public Situation getSituation() { return actual.getSituation(); }

    public int getNrWhiteBallsWon() { return game.getNrWhiteBallsWon(); }

    public String getSituationGame() { return "IDK"; }

}
