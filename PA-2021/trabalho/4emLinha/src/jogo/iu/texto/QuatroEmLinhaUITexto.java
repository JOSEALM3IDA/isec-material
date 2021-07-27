package jogo.iu.texto;

import jogo.logica.QuatroEmLinhaMaquinaEstados;
import jogo.logica.dados.tabuleiro.TipoFicha;
import jogo.logica.dados.jogadores.TipoJogador;
import jogo.utils.Constantes;
import jogo.utils.UtilsUITexto;
import jogo.utils.Utils;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class QuatroEmLinhaUITexto {

    private final QuatroEmLinhaMaquinaEstados maquinaEstados;
    private boolean doSair;

    public QuatroEmLinhaUITexto(QuatroEmLinhaMaquinaEstados maquinaEstados) { this.maquinaEstados = maquinaEstados; }

    public void comecar() {
        System.out.println("***Bem vindo ao Quatro em Linha!***");

        doSair = false;
        while (!doSair) {
            switch (maquinaEstados.getSituacao()) {
                case PedeDecisaoInicio -> pedeDecisaoInicioUI();
                case PedeConfiguracao -> pedeConfiguracaoUI();
                case PedeDecisaoJogada -> pedeDecisaoJogadaUI();
                case JogaMinijogo -> jogaMinijogoUI();
                case FimJogo -> fimJogoUI();
                case AssisteJogada -> assisteJogadaUI();
            }
        }
    }



    ///////////////////// UIs PRIMÁRIAS /////////////////////

    private void pedeDecisaoInicioUI() {
        switch (UtilsUITexto.getOpcao("--- MENU INICIAL ---",
                "Iniciar Jogo", "Continuar Jogo", "Ver Replay", "Sair")) {
            case 1 -> maquinaEstados.iniciarJogo();
            case 2 -> pedeLoadUI();
            case 3 -> pedeReplayUI();
            default -> doSair = true;
        }

    }

    private void pedeConfiguracaoUI() {

        switch (UtilsUITexto.getOpcao("Jogador " + (maquinaEstados.getNumJogadores() + 1) + ":",
                "Humano", "Computador", "Sair")) {
            case 1 -> adicionaJogadorUI(TipoJogador.HUMANO);
            case 2 -> adicionaJogadorUI(TipoJogador.COMPUTADOR);
            default -> doSair = true;
        }

        if (!doSair) System.out.println("\n" + maquinaEstados.getConfigJogadores());
    }

    private void adicionaJogadorUI(TipoJogador computador) {
        String nomeJogador;
        nomeJogador = pedeNomeJogadorUI();

        if (nomeJogador.isEmpty()) return;

        maquinaEstados.adicionarJogador(computador, nomeJogador);
    }

    private void pedeDecisaoJogadaUI() {

        System.out.println();
        printTabuleiro(maquinaEstados.getTabuleiro());
        System.out.println();

        printJogadorAtual();

        if (maquinaEstados.isComputadorAJogar()) {
            int jogada = maquinaEstados.getJogadaAutomatica();
            String nomeJogadorAtual = maquinaEstados.getNomeJogadorAtual();
            maquinaEstados.jogarFicha(jogada);
            System.out.println("\nO jogador " + nomeJogadorAtual + " jogou na coluna " + (jogada + 1) + "!");
            try { TimeUnit.MILLISECONDS.sleep(Constantes.MILISEGUNDOS_SLEEP_JOGADA_COMPUTADOR); }
            catch (InterruptedException ie) { Thread.currentThread().interrupt(); }

            return;
        }

        String[] opcoes = getOpcoesDecisaoJogada();

        switch (UtilsUITexto.getOpcao("--- PEDE JOGADA ---", opcoes)) {
            case 1 -> pedeFichaColunaUI();
            case 2 -> gravaJogoUI();
            case 3 -> voltaAtrasUI();
            case 4 -> maquinaEstados.aceitarMinijogo();
            case 5 -> maquinaEstados.jogarFichaEspecial(UtilsUITexto.getInteiro("\nColuna a remover: ") - 1);
            default -> maquinaEstados.desistir();
        }
    }

    private void gravaJogoUI() {

        while (true) {
            String fileName = UtilsUITexto.getResposta("Nome do ficheiro: ");

            if (fileName.isEmpty()) return;

            if (maquinaEstados.gravarJogo(Constantes.SAVE_PATH + fileName)) break;

            System.out.println("Save falhou.");
        }

        System.out.println("Save com sucesso!");
    }

    private void jogaMinijogoUI() {

        String pergunta = maquinaEstados.getPerguntaMinijogo();
        String resposta;

        do {
            resposta = UtilsUITexto.getResposta(pergunta);

            if (maquinaEstados.isAcabadoMinijogo()) break;

        } while (!maquinaEstados.isValidaRespostaMinijogo(resposta));


        maquinaEstados.enviarRespostaMinijogo(resposta);

        if (!maquinaEstados.isAcabadoMinijogo()) return;

        if (maquinaEstados.ganhouUltimoMinijogo()) {
            System.out.println("\nGanhou o minijogo e recebeu uma peça especial!");
            return;
        }

        System.out.println("\nAcabou o tempo e perdeu o minijogo. Pontuação final: " +
                maquinaEstados.getPontuacaoAtualMinijogo());
    }

    private void fimJogoUI() {

        System.out.println("\n--- FIM JOGO ---\n");

        printTabuleiro(maquinaEstados.getTabuleiro());

        printResultadoJogo();

        if (UtilsUITexto.getOpcao("O que pretende fazer?", "Voltar ao menu", "Sair") == 1) {
            maquinaEstados.voltar();
            return;
        }

        doSair = true;
    }

    private void assisteJogadaUI() {

        String descricao = maquinaEstados.getDescricaoComandoAtual();
        maquinaEstados.avancar();

        System.out.println("\n" + descricao + "\n");

        printTabuleiro(maquinaEstados.getTabuleiro());

        System.out.print("\nEnter para continuar...");
        try{ System.in.read(); } catch(IOException ioe) { /* ignored */ }
    }


    ///////////////////// UIs SECUNDÁRIAS /////////////////////

    private void pedeFichaColunaUI() {
        int coluna;

        while (true) {
            coluna = UtilsUITexto.getInteiro("\nColuna a jogar: ");

            if (coluna == 0) return;

            coluna -= 1;

            if (maquinaEstados.isJogavelColuna(coluna)) break;

            System.out.println("Essa coluna está cheia ou não existe!");
        }

        maquinaEstados.jogarFicha(coluna);

    }

    private String pedeNomeJogadorUI() {
        String nome;
        while (true) {
            nome = UtilsUITexto.getResposta("Qual o nome do jogador?");

            if (nome.isEmpty()) return "";

            if (!maquinaEstados.existeJogador(nome)) break;

            System.out.println("Esse nome já está a ser utilizado. Por favor insira outro nome.");
        }

        return nome;
    }

    private void pedeLoadUI() {
        List<String> ficheiros = new ArrayList<>(Utils.getFicheirosNoDiretorio(Constantes.SAVE_PATH));

        if (ficheiros.isEmpty()) {
            System.out.println("\nNão há saves para carregar.");
            return;
        }

        ficheiros.add("Sair");

        while (true) {
            int opt = UtilsUITexto.getOpcao("Ficheiro: ", ficheiros.toArray(new String[0]));

            if (opt == 0) return;

            if (maquinaEstados.continuarJogo(Constantes.SAVE_PATH + ficheiros.get(opt - 1))) break;
            System.out.println("Load falhou.");
        }

        System.out.println("Load com sucesso!");
    }

    private void pedeReplayUI() {
        List<String> ficheiros = new ArrayList<>(Utils.getFicheirosNoDiretorio(Constantes.REPLAY_PATH));

        if (ficheiros.isEmpty()) {
            System.out.println("\nNão há jogos para dar replay.");
            return;
        }

        ficheiros.add("Sair");

        int opt = UtilsUITexto.getOpcao("Ficheiro: ", ficheiros.toArray(new String[0]));

        if (opt == 0) return;

        maquinaEstados.verReplay(Constantes.REPLAY_PATH + ficheiros.get(opt - 1));
    }

    private void voltaAtrasUI() {
        int numCreditosAUtilizar;
        int numCreditosJogaveis = maquinaEstados.getNumCreditosJogaveis();

        do {
            numCreditosAUtilizar = UtilsUITexto.getInteiro(
                    "\nNúmero de créditos a utilizar [0 - " + numCreditosJogaveis + "]: ");
        } while (numCreditosAUtilizar < 0 || numCreditosAUtilizar > maquinaEstados.getNumCreditosJogaveis());

        if (numCreditosAUtilizar == 0) return;

        maquinaEstados.undoJogada(numCreditosAUtilizar);
        System.out.println("Voltou atrás " + numCreditosAUtilizar + " jogada(s).");
    }



    ///////////////////// OUTRAS UTILS /////////////////////

    private String[] getOpcoesDecisaoJogada() {
        List<String> opcoes = new LinkedList<>();
        opcoes.add("Jogar ficha"); // 1
        opcoes.add("Gravar jogo"); // 2

        // 3
        String optCreditos = "";
        if (maquinaEstados.podeVoltarAtras()) {
            System.out.println("\nTem " + maquinaEstados.getNumCreditos() + " créditos.");
            System.out.println("Pode voltar atrás!");
            optCreditos = "Voltar atrás";
        }
        opcoes.add(optCreditos);

        // 4
        String optMinijogo = "";
        if (maquinaEstados.temMinijogoDisponivel()) {
            System.out.println("\nPode jogar um minijogo!");
            optMinijogo = "Jogar minijogo";
        }
        opcoes.add(optMinijogo);

        // 5
        int numFichasEspeciais = maquinaEstados.getNumFichasEspeciaisJogadorAtual();
        String optFichaEspecial = "";
        if (numFichasEspeciais > 0) {
            System.out.println("\nTem " + numFichasEspeciais + " ficha(s) especial(is)");
            optFichaEspecial = "Jogar ficha especial";
        }
        opcoes.add(optFichaEspecial);

        opcoes.add("Desistir"); // 6

        return opcoes.toArray(new String[0]);
    }

    private void printResultadoJogo() {
        String resultado = "\nO jogo empatou.";
        if (!maquinaEstados.isEmpatado()) resultado = "\nO jogador " + maquinaEstados.getNomeVencedor() + " ganhou o jogo!";

        System.out.println(resultado);
    }

    private void printJogadorAtual() {
        System.out.print("É a vez de " + maquinaEstados.getNomeJogadorAtual() + " (Ficha ");

        switch(maquinaEstados.getFichaAtual()) {
            case FICHA_AMARELA -> System.out.print(Constantes.FICHA_AMARELA_PRINT);
            case FICHA_VERMELHA -> System.out.print(Constantes.FICHA_VERMELHA_PRINT);
            default -> System.out.print("ERRO");
        }

        System.out.println(").");
    }

    private void printTabuleiro(List<TipoFicha> tabuleiro) {
        int numLinhas = maquinaEstados.getNumLinhas();
        int numColunas = maquinaEstados.getNumColunas();

        for (int i = 1; i <= numColunas; i++) System.out.print(" " + i);
        System.out.println();

        for (int i = numLinhas - 1; i >= 0; i--) {
            for (int j = 0; j < numColunas; j++) {
                System.out.print(Constantes.DIVISORIA_TABULEIRO_PRINT);
                switch (tabuleiro.get(i * numColunas + j)) {
                    case FICHA_AMARELA -> System.out.print(Constantes.FICHA_AMARELA_PRINT);
                    case FICHA_VERMELHA -> System.out.print(Constantes.FICHA_VERMELHA_PRINT);
                    default -> System.out.print(" ");
                }
            }
            System.out.println(Constantes.DIVISORIA_TABULEIRO_PRINT + ' ' + (i + 1));
        }
    }
}
