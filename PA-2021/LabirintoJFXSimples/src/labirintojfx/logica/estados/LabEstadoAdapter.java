package labirintojfx.logica.estados;

import labirintojfx.logica.modelo.LabirintoGameData;

public abstract class LabEstadoAdapter implements ILabEstado {
    LabirintoGameData game;

    public LabEstadoAdapter(LabirintoGameData g) { game = g; }

    protected LabirintoGameData getGame() { return game; }

    @Override
    public ILabEstado configura(String nome, int dificuldade) { return this; }

    @Override
    public ILabEstado up() { return this; }

    @Override
    public ILabEstado down() { return null; }

    @Override
    public ILabEstado left() { return null; }

    @Override
    public ILabEstado right() { return null; }

    @Override
    public ILabEstado recomeca() { return this; }

}
