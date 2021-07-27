package jogo.iu.gui.stage;

import javafx.scene.layout.BorderPane;
import jogo.iu.gui.resources.CSSManager;
import jogo.logica.QuatroEmLinhaObservable;

public class PaneOrganizer extends BorderPane {
    private final QuatroEmLinhaObservable observable;

    private PrincipalPane principalPane;

    public PaneOrganizer(QuatroEmLinhaObservable observable) {
        this.observable = observable;
        CSSManager.setCss(this, "styles.css");
        criarLayout();
    }

    private void criarLayout() {
        principalPane = new PrincipalPane(observable);
        setCenter(principalPane);
    }
}
