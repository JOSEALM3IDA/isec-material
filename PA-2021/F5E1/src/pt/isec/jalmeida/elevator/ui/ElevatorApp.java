package pt.isec.jalmeida.elevator.ui;

import pt.isec.jalmeida.elevator.logic.StateMachine;
import pt.isec.jalmeida.elevator.ui.text.ElevatorUI;

public class ElevatorApp {

    public static void main(String[] args) {
        StateMachine stateMachine = new StateMachine();
        ElevatorUI elevatorUI = new ElevatorUI(stateMachine);
        elevatorUI.start();
    }
}

