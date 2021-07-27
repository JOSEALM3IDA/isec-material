package pt.isec.ans.biblioteca.iu;

import pt.isec.ans.biblioteca.modelo.*;

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class BiblioIU {
    BibliotecaSet biblio;
    Scanner sc;

    public BiblioIU(BibliotecaSet biblio) {
        this.biblio = biblio;
        sc = new Scanner(System.in);
    }

    int pedeInteiro(String pergunta) {
        System.out.print(pergunta);
        while (!sc.hasNextInt())
            sc.next();
        int valor = sc.nextInt();
        sc.nextLine();
        return valor;
    }

    String pedeString(String pergunta) {
        String resposta;
        do {
            System.out.print(pergunta);
            resposta = sc.nextLine().trim();
        } while (resposta.isEmpty());
        return resposta;
    }

    int escolheOpcao(String... opcoes) { // String [] opcoes
        int opcao;

        do {
            for (int i = 0; i < opcoes.length; i++)
                System.out.printf("%3d - %s\n",i+1,opcoes[i]);
            opcao = pedeInteiro("\n> ");
        } while (opcao<1 || opcao>opcoes.length);
        return opcao;
    }
    void acrescentaLivro() {
        String titulo = pedeString("Indique o titulo do livro:\n> ");
        String autor;
        ArrayList<String> autores = new ArrayList<>();
        do {
            autor = pedeString("Indique um autor [\'fim\' para terminar]:\n> ");
            if (autor!=null && !autor.equalsIgnoreCase("fim"))
                autores.add(autor);
        } while (!autor.equalsIgnoreCase("fim"));
        if (autores.isEmpty())
            autores.add("Autor desconhecido");
        biblio.acrescentaLivro(titulo,autores);
    }

    void acrescentaLivroAntigo() {
        String titulo = pedeString("Indique o titulo do livro:\n> ");
        String autor;
        ArrayList<String> autores = new ArrayList<>();
        do {
            autor = pedeString("Indique um autor [\'fim\' para terminar]:\n> ");
            if (autor!=null && !autor.equalsIgnoreCase("fim"))
                autores.add(autor);
        } while (!autor.equalsIgnoreCase("fim"));
        if (autores.isEmpty())
            autores.add("Autor desconhecido");
        int copias = pedeInteiro("Indique o numero de copias: ");
        biblio.acrescentaLivro(new LivroAntigo(titulo,autores,copias));
    }

    void acrescentaLivroAtual() {
        String titulo = pedeString("Indique o titulo do livro:\n> ");
        String autor;
        ArrayList<String> autores = new ArrayList<>();
        do {
            autor = pedeString("Indique um autor [\'fim\' para terminar]:\n> ");
            if (autor!=null && !autor.equalsIgnoreCase("fim"))
                autores.add(autor);
        } while (!autor.equalsIgnoreCase("fim"));
        if (autores.isEmpty())
            autores.add("Autor desconhecido");
        String isbn = pedeString("Indique o ISBN: ");
        System.out.println("Indique o preco do livro: ");
        while (!sc.hasNextFloat())
            sc.next();
        float preco = sc.nextFloat();
        biblio.acrescentaLivro(new LivroAtual(titulo,autores,isbn,preco));
    }

    void pesquisaLivro() {
        int codigo = pedeInteiro("Indique o codigo do livro a pesquisar: ");
        Livro livro = biblio.pesquisaLivro(codigo);
        if (livro == null)
            System.out.println("Codigo de livro nao encontrado");
        else
            System.out.println("Livro encontrado: "+livro);
    }

    void eliminaLivro() {
        int codigo = pedeInteiro("Indique o codigo do livro a eliminar: ");
        boolean apagou = biblio.eliminaLivro(codigo);
        if (!apagou)
            System.out.println("Codigo de livro nao encontrado");
        else
            System.out.println("Livro eliminado");
    }

    public void comeca() {
        while (true) {
            switch (escolheOpcao("Adiciona livro","Adiciona Livro Antigo","Adiciona Livro Atual",
                    "Pesquisa Livro","Remove Livro","Listar","Listar por titulo","Listar por codigo",
                    "Acrescentar livro repetido","Sair","Escrever em ficheiro","Ler de ficheiro",
                    "Gravar (Serialização)", "Ler (Desserialização)")) {
                case 1:
                    acrescentaLivro();
                    break;
                case 2:
                    acrescentaLivroAntigo();
                    break;
                case 3:
                    acrescentaLivroAtual();
                    break;
                case 4:
                    pesquisaLivro();
                    break;
                case 5:
                    eliminaLivro();
                    break;
                case 6:
                    System.out.println(biblio.toString());
                    break;
                case 7:
                    System.out.println(biblio.toStringPorTitulo());
                    break;
                case 8:
                    System.out.println(biblio.toStringPorCodigo());
                    break;
                case 9:
                    Livro livro = biblio.pesquisaLivro(1);
                    if (livro != null) {
                        if (biblio.acrescentaLivro(livro) < 0)
                            System.out.println("Erro a adicionar livro");
                        else
                            System.out.println("Livro adicionado com sucesso");
                    }
                    break;
                case 10:
                    return;
                case 11:
                    biblio.escreveFichTxt(new File("biblio.txt"));
                    break;
                case 12:
                    biblio = new BibliotecaSet(new File("biblio.txt"));
                    break;
                case 13:
                    biblio.gravar();
                    break;
                case 14:
                    biblio.ler();
                    biblio = BibliotecaSet.lerGenerico();
                    break;
            }
        }
    }
}
