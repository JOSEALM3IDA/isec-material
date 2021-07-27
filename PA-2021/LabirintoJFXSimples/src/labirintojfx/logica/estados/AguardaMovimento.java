package labirintojfx.logica.estados;

import labirintojfx.logica.Situacao;
import labirintojfx.logica.modelo.LabirintoGameData;

public class AguardaMovimento extends LabEstadoAdapter {

    AguardaMovimento(LabirintoGameData g) { super(g); }

    @Override
    public ILabEstado up() {
        LabirintoGameData g = getGame();
        g.up();
        if (g.isGameFinished())
            return new AguardaFinal(g);
        return this;
    }

    @Override
    public ILabEstado down() {
        LabirintoGameData g = getGame();
        g.down();
        if (g.isGameFinished())
            return new AguardaFinal(g);
        return this;
    }

    @Override
    public ILabEstado left() {
        LabirintoGameData g = getGame();
        g.left();
        if (g.isGameFinished())
            return new AguardaFinal(g);
        return this;
    }

    @Override
    public ILabEstado right() {
        LabirintoGameData g = getGame();
        g.right();
        if (g.isGameFinished())
            return new AguardaFinal(g);
        return this;
    }

    public Situacao getSituacao() { return Situacao.AGUARDA_MOVIMENTO; }

}
