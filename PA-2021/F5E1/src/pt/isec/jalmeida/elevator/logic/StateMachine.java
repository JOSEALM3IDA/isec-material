package pt.isec.jalmeida.elevator.logic;

import pt.isec.jalmeida.elevator.logic.data.Elevator;
import pt.isec.jalmeida.elevator.logic.states.State;
import pt.isec.jalmeida.elevator.logic.states.Floor0;

public class StateMachine {

    State current;
    Elevator elevator;

    public StateMachine() {
        this.elevator = new Elevator();
        current = new Floor0(elevator);
    }

    public void up() {
        current = current.up();
    }

    public void down() {
        current = current.down();
    }

    public Situation getCurrentSituation() { return current.getSituation(); }

    public String getHistory() { return elevator.toString(); }
}
