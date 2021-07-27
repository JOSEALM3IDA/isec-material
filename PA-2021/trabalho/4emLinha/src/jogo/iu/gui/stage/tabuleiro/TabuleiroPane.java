package jogo.iu.gui.stage.tabuleiro;

import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.layout.GridPane;
import jogo.iu.gui.resources.MusicPlayer;
import jogo.logica.Propriedade;
import jogo.logica.QuatroEmLinhaObservable;
import jogo.logica.dados.tabuleiro.TipoFicha;
import jogo.utils.Constantes;

import java.util.List;

public class TabuleiroPane extends GridPane {

    private final QuatroEmLinhaObservable observable;

    private final int numColunas;
    private final int numLinhas;
    private final double tamanhoSlot;

    private boolean isJogarFichaEspecial = false;

    public TabuleiroPane(QuatroEmLinhaObservable observable) {
        this.observable = observable;
        setAlignment(Pos.CENTER);
        numColunas = observable.getNumColunas();
        numLinhas = observable.getNumLinhas();
        tamanhoSlot = Constantes.TAM_TABULEIRO / Math.max(numColunas, numLinhas);
        registarObservadores();
    }

    private void adicionarGridNode(SlotTabuleiro slot, int lin, int col) {
        add(slot, col, observable.getNumLinhas() - 1 - lin);

        if (observable.isComputadorAJogar() || observable.isReplayAtivo()) return;

        slot.setOnMouseClicked(e -> {
            if (isJogarFichaEspecial) {
                MusicPlayer.playMusic(Constantes.SOM_FICHA_ESPECIAL);
                observable.jogarFichaEspecial(col);
                return;
            }

            if (!observable.isJogavelColuna(col)) return;

            MusicPlayer.playMusic(Constantes.SOM_FICHA_DROP);
            observable.jogarFicha(col);
        });

        slot.setOnMouseEntered(e -> {
            if (observable.jogoAcabou()) return;

            if (isJogarFichaEspecial) {
                for (Node child : getChildren()) {
                    if (GridPane.getColumnIndex(child) == col) {
                        ((SlotTabuleiro) child).setMouseInside(true);
                    }
                }

                MusicPlayer.playMusic(Constantes.SOM_FICHA_HOVER);
                return;
            }

            for (Node child : getChildren()) {
                if (GridPane.getColumnIndex(child) == col && ((SlotTabuleiro) child).getTipoFicha() == TipoFicha.NONE) {
                    ((SlotTabuleiro) child).setMouseInside(true, observable.getFichaAtual());
                    return;
                }
            }
        });

        slot.setOnMouseExited(e -> {
            if (observable.jogoAcabou()) return;

            int colEntered = GridPane.getColumnIndex(slot);
            for (Node node : getChildren()) {
                if (GridPane.getColumnIndex(node) == colEntered) {
                    ((SlotTabuleiro) node).setMouseInside(false, TipoFicha.NONE);
                }
            }
        });
    }

    public boolean isJogarFichaEspecial() { return isJogarFichaEspecial; }

    public void setJogarFichaEspecial(boolean isJogarFichaEspecial) { this.isJogarFichaEspecial = isJogarFichaEspecial; }

    private void registarObservadores() { observable.addPropertyChangeListener(Propriedade.ATUALIZAR_TABULEIRO, evt -> atualizarTabuleiro()); }

    public void atualizarTabuleiro() {
        getChildren().clear();

        List<TipoFicha> tabuleiroActual = observable.getTabuleiro();

        for (int col = 0; col < numColunas; col++) {
            for (int lin = 0; lin < numLinhas; lin++) {
                SlotTabuleiro slot = new SlotTabuleiro(tabuleiroActual.get(lin * numColunas + col), tamanhoSlot);
                adicionarGridNode(slot, lin, col);
            }
        }
    }
}
