package listadecompras.iu.texto;

import listadecompras.logica.ListaDeComprasGestao;

import java.util.Scanner;

public class IUTexto {
    private ListaDeComprasGestao listaDeComprasGestao;
    private boolean sair = false;
    private Scanner s = new Scanner(System.in);

    public IUTexto(ListaDeComprasGestao listaDeComprasGestao) {
        this.listaDeComprasGestao = listaDeComprasGestao;
    }

    private int lerInt( String msg) {
        System.out.print(msg);
        while (!s.hasNextInt()) {
            s.next();
            System.out.print(msg);
        }
        int num = s.nextInt();
        s.nextLine();
        return num;
    }

    private int escolheOpcao(String[] opcoes) {

        System.out.println("Escolha uma opcao:");
        Scanner s = new Scanner(System.in);
        for (int i = 0; i < opcoes.length; i++) {
            System.out.println("" + i + "-" + opcoes[i]);
        }
        int op = -1;
        do {
            op = lerInt("> ");
        } while (op < 0 || op >= opcoes.length);
        return op;
    }

    private void iuAguardaOpcao() {
        Scanner s = new Scanner(System.in);
        String[] opcoes = {"Sair", "Listar", "Acrescentar produto",
                "Eliminar prduto", "Alterar quantidade", "Undo", "Redo"};
        int op = escolheOpcao(opcoes);
        switch (op) {
            case 0:  // Sair
                sair = true;
                break;
            case 1:  //Listar
                System.out.println(listaDeComprasGestao);
                break;
            case 2: // Acrescentar produto
            {
                System.out.println("Nome do produto:");
                String nome = s.nextLine();
                int quantidade = lerInt("Quantidade:");
                listaDeComprasGestao.acrescentaNovoProduto( nome, quantidade);
            }
            break;
            case 3: // Eliminar prduto
            {
                System.out.println(listaDeComprasGestao);
                int indice = lerInt("Indice:");
                listaDeComprasGestao.eliminaProduto(indice);
                System.out.println(listaDeComprasGestao);
            }
            break;
            case 4:  // Alterar quantidade
            {   System.out.println(listaDeComprasGestao);
                int indice = lerInt("Indice:");
                int quantidade = lerInt("Quantidade:");
                listaDeComprasGestao.alteraQuantidade(indice, quantidade);
                System.out.println(listaDeComprasGestao);
            }
            break;
            case 5:  // Undo
            {   System.out.println(listaDeComprasGestao);
                listaDeComprasGestao.undo();
                System.out.println("**** undo ****");
                System.out.println(listaDeComprasGestao);
            }
            break;
            case 6:  // Redo
            {   System.out.println(listaDeComprasGestao);
                listaDeComprasGestao.redo();
                System.out.println("**** redo ****");
                System.out.println(listaDeComprasGestao);
            }
            break;
        }
    }

    public void corre() {
        while (!sair) {
            iuAguardaOpcao();
        }
    }

}
