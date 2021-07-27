package jogo;

import javafx.application.Application;
import jogo.iu.gui.QuatroEmLinhaUIGrafica;
import jogo.logica.QuatroEmLinhaMaquinaEstados;
import jogo.iu.texto.QuatroEmLinhaUITexto;
import jogo.utils.UtilsUITexto;

public class QuatroEmLinhaApp {
    public static void main(String[] args) {

        switch (UtilsUITexto.getOpcao("UI:", "Texto", "Gráfica", "Sair")) {
            case 1 -> {
                QuatroEmLinhaMaquinaEstados maquinaEstados = new QuatroEmLinhaMaquinaEstados();
                QuatroEmLinhaUITexto uiTexto = new QuatroEmLinhaUITexto(maquinaEstados);
                uiTexto.comecar();
            }
            case 2 -> Application.launch(QuatroEmLinhaUIGrafica.class, args);

            default -> System.out.println("Até à próxima!");
        }

    }
}
