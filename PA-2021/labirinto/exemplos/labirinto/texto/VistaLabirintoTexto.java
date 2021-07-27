package exemplos.labirinto.texto;


import exemplos.labirinto.logica.modelo.GestaoLabirintoGame;

import java.util.List;
import java.util.Scanner;

public class VistaLabirintoTexto {
    private final GestaoLabirintoGame game;
    public VistaLabirintoTexto(GestaoLabirintoGame lg) {
        game = lg;
    }


    public void corre() {
        Scanner sc = new Scanner(System.in);
        char tecla;
        game.inicializa();

        main_loop:
        while (!game.isGameFinished()) {
            imprimeMapa(game.getVisibleMap());
            System.out.println("w=up s=down a=left d=right z=undo y=redo q=quit");
            tecla = sc.next().toLowerCase().charAt(0);
            switch (tecla) {
                case 'w':
                    game.up();
                    break;
                case 's':
                    game.down();
                    break;
                case 'a':
                    game.left();
                    break;
                case 'd':
                    game.right();
                    break;
                case 'z':
                    game.undo();
                    break;
                case 'y':
                    game.redo();
                    break;
                case 'q':
                    break main_loop;
                default:
                    System.out.println("?????");
                    break;
            }
        }
        if (game.isGameFinished())
            System.out.println("parabens - saiste do labirinto");
    }

    private void imprimeMapa(List<String> mapavis) {
        for (String s : mapavis)
            System.out.println(s);
    }

}
