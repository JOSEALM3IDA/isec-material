package jogo.logica.estados;

import jogo.logica.dados.QuatroEmLinhaGestor;
import jogo.logica.dados.jogadores.TipoJogador;

public interface Estado {

    // PedeDecisaoInicio
    Estado iniciarJogo();       // -> PedeConfiguracao
    Estado continuarJogo(QuatroEmLinhaGestor quatroEmLinhaGestor);      // -> PedeDecisaoJogada
    Estado verReplay(QuatroEmLinhaGestor quatroEmLinhaGestor);         // -> AssisteJogada

    // PedeConfiguracao
    Estado adicionarJogador(TipoJogador tipoJogador, String nomeJogador); // -> PedeConfiguracao ; PedeDecisaoJogada

    // PedeDecisaoJogadaPane
    Estado jogarFicha(int col);      // -> PedeDecisaoJogadaPane ; FimJogo
    Estado undoJogada(int numVezes);        // -> PedeDecisaoJogada
    Estado desistir();          // -> FimJogo
    Estado aceitarMinijogo();   // -> JogoMinijogo
    Estado jogarFichaEspecial(int col); // -> PedeDecisaoJogada

    // JogoMinijogo
    Estado jogarMinijogo(String resposta); // -> PedeDecisaoJogada

    // AssisteJogada ; PedeConfiguracao
    Estado avancar();           // -> PedeDecisaoInicio ; AssisteJogada

    // AssisteJogada ; PedeConfiguracao ; PedeDecisaoJogada ; FimJogo
    Estado voltar();        // -> PedeDecisaoInicio

    Situacao getSituacao();
}
