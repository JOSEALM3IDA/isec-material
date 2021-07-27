package jogo.logica.dados.minijogos;

import jogo.utils.Utils;

import java.util.Arrays;
import java.util.List;

public class Calculos extends MinijogoAdapter {

    static final int TEMPO_MAXIMO_SEGUNDOS = 30;

    private enum Operadores {
        SOMA('+'),
        SUBTRACAO('-'),
        DIVISAO('/'),
        MULTIPLICACAO('x');

        char op;

        Operadores(char op) { this.op = op; }
    }

    private int inteiro1 = -1;
    private int inteiro2 = -1;

    private Operadores currOperador = null;

    @Override
    public void comecar() {
        isComecado = true;
        cronometro.comecar();

        gerarNovaPergunta();
    }

    @Override
    public boolean isValidaResposta(String resposta) {
        try { Double.parseDouble(resposta); } catch (NumberFormatException nfe) { return false; }
        return true;
    }

    @Override
    public void receberResposta(String resposta) {
        if (isAcabado) return;

        if (inteiro1 == -1 || inteiro2 == -1) return;
        if (currOperador == null) return;

        if (!cronometro.isAtivo()) return;

        if (cronometro.passouTempo(TEMPO_MAXIMO_SEGUNDOS)) {
            cronometro.acabar();
            isGanho = false;
            isAcabado = true;
            return;
        }

        if (!isValidaResposta(resposta)) return;

        double respostaCorreta = -1;
        try { respostaCorreta = aplicarOperador(inteiro1, inteiro2); }
        catch (NumberFormatException nfe) { return; }
        finally { gerarNovaPergunta(); }

        respostaCorreta = Utils.round(respostaCorreta, 3);

        double respostaDada = Double.parseDouble(resposta);
        if (respostaCorreta != respostaDada) return;

        numPontos++;

        if (numPontos >= 5) {
            isGanho = true;
            isAcabado = true;
        }

    }

    @Override
    protected void gerarNovaPergunta() {
        inteiro1 = Utils.getNumeroRandom(100);
        inteiro2 = Utils.getNumeroRandom(100);

        List<Operadores> ops = Arrays.asList(Operadores.values());
        currOperador = ops.get(Utils.getNumeroRandom(ops.size()));

        perguntaAtual = inteiro1 + " " + currOperador.op + " " + inteiro2 + " = ?";
    }

    private double aplicarOperador(int inteiro1, int inteiro2) throws NumberFormatException {
        return switch (currOperador) {
            case SOMA -> inteiro1 + inteiro2;
            case SUBTRACAO -> inteiro1 - inteiro2;
            case DIVISAO -> (double) inteiro1 / inteiro2;
            case MULTIPLICACAO -> inteiro1 * inteiro2;
        };
    }
}
