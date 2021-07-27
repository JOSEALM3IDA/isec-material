package exemplos.labirinto.logica.modelo;

import java.util.ArrayList;
import java.util.List;

public class LabirintoGame {
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

    public LabirintoGame(double vr) {
        visRadius  = vr;
        inicializa();
    }

    public void inicializa() {
        lin = 7;
        col = 9;
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

    private void checkGameFinished() {
        if (lin == 0 || lin == NLIN || col == 0 || col == NCOL)
            gameFinished = true;
    }
    // -------------------------

    boolean move(int dy,int dx) {
        if (gameFinished)
            return false;
        if (lin + dy < 0 || lin + dy >= NLIN ||
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
