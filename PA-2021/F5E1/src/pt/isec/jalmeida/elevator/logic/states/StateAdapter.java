package pt.isec.jalmeida.elevator.logic.states;

import pt.isec.jalmeida.elevator.logic.data.Elevator;
import pt.isec.jalmeida.elevator.logic.states.State;

abstract class StateAdapter implements State {

    protected Elevator elevator;

    public StateAdapter(Elevator elevator) { this.elevator = elevator; }

    @Override
    public State up() {
        return this;
    }

    @Override
    public State down() {
        return this;
    }
}
