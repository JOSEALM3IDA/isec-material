package labirintojfx.logica.estados;

import labirintojfx.logica.Situacao;
import labirintojfx.logica.modelo.LabirintoGameData;

public class AguardaConfig extends LabEstadoAdapter {
    public AguardaConfig(LabirintoGameData g) { super(g); }

    @Override
    public ILabEstado configura(String nome, int dificuldade) {
        if (getGame().inicializa(nome, dificuldade))
            return new AguardaMovimento(getGame());
        return this;  // config não aceite => fica na mesma
    }

    public Situacao getSituacao() { return Situacao.AGUARDA_CONFIG; }

}
