package labirintojfx.logica.estados;

import labirintojfx.logica.Situacao;
import labirintojfx.logica.modelo.LabirintoGameData;

public class AguardaFinal extends LabEstadoAdapter {
    AguardaFinal(LabirintoGameData g) { super(g); }

    @Override
    public ILabEstado recomeca() {
        return new AguardaConfig(getGame());
    }

    public Situacao getSituacao() { return Situacao.AGUARDA_FINAL; }

}
