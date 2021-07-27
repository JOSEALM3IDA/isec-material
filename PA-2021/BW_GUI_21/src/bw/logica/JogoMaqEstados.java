package bw.logica;


import bw.logica.dados.JogoDados;
import bw.logica.estados.AguardaInicio;
import bw.logica.estados.IEstado;

import java.io.Serializable;
import java.util.List;

public class JogoMaqEstados implements Serializable {
    private JogoDados jogoDados;
    private IEstado estado;

    public JogoMaqEstados()
    {
        jogoDados = new JogoDados();
        estado = new AguardaInicio(jogoDados);
    }
    public int getPontuacao() {
        return jogoDados.getPontuacao();
    }

    public List<String> getMsgLog(){
        return jogoDados.getMsgLog();
    }

    public void clearMsgLog(){
        jogoDados.clearMsgLog();
    }
    public Situacao getSituacaoAtual(){
        return estado.getSituacaoAtual();
    }

    public String toString()    {
        return estado.getSituacaoAtual() + "\n" +jogoDados.toString();
    }
    public List<String> getSaco() {
        return jogoDados.getSaco();
    }
    public int getAposta() {
        return jogoDados.getAposta();
    }
    public int getNBrancasRemovidas() {
        return jogoDados.getNBrancasRemovidas();
    }

    public int getNPretasRemovidas() {
        return jogoDados.getNPretasRemovidas();
    }

    public int getNBolasBrancasNoSaco() {
        return jogoDados.getNBolasBrancasNoSaco();
    }

    public int getNBolasPretasNoSaco() {
        return jogoDados.getNBolasPretasNoSaco();
    }

    // metodos delegados no estado corrente
    public void comecarJogo() {
        estado = estado.comecarJogo();
    }
    public void terminar() {
        estado = estado.terminar();
    }
    public void apostar(int n) {
        estado = estado.apostar(n);
    }
    public void escolherOpcaoPerderPontuacao() {
        estado = estado.escolherOpcaoPerderPontuacao();
    }
    public void escolherOpcaoRetirarDuasBolas() {
        estado = estado.escolherOpcaoRetirarDuasBolas();
    }
}
