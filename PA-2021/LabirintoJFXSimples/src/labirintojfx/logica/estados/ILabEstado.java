package labirintojfx.logica.estados;

import labirintojfx.logica.Situacao;

public interface ILabEstado {
    ILabEstado configura(String nome, int dificuldade);
    ILabEstado up();
    ILabEstado down();
    ILabEstado left();
    ILabEstado right();
    ILabEstado recomeca();
    Situacao getSituacao();
}
