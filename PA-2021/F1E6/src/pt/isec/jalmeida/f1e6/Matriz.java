package pt.isec.jalmeida.f1e6;

import java.util.Arrays;
import java.util.Objects;

public class Matriz {
    float[][] matriz;
    int linhas, colunas;

    public Matriz(int linhas, int colunas) {
        this.linhas = linhas;
        this.colunas = colunas;
        matriz = new float[linhas][colunas];

        for (int i = 0; i < linhas; i++) {
            Arrays.fill(matriz[i], 1.0f * i);
        }
    }

//    public Matriz(Matriz m) {
//        this.linhas = m.linhas;
//        this.colunas = m.colunas;
//        this.matriz = new float[m.getLinhas()][m.getColunas()];
//        for (int i = 0; i < linhas; i++) {
//            this.matriz[i] = Arrays.copyOf(m.matriz[i], m.matriz[i].length);
//        }
//    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        Matriz newm = new Matriz(linhas, colunas);
        for (int i = 0; i < linhas; i++) {
            newm.matriz[i] = Arrays.copyOf(matriz[i], matriz[i].length);
        }
        return newm;
    }

    public boolean setValor(int linha, int coluna, float valor) {
        if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas)
            return false;

        matriz[linha][coluna] = valor;
        return true;
    }

    public int getLinhas() {
        return linhas; // matriz.length
    }

    public int getColunas() {
        return colunas; // matriz[0].length
    }

    public boolean acumula(Matriz m) {
        if (linhas != m.linhas || colunas != m.colunas)
            return false;

        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                matriz[i][j] += m.matriz[i][j];

        return true;
    }

    public Matriz adiciona(Matriz m) {
        if (linhas != m.linhas || colunas != m.colunas)
            return null;

        Matriz res = null;
        try {
            res = (Matriz) this.clone();
            res.acumula(m);
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }

        return res;
    }

    public static Matriz adiciona(Matriz m1, Matriz m2) {
        return m1.adiciona(m2);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        //if (o == null || getClass() != o.getClass()) return false;
        if (!(o instanceof Matriz)) return false;

        Matriz matriz1 = (Matriz) o;

        if (linhas != matriz1.linhas) return false;
        if (colunas != matriz1.colunas) return false;
        return Arrays.deepEquals(matriz, matriz1.matriz);
    }

    @Override
    public int hashCode() {
        int result = Objects.hash(linhas, colunas);
        result = 31 * result + Arrays.hashCode(matriz);
        return result;
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++)
                str.append(String.format(" %5.2f", matriz[i][j]));
            str.append('\n');
        }
        return str.toString();
    }
}
