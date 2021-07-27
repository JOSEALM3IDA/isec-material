package pt.isec.jalmeida.hangman;

public class HangmanDictionary {
    private static final String [] words = {"AMANHA","ARQUIMEDES","LEAO","TIGRE","ZEBRA","PRATO",
            "CASTANHO","LARANJA","ERVILHA","LONTRA","LASTRO","ORANGOTANGO","DISCIPLINA","PROGRAMACAO",
            "BATATA","PALHACO","CEREBRO","ATUM","PORTUGAL","SILVESTRE","ANIMAL","IRRACIONAL","MATEMATICA",
            "DISCRETO","EFICAZ","EFICIENTE","MARAVILHA","SINOPSE","DISPOSITIVO","LINEAR","LIMAO","LAMPADA",
            "ORELHA","BUFALO","SAPATO","LAGOSTA","ARRISCADO","RISCADO","CARNAVAL","ARROJADO","LIBERTADO",
            "SIMPLES","COMPLEXO","AGRAFADOR","MONITOR","TECLADO","CHAVE","RELOGIO","LENCO","JANELA","CORDA",
            "VIOLA","GUITARRA","PONTEIRO","ARGUENTE","SAGAZ","ERRONEO","INSTITUTO","SUPERIOR","ENGENHARIA",
            "DEPARTAMENTO","INFORMATICA","SISTEMA","CONVOCATORIA","PRESIDENTE","FEVEREIRO","AUMENTO","SALARIO",
            "DINHEIRO","IMEDIATO","FLAMINGO","RINOCERONTE","HIPOPOTAMO","BACALHAU","PARGO","SARDINHA","CARACOL",
            "INSECTO","VOADOR","LARANJA","ASPERSAO","EXTINTO","EXTERIOR","AMBIVALENTE"};

    public static String getPalavra(int i) {
        if (i < 0 || i >= words.length)
            return null;

        return words[i];
    }

    public static int getTamanho() {
        return words.length;
    }

}
