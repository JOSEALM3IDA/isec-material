package pt.isec.jalmeida.elevator.ui.text;

import pt.isec.jalmeida.elevator.logic.StateMachine;
import pt.isec.jalmeida.elevator.utils.Util;

public class ElevatorUI {

    StateMachine stateMachine;
    boolean exit;

    public ElevatorUI(StateMachine stateMachine) { this.stateMachine = stateMachine; }

    public void start() {
        exit = false;
        while (!exit) {
            System.out.println(stateMachine.getHistory());
            switch (stateMachine.getCurrentSituation()) {
                case Floor0:
                    uiFloor0();
                    break;
                case Floor1:
                    uiFloor1();
                    break;
                case Floor2:
                    uiFloor2();
                    break;
            }
        }
    }

    private void uiFloor0() {
        System.out.println("Floor 0: ");

        switch (Util.chooseOpt("Up", "Exit")) {
            case 1:
                stateMachine.up();
                break;
            default:
                this.exit = true;
                break;
        }

    }

    private void uiFloor1() {
        System.out.println("Floor 1: ");

        switch (Util.chooseOpt("Up", "Down", "Exit")) {
            case 1:
                stateMachine.up();
                break;
            case 2:
                stateMachine.down();
                break;
            default:
                this.exit = true;
                break;
        }
    }

    private void uiFloor2() {
        System.out.println("Floor 2: ");

        switch (Util.chooseOpt("Down", "Exit")) {
            case 1:
                stateMachine.down();
                break;
            default:
                this.exit = true;
                break;
        }
    }
}
