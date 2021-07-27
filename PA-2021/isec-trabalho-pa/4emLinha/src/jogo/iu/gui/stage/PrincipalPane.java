package jogo.iu.gui.stage;

import javafx.scene.layout.*;
import jogo.iu.gui.estados.*;
import jogo.logica.QuatroEmLinhaObservable;

public class PrincipalPane extends BorderPane  {
    private final QuatroEmLinhaObservable observable;

    public PrincipalPane(QuatroEmLinhaObservable observable) {
        this.observable = observable;

        criarVista();
    }

    private void criarVista() {
        // PAINEIS DOS ESTADOS
        PedeDecisaoInicioPane pedeDecisaoInicioPane = new PedeDecisaoInicioPane(observable);
        PedeConfiguracaoPane pedeConfiguracaoPane = new PedeConfiguracaoPane(observable);
        PedeDecisaoJogadaPane pedeDecisaoJogadaPane = new PedeDecisaoJogadaPane(observable);
        JogaMinijogoPane jogaMinijogoPane = new JogaMinijogoPane(observable);
        FimJogoPane fimJogoPane = new FimJogoPane(observable);
        AssisteJogadaPane assisteJogadaPane = new AssisteJogadaPane(observable);

        // STACKPANE COM OS PAINEIS DOS ESTADOS
        StackPane stackPane = new StackPane(pedeDecisaoInicioPane, pedeConfiguracaoPane,
                pedeDecisaoJogadaPane, jogaMinijogoPane, fimJogoPane, assisteJogadaPane);

        setCenter(stackPane);
    }

}
