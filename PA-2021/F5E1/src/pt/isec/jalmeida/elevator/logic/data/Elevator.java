package pt.isec.jalmeida.elevator.logic.data;

import java.util.ArrayList;

public class Elevator {
    ArrayList<String> history;

    public Elevator() { history = new ArrayList<>(); }

    public void remember(String evolution) { history.add(evolution); }

    @Override
    public String toString() { return history.toString(); }
}
