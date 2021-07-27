package pt.isec.jalmeida.balls.logic.states;

import pt.isec.jalmeida.balls.logic.BallType;
import pt.isec.jalmeida.balls.logic.Game;

public class WaitForLoseDecision extends StateAdapter {

    protected WaitForLoseDecision(Game game) {
        super(game);
    }

    @Override
    public State rm2BallsFromBag() {
        for (int i = 0; i < 2; i++) {
            BallType b = game.getBallFromBag();
            if (b == BallType.Black)
                game.returnBalls(1, BallType.Black);
            else if (b == BallType.White)
                game.rmWhite();
            else
                return new End(game);

            if (game.isBagEmpty())
                return new End(game);
        }

        return new WaitForBet(game);
    }

    @Override
    public State rmWhiteBallWon() {
        if (!game.loseWhite())
            return this;
        game.rmWhite();
        return new WaitForBet(game);
    }

    @Override
    public Situation getSituation() {
        return Situation.WaitForLoseDecision;
    }
}
