package jogo.logica.dados.tabuleiro;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Tabuleiro implements Serializable {
    private static final int DEFAULT_NUM_LINHAS = 6;
    private static final int DEFAULT_NUM_COLUNAS = 7;
    private static final int NUM_PECAS_PARA_GANHAR = 4;

    private final int numColunas;
    private final int numLinhas;

    ArrayList<TipoFicha> tabuleiroList = new ArrayList<>(DEFAULT_NUM_LINHAS * DEFAULT_NUM_COLUNAS);

    public Tabuleiro() {
        numColunas = DEFAULT_NUM_COLUNAS;
        numLinhas = DEFAULT_NUM_LINHAS;
        initTabuleiro();
    }

    private void initTabuleiro() {
        tabuleiroList.clear();
        for (int i = 0; i < numLinhas * numColunas; i++) tabuleiroList.add(TipoFicha.NONE);
    }

    public void addFicha(int col, TipoFicha ficha) {
        if (!isJogavelColuna(col)) return;

        for (int lin = 0; lin < numLinhas; lin++) {
            if (getFichaEm(lin, col) != TipoFicha.NONE) continue;

            setFichaEm(lin, col, ficha);
            return;
        }
    }

    public void removeFicha(int col) {
        for (int lin = numLinhas - 1; lin >= 0; lin--) {
            if (getFichaEm(lin, col) != TipoFicha.NONE) {
                setFichaEm(lin, col, TipoFicha.NONE);
                return;
            }
        }
    }

    private TipoFicha getFichaEm(int lin, int col) {
        if (lin >= numLinhas || col >= numColunas) return null;
        if (lin < 0 || col < 0) return null;
        return tabuleiroList.get(lin * numColunas + col);
    }

    private void setFichaEm(int lin, int col, TipoFicha tipoFicha) { tabuleiroList.set(lin * numColunas + col, tipoFicha); }

    public List<TipoFicha> getFichas() { return Collections.unmodifiableList(tabuleiroList); }
    public int getNumLinhas() { return numLinhas; }
    public int getNumColunas() { return numColunas; }

    public boolean isEmpatado() {
        for (int col = 0; col < numColunas; col++) if (getFichaEm(numLinhas - 1, col) == TipoFicha.NONE) return false;
        return true;
    }

    public boolean checkQuatroEmLinha(TipoFicha ficha) {
        return checkQuatroEmLinhaLinhas(ficha)
                || checkQuatroEmLinhaColunas(ficha)
                || checkQuatroEmLinhaDiagonaisSubir(ficha)
                || checkQuatroEmLinhaDiagonaisDescer(ficha);
    }

    private boolean checkQuatroEmLinhaLinhas(TipoFicha ficha) {
        int counter;
        for (int lin = 0; lin < numLinhas; lin++) {
            counter = 0;
            for (int col = 0; col < numColunas; col++) {
                if (getFichaEm(lin, col) != ficha) {
                    counter = 0;
                    continue;
                }

                counter++;
                if (counter >= NUM_PECAS_PARA_GANHAR) return true;
            }
        }

        return false;
    }

    private boolean checkQuatroEmLinhaColunas(TipoFicha ficha) {
        int counter;
        for (int col = 0; col < numColunas; col++) {
            counter = 0;
            for (int lin = 0; lin < numLinhas; lin++) {
                if (getFichaEm(lin, col) != ficha) {
                    counter = 0;
                    continue;
                }

                counter++;
                if (counter >= NUM_PECAS_PARA_GANHAR) return true;
            }
        }

        return false;
    }

    // diagonais /
    private boolean checkQuatroEmLinhaDiagonaisSubir(TipoFicha ficha) {
        int col;
        int lin;
        int counter;

        for (int initLin = 0; initLin < numLinhas - (NUM_PECAS_PARA_GANHAR - 1); initLin++) {
            counter = 0;
            for (lin = initLin, col = 0; lin < numLinhas && col < numColunas; lin++, col++) {
                if (getFichaEm(lin, col) != ficha) {
                    counter = 0;
                    continue;
                }

                counter++;
                if (counter >= NUM_PECAS_PARA_GANHAR) return true;
            }
        }

        for (int initCol = 1; initCol < numColunas - NUM_PECAS_PARA_GANHAR; initCol++) {
            counter = 0;
            for (lin = 0, col = initCol; lin < numLinhas && col < numColunas; lin++, col++) {
                if (getFichaEm(lin, col) != ficha) {
                    counter = 0;
                    continue;
                }

                counter++;
                if (counter >= NUM_PECAS_PARA_GANHAR) return true;
            }
        }


        return false;
    }

    // diagonais \
    private boolean checkQuatroEmLinhaDiagonaisDescer(TipoFicha ficha) {
        int col;
        int lin;
        int counter;

        for (int initLin = 0; initLin < numLinhas - (NUM_PECAS_PARA_GANHAR - 1); initLin++) {
            counter = 0;
            for (lin = initLin, col = numColunas - 1; lin < numLinhas && col >= 0 ; lin++, col--) {
                if (getFichaEm(lin, col) != ficha) {
                    counter = 0;
                    continue;
                }

                counter++;
                if (counter >= NUM_PECAS_PARA_GANHAR) return true;
            }
        }

        for (int initCol = numColunas - 1 - 1; initCol >= NUM_PECAS_PARA_GANHAR - 1; initCol--) {
            counter = 0;
            for (lin = 0, col = initCol; lin < numLinhas && col >= 0; lin++, col--) {
                if (getFichaEm(lin, col) != ficha) {
                    counter = 0;
                    continue;
                }

                counter++;
                if (counter >= NUM_PECAS_PARA_GANHAR) return true;
            }
        }

        return false;
    }

    public void limpar() { initTabuleiro(); }

    public List<TipoFicha> getColuna(int col) {
        List<TipoFicha> coluna = new LinkedList<>();

        for (int lin = 0; lin < numLinhas; lin++) coluna.add(getFichaEm(lin, col));

        return coluna;
    }

    public void setColuna(int col, List<TipoFicha> novaColuna) {
        if (novaColuna.size() != numLinhas) return;

        for (int lin = 0; lin < numLinhas; lin++) setFichaEm(lin, col, novaColuna.get(lin));
    }

    public boolean isJogavelColuna(int col) {
        if (col >= numColunas || col < 0) return false;

        for (int lin = 0; lin < numLinhas; lin++) if (getFichaEm(lin, col) == TipoFicha.NONE) return true;
        return false;
    }

}
