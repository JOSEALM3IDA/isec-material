package pt.isec.jalmeida.balls.logic.states;

import pt.isec.jalmeida.balls.logic.Game;

public abstract class StateAdapter implements State {
    protected Game game;

    protected StateAdapter(Game game) { this.game = game; }

    @Override
    public State start() {
        return null;
    }

    @Override
    public State bet(int nBalls) {
        return null;
    }

    @Override
    public State rm2BallsFromBag() {
        return null;
    }

    @Override
    public State rmWhiteBallWon() {
        return null;
    }

    @Override
    public State end() {
        return null;
    }

    public abstract Situation getSituation();
}
