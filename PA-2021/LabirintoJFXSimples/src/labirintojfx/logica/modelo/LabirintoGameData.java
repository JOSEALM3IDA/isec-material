package labirintojfx.logica.modelo;

import java.util.ArrayList;
import java.util.List;

public class LabirintoGameData {
    int NCOL = 20, NLIN = 15;
    private static String[] lab = {
        "######### ##########",
        "#       #     #    #",
        "# ########### #### #",
        "#       # ### #    #",
        "# ##### #  #  #### #",
        "# #     ## # ##    #",
        "# ## ##### # ## ####",
        "# #                #",
        "###### ########### #",
        "# # ## #    #      #",
        "### ## # #### ######",
        "# # ## # # ## #    #",
        "# # ## ###### #### #",
        "#                  #",
        "####################"
    };

    double visRadius;
    int lin,col;
    boolean gameFinished;
    String jogador;

    public LabirintoGameData() {
        inicializa("???",1);
    }

    public boolean inicializa(String nome, int dif) {
        lin = 7;
        col = 9;
        if (nome == null)
            return false;
        nome = nome.trim();
        if (nome.length() == 0)
            return false;
        jogador = nome;
        if (dif <0 || dif > 20)
            return false;
        visRadius  = 10-(dif/2);
        gameFinished = false;
        return true;
    }

    public boolean isGameFinished() {
        return gameFinished;
    }

    public List<String> getVisibleMap() {
        StringBuilder[] sbmat = new StringBuilder[NLIN];
        for (int i=0; i< NLIN; i++)
            sbmat[i] = new StringBuilder(lab[i]);
        for (int l=0; l<NLIN; l++)
            for (int c=0; c < NCOL; c++) {
                double dist = Math.sqrt( (l-lin)*(l-lin) + (c-col)*(c-col)) ;
                if (dist > visRadius)
                    sbmat[l].setCharAt(c,'.');
            }
        sbmat[lin].setCharAt(col,'X');
        List<String> res = new ArrayList();
        for (StringBuilder sb : sbmat)
            res.add(sb.toString());
        return res;
    }

    public String getNomeJogador() { return jogador; }

    private void checkGameFinished() {
        if (lin == 0 || lin == NLIN-1 || col == 0 || col == NCOL-1)
            gameFinished = true;
    }

    // -------------------------

    boolean move(int dy,int dx) {
        if (gameFinished)
            return false;
        if (Math.abs(dx)>1 || Math.abs(dy)>1 ||
                lin + dy < 0 || lin + dy >= NLIN ||
                col + dx < 0 || col + dx >= NCOL )
            return false;
        if (lab[lin+dy].charAt(col+dx) == '#')
            return false;
        lin += dy;
        col += dx;
        checkGameFinished();
        return true;
    }

    public boolean up() {
        return move(-1,0);
    }

    public boolean down()  {
        return move(1,0);
    }

    public boolean left() {
        return move(0,-1);
    }

    public boolean right() {
        return move(0,1);
    }

}
