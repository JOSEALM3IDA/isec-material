
package bw.iu.gui;

import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;

public class ConstantesGUI {
    private ConstantesGUI() { }

    public static int DIM_X_BOLA = 20;
    public static int DIM_Y_BOLA = 20;

    public static int BORDER_X = 10;
    public static int BORDER_Y = 10;

    public static int GAP_X_BOLAS = 10;
    public static int GAP_Y_BOLAS = 10;

    public static int DIM_X_SACO = 250, DIM_Y_SACO = 200;
    public static int N_COL_SACO = 5;
    public static int DIM_X_PONTUACAO = 320;
    public static int DIM_Y_PONTUACAO = 2*(DIM_Y_BOLA) + GAP_Y_BOLAS + 2*BORDER_Y;
    public static int N_COL_PONTUACAO = 10;

    public static int BOLAS_REMOVIDAS_X = 320;
    public static int BOLAS_REMOVIDAS_Y = 2*(DIM_Y_BOLA) + 1* GAP_Y_BOLAS + 2*BORDER_Y;


    public static int LEFT_VBOX_X = 280;
    public static int LEFT_VBOX_Y = 230;

    public static int DIM_X_FRAME = 670;
    public static int DIM_Y_FRAME = 330;

    public static int DIM_X_BOTTOM_PANEL = DIM_X_FRAME;
    public static int DIM_Y_BOTTOM_PANEL = 65;


    public static String BOLA_BRANCA = "white.gif";

    public static String BOLA_PRETA = "black.gif";

    public static String BACKGROUND_BALL = "background.png";

    public static Font LETRA = Font.font("verdana", FontWeight.NORMAL, FontPosture.ITALIC, 14);
    
}
