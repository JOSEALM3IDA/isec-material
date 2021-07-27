package bw.iu.texto;



import bw.logica.JogoMaqEstados;
import bw.logica.Situacao;

import java.util.Scanner;

public class IUTexto {
    private JogoMaqEstados jogoMaqEstados;
    private Scanner s = new Scanner(System.in);
    private boolean sair = false;

    public IUTexto(JogoMaqEstados game) {
        jogoMaqEstados = game;
    }

    private void iuAguardaInicio() {
        int value;

        System.out.println("1-Comecar Jogo");
        System.out.print("> ");

        while (!s.hasNextInt()) s.next();

        value = s.nextInt();

        if (value == 1)
            jogoMaqEstados.comecarJogo();
    }

    private void iuAguardaAposta() {
        int value;

        System.out.println("\n\n---------------------------------");
        System.out.println(jogoMaqEstados);

        System.out.println();
        System.out.println("Apostar ate " + jogoMaqEstados.getPontuacao() + " ponto(s) ou -1 para terminar");
        System.out.print("> ");

        while (!s.hasNextInt()) s.next();

        value = s.nextInt();

        if (value >= 0) {
            jogoMaqEstados.apostar(value);
        } else {
            jogoMaqEstados.terminar();
        }

    }

    private void iuAguardaOpcao() {
        int value;

        System.out.println("\n\n---------------------------------");
        System.out.println(jogoMaqEstados);

        System.out.println();
        System.out.println("Saiu bola preta");
        System.out.println();
        System.out.println("1-Perder um ponto");
        System.out.println("2-Remover duas bolas do saco (as pretas voltam para o saco e as brancas sao removidas do jogo)");
        System.out.print("> ");

        while (!s.hasNextInt()) s.next();

        value = s.nextInt();

        if (value == 1) {
            jogoMaqEstados.escolherOpcaoPerderPontuacao();
        } else if (value == 2) {
            jogoMaqEstados.escolherOpcaoRetirarDuasBolas();
        }

    }

    private void iuFinalJogo() {
        int value;

        System.out.println("1-Jogar de novo");
        System.out.println("2-Sair");
        System.out.print("> ");

        while (!s.hasNextInt()) s.next();

        value = s.nextInt();

        if (value == 1) {
            jogoMaqEstados.comecarJogo();
        } else if (value == 2) {
            sair = true;
        }
    }

    public void corre() {

        while (!sair) {

            if (jogoMaqEstados.getMsgLog().size() > 0) {

                System.out.println();

                for (String msg : jogoMaqEstados.getMsgLog()) {
                    System.out.println("---> " + msg);
                }

                jogoMaqEstados.clearMsgLog();

            }
            Situacao situacao = jogoMaqEstados.getSituacaoAtual();

            switch (situacao) {
                case AGUARDA_INICIO:
                    iuAguardaInicio();
                    break;
                case AGUARDA_APOSTA:
                    iuAguardaAposta();
                    break;
                case AGUARDA_OPCAO:
                    iuAguardaOpcao();
                    break;
                case FINAL_JOGO:
                    iuFinalJogo();
                    break;
                default:
                    System.out.println("Fora de controlo");
                    break;
            }
        }

        System.out.println();
        System.out.println("************** Final Jogo *****************");
        System.out.println(jogoMaqEstados);

    }
}
