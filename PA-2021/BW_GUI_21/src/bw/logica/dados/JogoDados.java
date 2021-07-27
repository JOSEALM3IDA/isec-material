package bw.logica.dados;


import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class JogoDados implements Serializable {
    private static final int NR_BOLAS_BRANCAS = 10;
    private static final int NR_BOLAS_PRETAS = 10;

    private List<Bola> saco = new ArrayList<Bola>();
    private int pontuacao;
    private int brancasRemovidas;
    private int pretasRemovidas;

    private int aposta = 0;
  //  private boolean apostaGanha;
    private List<String> msgLog = new ArrayList<>();

    public JogoDados() {
        inicia();
    }

    public void inicia() {
        aposta = 0;
       // apostaGanha = false;
        pontuacao = 0;
        brancasRemovidas = 0;
        pretasRemovidas = 0;
        saco = new ArrayList<Bola>();
        for(int i = 0; i < NR_BOLAS_BRANCAS; i++)
            saco.add(new BolaBranca());
        for(int i = 0; i < NR_BOLAS_PRETAS; i++)
            saco.add(new BolaPreta());
        Collections.shuffle(saco);
    }

    // log
    public void clearMsgLog(){
        msgLog.clear();
    }

    public void addMsgLog(String msg){
        msgLog.add(msg);
    }

    public List<String> getMsgLog(){
        return msgLog;
    }
    // acoes
    public boolean apostar( int n){
        if( n > pontuacao || n < 0){
            return false;
        }
        aposta = n;
        return true;
    }
    public boolean tiraBolaDoSaco() {
        int index;

        Bola bola = saco.remove(0);
        return bola.reagirASerRetiradaDoSaco(this);
    }

    public boolean sairBolaBranca(){
        msgLog.add("jogo dados sair bola branca");
        ++pontuacao;
        List<Bola> reveladas = new ArrayList<>();
        for( int i = 0 ; i < aposta && i<saco.size(); ++i) {
            reveladas.add(saco.get(i));
        }
        for(Bola b: reveladas) {
            b.removerSePreta(this);
        }

        //Collections.shuffle(saco);
        aposta = 0;
        return true;
    }

    public boolean sairBolaPreta(){
        msgLog.add("saiu bola preta");
        ++pretasRemovidas;
        pontuacao -= aposta;
        brancasRemovidas+= aposta;
        aposta = 0;
        return false;
    }

    public void removerDoSaco(Bola bola){
        saco.remove(bola);
    }

    public void incrementaBrancasRemovidas(){
        ++brancasRemovidas;
    }
    public void incrementaPretasRemovidas(){
        ++pretasRemovidas;
    }



    public void escolherOpcaoRetirarDuasBolas() {
        addMsgLog("retira 2 bolas opcao");
        Bola b0 = null, b1 = null;
        if(saco.size() >0) {
            b0 = saco.get(0);
        }
        if(saco.size() >1) {
            b1 = saco.get(1);
        }
        if(b0!= null) {
            addMsgLog("remove se brancao");
            b0.removerSeBranca(this);
        }
        if(b1!= null) {
            addMsgLog("remove se brancao");
            b1.removerSeBranca(this);
        }
        //Collections.shuffle(saco);
    }
    public boolean escolherOpcaoPerderPontuacao(){
        if (pontuacao > 0) {
            --pontuacao;
            incrementaBrancasRemovidas();
            return true;
        } else {
            return false;
        }
    }

    public String toString(){
        String s;

        s = "PONTUACAO: " + pontuacao;
        s += "\n" + "Saco (" + saco.size() + " balls): " + saco;
        s += "\n" + "Bolas removidas:";
        s += "\n\t(" + brancasRemovidas + " bolas brancas):";
        s += "\n\t(" + pretasRemovidas + " bolas pretas):";

        return s;
    }

    public boolean isSacoVazio(){
        return saco.isEmpty();
    }

    public int getPontuacao() {
        return pontuacao;
    }

    public List<String> getSaco() {
        List<String> strSaco = new ArrayList<>();
        for(Bola bola : saco)
            strSaco.add(bola.toString());
        return strSaco;
    }

    public int getNBrancasRemovidas() {
        return brancasRemovidas;
    }

    public int getNPretasRemovidas() {
        return pretasRemovidas;
    }

    public int getAposta() {
        return aposta;
    }
    public int getNBolasBrancasNoSaco() {
       int n = 0;
       for( Bola bola: saco){
           String s = bola.toString();
           if(s.equalsIgnoreCase("B")){
               ++n;
           }
       }
       return n;
    }

    public int getNBolasPretasNoSaco() {
        int n = 0;
        for( Bola bola: saco){
            String s = bola.toString();
            if(s.equalsIgnoreCase("P")){
                ++n;
            }
        }
        return n;
    }
}
