package pt.isec.jalmeida.balls.logic.states;

import pt.isec.jalmeida.balls.logic.Game;

public class Start extends StateAdapter {

    protected Start(Game game) { super(game); }

    @Override
    public State start() {
        game.startGame();
        return new WaitForBet(game);
    }

    @Override
    public Situation getSituation() {
        return Situation.Start;
    }
}
