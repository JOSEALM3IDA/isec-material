package pt.isec.jalmeida.elevator.logic.states;

import pt.isec.jalmeida.elevator.logic.Situation;
import pt.isec.jalmeida.elevator.logic.data.Elevator;

public class Floor0 extends StateAdapter {

    public Floor0(Elevator elevator) {
        super(elevator);
        elevator.remember("Floor 0");
    }

    @Override
    public State up() {
        elevator.remember("Going Up");
        return new Floor1(elevator);
    }

    @Override
    public Situation getSituation() { return Situation.Floor0; }
}
