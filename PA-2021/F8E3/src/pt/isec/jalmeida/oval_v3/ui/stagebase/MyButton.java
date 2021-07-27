package pt.isec.jalmeida.oval_v3.ui.stagebase;

import javafx.scene.control.Button;
import pt.isec.jalmeida.oval_v3.ui.UIConstantes;

public class MyButton extends Button {

    public MyButton() { setSize();}

    public MyButton(String s) { super(s); setPrefHeight(UIConstantes.TAM_BTN); }

    public void setSize() { this.setPrefSize(UIConstantes.TAM_BTN, UIConstantes.TAM_BTN); }
}