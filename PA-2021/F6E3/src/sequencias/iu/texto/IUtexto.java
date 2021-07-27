package sequencias.iu.texto;

import sequencias.logica.GestaoJogoMaqEstados;
import sequencias.logica.memento.dados.Situacao;

import java.util.Scanner;


public class IUtexto {

    private final GestaoJogoMaqEstados jogoMaqEstados;
    private boolean sair = false;

    public IUtexto(GestaoJogoMaqEstados jogoMaqEstados) {
        this.jogoMaqEstados = jogoMaqEstados;
    }

    public void corre() {
        while (!sair) {
            Situacao situacao = jogoMaqEstados.getSituacaoAtual();
            System.out.println("" + jogoMaqEstados);
            switch (situacao) {
                case AGUARDA_INICIO -> AguardaInicioIU();
                case AGUARDA_RELANCAMENTO -> AguardaRelancamentoIU();
                case AGUARDA_SEQUENCIA -> AguardaSequenciaIU();
            }
        }
    }

    private void AguardaInicioIU() {
        int opt = IUutil.getOpt("Comecar", "Undo", "Redo", "Sair");
        switch (opt) {
            case 1 -> jogoMaqEstados.comecar();
            case 2 -> jogoMaqEstados.undo();
            case 3 -> jogoMaqEstados.redo();
            case 4 -> sair = true;
        }
    }

    private void AguardaRelancamentoIU() {
        int opt = IUutil.getOpt("Relancar", "Recolher", "Avaliar", "Undo", "Redo", "Sair");
        switch (opt) {
            case 1 -> jogoMaqEstados.relancar();
            case 2 -> {
                System.out.println("Indique o indice (entre 0 e " + (jogoMaqEstados.getNDadosLancados() - 1) + "): ");
                Scanner sc = new Scanner(System.in);
                char idx = sc.next().charAt(0);
                if (idx >= '0' && idx <= '9')
                    jogoMaqEstados.recolher(Integer.parseInt(String.valueOf(idx)));
            }
            case 3 -> jogoMaqEstados.avaliar();
            case 4 -> jogoMaqEstados.undo();
            case 5 -> jogoMaqEstados.redo();
            case 6 -> sair = true;
        }
    }

    private void AguardaSequenciaIU() {
        int opt = IUutil.getOpt("Recolher", "Avaliar", "Undo", "Redo", "Sair");
        switch (opt) {
            case 1 -> {
                System.out.println("Indique o indice (entre 0 e " + (jogoMaqEstados.getNDadosLancados() - 1) + "): ");
                Scanner sc = new Scanner(System.in);
                char idx = sc.next().charAt(0);
                if (jogoMaqEstados.getNDadosLancados() > 0 && idx >= '0' && idx <= '9')
                    jogoMaqEstados.recolher(Integer.parseInt(String.valueOf(idx)));
            }
            case 2 -> jogoMaqEstados.avaliar();
            case 3 -> jogoMaqEstados.undo();
            case 4 -> jogoMaqEstados.redo();
            case 5 -> sair = true;
        }
    }
}
