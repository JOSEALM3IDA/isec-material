package pt.isec.jalmeida.f2e2;

public class Main {
    public static void main(String[] args) {
        Documento doc = new Documento("Lista de Algo Relevante");
        doc.acrescentaAutor("Joao");
        doc.acrescentaAutor("Joaquim");
        doc.acrescentaAutor("Jose");

        System.out.println(doc.acrescentaAutor("Joao"));
        //System.out.println("Tam: " + doc.getTamMaxAutores() + '\n');

        for (String autor : doc.getAutores())
            System.out.println(autor);

        doc.acrescentaTexto("   Alvaro Nuno,    Santos.... \n qualquer coisa");
        doc.acrescentaTexto("   Alvaro Nuno,    Santos.... \n qualquer coisa");
        doc.acrescentaTexto("   Alvaro Nuno,    Santos.... \n qualquer coisa");

        System.out.println(doc.getTexto());
        System.out.println(doc.contaPalavras());

    }
}
