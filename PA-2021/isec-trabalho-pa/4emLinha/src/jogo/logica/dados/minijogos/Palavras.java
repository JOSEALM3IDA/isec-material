package jogo.logica.dados.minijogos;

import jogo.utils.Utils;

import java.util.Arrays;
import java.util.List;

public class Palavras extends MinijogoAdapter {

    private static final String DEFAULT_FICHEIRO = "palavras/palavras.txt";
    private static final int NUM_PALAVRAS = 5;

    private List<String> listaPalavras;

    @Override
    public void comecar() {
        lerFicheiroPalavras();

        isComecado = true;

        gerarNovaPergunta();
    }

    @Override
    public void receberResposta(String resposta) {
        if (isAcabado) return;

        if (perguntaAtual.isEmpty()) return;

        if (!cronometro.isAtivo()) return;

        cronometro.acabar();
        isAcabado = true;
        if (cronometro.getTempoTotal() > perguntaAtual.length() / 2) {
            isGanho = false;
            cronometro.acabar();
            return;
        }

        List<String> listaPergunta;
        listaPergunta = Arrays.asList(perguntaAtual.split("\\s+"));

        List<String> listaResposta;
        listaResposta = Arrays.asList(resposta.split("\\s+"));

        if (listaPergunta.size() != listaResposta.size()) return;

        for (int i = 0; i < NUM_PALAVRAS; i++) if (listaPergunta.get(i).equalsIgnoreCase(listaResposta.get(i))) numPontos++;

        if (numPontos == NUM_PALAVRAS) isGanho = true;
    }

    @Override
    protected void gerarNovaPergunta() {

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < NUM_PALAVRAS; i++) {
            sb.append(listaPalavras.get(Utils.getNumeroRandom(listaPalavras.size())));

            if (i != NUM_PALAVRAS - 1) sb.append(' ');
        }

        perguntaAtual = sb.toString();
        cronometro.comecar();
    }

    private void lerFicheiroPalavras() {
        listaPalavras = Utils.lerLinhasParaLista(DEFAULT_FICHEIRO);
        if (listaPalavras.isEmpty()) carregarPalavrasDefault();
    }

    private void carregarPalavrasDefault() {
        listaPalavras.add("sagaz");
        listaPalavras.add("negro");
        listaPalavras.add("âmago");
        listaPalavras.add("êxito");
        listaPalavras.add("mexer");
        listaPalavras.add("termo");
        listaPalavras.add("algoz");
        listaPalavras.add("senso");
        listaPalavras.add("nobre");
        listaPalavras.add("plena");
        listaPalavras.add("afeto");
        listaPalavras.add("mútua");
        listaPalavras.add("ética");
        listaPalavras.add("sutil");
        listaPalavras.add("audaz");
        listaPalavras.add("vigor");
        listaPalavras.add("tênue");
        listaPalavras.add("inato");
        listaPalavras.add("aquém");
        listaPalavras.add("porém");
        listaPalavras.add("sanar");
        listaPalavras.add("seção");
        listaPalavras.add("desde");
        listaPalavras.add("fazer");
        listaPalavras.add("cerne");
        listaPalavras.add("ideia");
        listaPalavras.add("moral");
        listaPalavras.add("assim");
        listaPalavras.add("poder");
        listaPalavras.add("torpe");
        listaPalavras.add("fosse");
        listaPalavras.add("anexo");
        listaPalavras.add("honra");
        listaPalavras.add("fútil");
        listaPalavras.add("justo");
        listaPalavras.add("muito");
        listaPalavras.add("razão");
        listaPalavras.add("ícone");
        listaPalavras.add("mútuo");
        listaPalavras.add("quiçá");
        listaPalavras.add("gozar");
        listaPalavras.add("lapso");
        listaPalavras.add("égide");
        listaPalavras.add("tange");
        listaPalavras.add("hábil");
        listaPalavras.add("expor");
        listaPalavras.add("haver");
        listaPalavras.add("sobre");
        listaPalavras.add("etnia");
        listaPalavras.add("corja");
        listaPalavras.add("exceto");
        listaPalavras.add("cínico");
        listaPalavras.add("idôneo");
        listaPalavras.add("âmbito");
        listaPalavras.add("néscio");
        listaPalavras.add("índole");
        listaPalavras.add("mister");
        listaPalavras.add("vereda");
        listaPalavras.add("apogeu");
        listaPalavras.add("inócuo");
        listaPalavras.add("convém");
        listaPalavras.add("sádico");
        listaPalavras.add("utopia");
        listaPalavras.add("ênfase");
        listaPalavras.add("mérito");
        listaPalavras.add("escopo");
        listaPalavras.add("alusão");
        listaPalavras.add("anseio");
        listaPalavras.add("casual");
        listaPalavras.add("pressa");
        listaPalavras.add("alheio");
        listaPalavras.add("nocivo");
        listaPalavras.add("infame");
        listaPalavras.add("hostil");
        listaPalavras.add("exímio");
        listaPalavras.add("gentil");
        listaPalavras.add("afável");
        listaPalavras.add("idiota");
        listaPalavras.add("legado");
        listaPalavras.add("adorno");
        listaPalavras.add("cético");
        listaPalavras.add("adesão");
        listaPalavras.add("dádiva");
        listaPalavras.add("sóbrio");
        listaPalavras.add("paixão");
        listaPalavras.add("clichê");
        listaPalavras.add("aferir");
        listaPalavras.add("astuto");
        listaPalavras.add("êxtase");
        listaPalavras.add("boceta");
        listaPalavras.add("difuso");
        listaPalavras.add("apreço");
        listaPalavras.add("otário");
        listaPalavras.add("formal");
        listaPalavras.add("limiar");
        listaPalavras.add("solene");
        listaPalavras.add("sessão");
        listaPalavras.add("lábaro");
        listaPalavras.add("júbilo");
        listaPalavras.add("ocioso");
        listaPalavras.add("empatia");
        listaPalavras.add("embuste");
        listaPalavras.add("cônjuge");
        listaPalavras.add("exceção");
        listaPalavras.add("efêmero");
        listaPalavras.add("prolixo");
        listaPalavras.add("idílico");
        listaPalavras.add("caráter");
        listaPalavras.add("análogo");
        listaPalavras.add("genuíno");
        listaPalavras.add("estória");
        listaPalavras.add("sublime");
        listaPalavras.add("verbete");
        listaPalavras.add("pêsames");
        listaPalavras.add("sucinto");
        listaPalavras.add("inferir");
        listaPalavras.add("apático");
        listaPalavras.add("audácia");
        listaPalavras.add("recesso");
        listaPalavras.add("astúcia");
        listaPalavras.add("pródigo");
        listaPalavras.add("acepção");
        listaPalavras.add("cinismo");
        listaPalavras.add("redimir");
        listaPalavras.add("refutar");
        listaPalavras.add("estável");
        listaPalavras.add("estigma");
        listaPalavras.add("família");
        listaPalavras.add("exortar");
        listaPalavras.add("cordial");
        listaPalavras.add("icônico");
        listaPalavras.add("mórbido");
        listaPalavras.add("trivial");
        listaPalavras.add("escória");
        listaPalavras.add("cultura");
        listaPalavras.add("emergir");
        listaPalavras.add("virtude");
        listaPalavras.add("imputar");
        listaPalavras.add("síntese");
        listaPalavras.add("soberba");
        listaPalavras.add("aspecto");
        listaPalavras.add("mitigar");
        listaPalavras.add("anátema");
        listaPalavras.add("deboche");
        listaPalavras.add("candura");
        listaPalavras.add("almejar");
        listaPalavras.add("excerto");
        listaPalavras.add("luxúria");
        listaPalavras.add("frívolo");
        listaPalavras.add("ademais");
        listaPalavras.add("inerente");
        listaPalavras.add("peculiar");
        listaPalavras.add("denegrir");
        listaPalavras.add("respeito");
        listaPalavras.add("anuência");
        listaPalavras.add("genocida");
        listaPalavras.add("deferido");
        listaPalavras.add("prudente");
        listaPalavras.add("equidade");
        listaPalavras.add("iminente");
        listaPalavras.add("invasivo");
        listaPalavras.add("essência");
        listaPalavras.add("alienado");
        listaPalavras.add("extensão");
        listaPalavras.add("desgraça");
        listaPalavras.add("eminente");
        listaPalavras.add("pandemia");
        listaPalavras.add("misógino");
        listaPalavras.add("abstrato");
        listaPalavras.add("empírico");
        listaPalavras.add("premissa");
        listaPalavras.add("ardiloso");
        listaPalavras.add("conceito");
        listaPalavras.add("reiterar");
        listaPalavras.add("ascensão");
        listaPalavras.add("passível");
        listaPalavras.add("prodígio");
        listaPalavras.add("devaneio");
        listaPalavras.add("conserto");
        listaPalavras.add("relativo");
        listaPalavras.add("apologia");
        listaPalavras.add("modéstia");
        listaPalavras.add("lascívia");
        listaPalavras.add("inserção");
        listaPalavras.add("inóspito");
        listaPalavras.add("monótono");
        listaPalavras.add("analogia");
        listaPalavras.add("ativista");
        listaPalavras.add("respaldo");
        listaPalavras.add("talarico");
        listaPalavras.add("remissão");
        listaPalavras.add("rechaçar");
        listaPalavras.add("sinônimo");
        listaPalavras.add("notívago");
        listaPalavras.add("concerne");
        listaPalavras.add("despeito");
        listaPalavras.add("alicerce");
        listaPalavras.add("medíocre");
        listaPalavras.add("destarte");
        listaPalavras.add("proceder");
    }
}
