package bw.logica.estados;


import bw.logica.Situacao;
import java.io.Serializable;

public interface IEstado extends Serializable {
    IEstado comecarJogo();
    IEstado terminar();
    IEstado apostar(int n);
    IEstado escolherOpcaoPerderPontuacao();
    IEstado escolherOpcaoRetirarDuasBolas();
    Situacao getSituacaoAtual();
}
