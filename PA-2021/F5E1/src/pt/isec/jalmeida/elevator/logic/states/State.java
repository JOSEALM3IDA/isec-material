package pt.isec.jalmeida.elevator.logic.states;

import pt.isec.jalmeida.elevator.logic.Situation;

public interface State {
    State up();

    State down();

    Situation getSituation();
}
