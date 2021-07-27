package pt.isec.jalmeida.balls;

import pt.isec.jalmeida.balls.logic.states.StateMachine;
import pt.isec.jalmeida.balls.ui.GameUI;

public class Main {
    public static void main(String[] args) {
        StateMachine stateMachine = new StateMachine();
        GameUI gameUI = new GameUI(stateMachine);
        gameUI.start();
    }
}
