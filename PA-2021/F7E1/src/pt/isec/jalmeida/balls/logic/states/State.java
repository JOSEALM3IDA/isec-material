package pt.isec.jalmeida.balls.logic.states;

import pt.isec.jalmeida.balls.logic.Game;

public interface State {
    State start();
    State bet(int nBalls);
    State rm2BallsFromBag();
    State rmWhiteBallWon();
    State end();

    Situation getSituation();
}

