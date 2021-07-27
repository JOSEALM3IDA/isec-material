package listadecompras.ui.texto;

import listadecompras.logica.GestaoListaCompras;

import java.util.Scanner;

public class UITextoListaCompras {
    private GestaoListaCompras listaDeCompras;
    private boolean sair = false;
    private Scanner s = new Scanner(System.in);

    public UITextoListaCompras(GestaoListaCompras listaDeCompras) {
        this.listaDeCompras = listaDeCompras;
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
                System.out.println(listaDeCompras);
                break;
            case 2: // Acrescentar produto
            {
                System.out.println("Nome do produto:");
                String nome = s.nextLine();
                int quantidade = lerInt("Quantidade:");
                listaDeCompras.acrescentaNovoProduto( nome, quantidade);
            }
            break;
            case 3: // Eliminar prduto
            {
                System.out.println(listaDeCompras);
                int indice = lerInt("Indice:");
                listaDeCompras.eliminaProduto(indice);
                System.out.println(listaDeCompras);
            }
            break;
            case 4:  // Alterar quantidade
            {   System.out.println(listaDeCompras);
                int indice = lerInt("Indice:");
                int quantidade = lerInt("Quantidade:");
                listaDeCompras.alteraQuantidade(indice, quantidade);
                System.out.println(listaDeCompras);
            }
            break;
            case 5:  // Undo
            {   System.out.println(listaDeCompras);
                listaDeCompras.undo();
                System.out.println("**** undo ****");
                System.out.println(listaDeCompras);
            }
            break;
            case 6:  // Redo
            {   System.out.println(listaDeCompras);
                listaDeCompras.redo();
                System.out.println("**** redo ****");
                System.out.println(listaDeCompras);
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

