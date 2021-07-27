package pt.isec.jalmeida.elevator.logic.states;

import pt.isec.jalmeida.elevator.logic.Situation;
import pt.isec.jalmeida.elevator.logic.data.Elevator;

public class Floor2 extends StateAdapter {

    public Floor2(Elevator elevator) {
        super(elevator);
        elevator.remember("Floor 2");
    }

    @Override
    public State down() {
        elevator.remember("Going Down");
        return new Floor1(elevator);
    }

    @Override
    public Situation getSituation() { return Situation.Floor2; }
}
