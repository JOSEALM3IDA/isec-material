package pt.isec.jalmeida.f1e4;

class Tabela20 {
    static final int TAM_TAB = 20;

    private int [] tab;
    private int nrTentativas = 0;
    private int nrValores;


    public Tabela20 () {
        tab = new int[TAM_TAB];
    }

    private boolean existe(int valor) {
        for (int i = 0; i < nrValores; i++)
            if (tab[i] == valor)
                return true;

        return false;
    }

    public void preenche() {
        nrValores = 0;
        while (nrValores < TAM_TAB) {
            nrTentativas++;
            int valor = (int) (Math.random() * 101);
            if (!existe(valor)) {
                tab[nrValores++] = valor;
            }
        }
    }

    public int nrDuplicados() { return nrTentativas - nrValores; }

    public void mostra() {
        System.out.print("[");
        for (int i = 0; i < nrValores; i++) {
            if (i != 0)
                System.out.print(", ");
            System.out.print(tab[i]);
        }
        System.out.println("]");
    }
}

public class Main {
    public static void main(String[] args) {
        Tabela20 t = new Tabela20();
        t.preenche();
        System.out.println("Numero de elementos duplicados: " + t.nrDuplicados());
        t.mostra();

    }
}
