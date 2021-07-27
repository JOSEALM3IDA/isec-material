package bw.logica;

import bw.files.FileUtility;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.io.File;
import java.io.IOException;
import java.util.List;

import static bw.logica.Constantes.PROPRIEDADE_BOLAS;

public class JogoObservavel{

    private JogoMaqEstados jogoMaqEstados;
    private final PropertyChangeSupport propertyChangeSupport;

    public JogoObservavel(JogoMaqEstados jogoMaqEstados) {
        this.jogoMaqEstados = jogoMaqEstados;
        propertyChangeSupport = new PropertyChangeSupport(jogoMaqEstados);
    }

    // o argumento recebido por listener vai passar a fazer parte da colecao de observadores
    // geridos pelo objeto propertyCangeSupport, desta classe,
    // IDENTIFICADOS com propertyName,

    public void addPropertyChangeListener(String propertyName, PropertyChangeListener listener) {
        propertyChangeSupport.addPropertyChangeListener(propertyName, listener);
    }

    // metodos que consultam

    public List<String> getSaco(){
        return jogoMaqEstados.getSaco();
    }

    public int getAposta() {
        return jogoMaqEstados.getAposta();
    }

    public int getNBrancasRemovidas() {
        return jogoMaqEstados.getNBrancasRemovidas();
    }

    public int getNPretasRemovidas() {
        return jogoMaqEstados.getNPretasRemovidas();
    }

    public int getNBolasBrancasNoSaco() {
        return jogoMaqEstados.getNBolasBrancasNoSaco();
    }

    public int getNBolasPretasNoSaco() {
        return jogoMaqEstados.getNBolasPretasNoSaco();
    }

    public int getPontuacao() {
        return jogoMaqEstados.getPontuacao();
    }

    public List<String> getMsgLog(){
        return jogoMaqEstados.getMsgLog();
    }

    public Situacao getSituacaoAtual(){
        return jogoMaqEstados.getSituacaoAtual();
    }

    public String toString()    {
        return jogoMaqEstados.toString();
    }

    public JogoMaqEstados getJogoMaqEstados() {
        return jogoMaqEstados;
    }

    // metodos que alteram
    public void clearMsgLog(){
        jogoMaqEstados.clearMsgLog();
        propertyChangeSupport.firePropertyChange(PROPRIEDADE_BOLAS, null, null);
    }

    public void setJogoMaqEstados(JogoMaqEstados jogoMaqEstados) {
        this.jogoMaqEstados = jogoMaqEstados;

        propertyChangeSupport.firePropertyChange(PROPRIEDADE_BOLAS, null, null);
    }

    public void comecarJogo() {
        jogoMaqEstados.comecarJogo();
        propertyChangeSupport.firePropertyChange(PROPRIEDADE_BOLAS, null, null);
    }
    public void terminar() {
        jogoMaqEstados.terminar();
        propertyChangeSupport.firePropertyChange(PROPRIEDADE_BOLAS, null, null);
    }
    public void apostar(int n) {
        jogoMaqEstados.apostar(n);
        propertyChangeSupport.firePropertyChange(PROPRIEDADE_BOLAS, null, null);
    }
    public void escolherOpcaoPerderPontuacao() {
        jogoMaqEstados.escolherOpcaoPerderPontuacao();
        propertyChangeSupport.firePropertyChange(PROPRIEDADE_BOLAS, null, null);
    }
    public void escolherOpcaoRetirarDuasBolas() {
        jogoMaqEstados.escolherOpcaoRetirarDuasBolas();
        propertyChangeSupport.firePropertyChange(PROPRIEDADE_BOLAS, null, null);
    }


    public boolean gravar(File filename)  {

        try {
            FileUtility.saveGameToFile(filename, getJogoMaqEstados());
            return true;
        }catch (IOException e) {
            System.err.println("ERRO ao gravar");
            return false;
        }
    }

    public boolean ler(File filename) {
        try {
            JogoMaqEstados jogoMaqEstados = (JogoMaqEstados) FileUtility.retrieveGameFromFile(filename);
            if (jogoMaqEstados != null) {
                setJogoMaqEstados(jogoMaqEstados);
            }
        }catch (IOException | ClassNotFoundException e) {
            System.err.println("ERRO ao ler");
            return false;
        }
        return true;
    }
}
