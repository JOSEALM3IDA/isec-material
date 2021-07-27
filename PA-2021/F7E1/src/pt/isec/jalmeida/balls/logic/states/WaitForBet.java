package pt.isec.jalmeida.balls.logic.states;

import pt.isec.jalmeida.balls.logic.BallType;
import pt.isec.jalmeida.balls.logic.Game;

public class WaitForBet extends StateAdapter {

    protected WaitForBet(Game game) {
        super(game);
    }

    @Override
    public State bet(int nBalls) {
        if (!game.bet(nBalls))
            return this;

        BallType ball = game.getBallFromBag();

        if (ball == BallType.Black) {
            game.loseBet();
            game.rmBlack();
            return new WaitForLoseDecision(game);
        }

        game.winWhiteBall();

        int nWhite = 0;

        for (int i = 0; !game.isBagEmpty() && i < game.getBet(); i++) {
            BallType b = game.getBallFromBag();
            if (b == BallType.White)
                nWhite++;
            else
                game.rmBlack();
        }

        game.returnBalls(nWhite, BallType.White);
        game.recoverBet();
        if (game.isBagEmpty())
            return new End(game);

        return new WaitForBet(game);
    }

    @Override
    public State end() { return new End(game); }

    @Override
    public Situation getSituation() { return Situation.WaitForBet; }
}
