package pt.isec.jalmeida.elevator.logic.states;

import pt.isec.jalmeida.elevator.logic.Situation;
import pt.isec.jalmeida.elevator.logic.data.Elevator;

public class Floor1 extends StateAdapter {

    public Floor1(Elevator elevator) {
        super(elevator);
        elevator.remember("Floor 1");
    }

    @Override
    public State up() {
        elevator.remember("Going Up");
        return new Floor2(elevator);
    }

    @Override
    public State down() {
        elevator.remember("Going Down");
        return new Floor0(elevator);
    }

    @Override
    public Situation getSituation() {
        return Situation.Floor1;
    }

}
