#include "Livro.h"
#include "Policial.h"
#include "FC.h"
#include "Biblioteca.h"

int main()
{    
    Livro *l1 = new Livro("Harry Potter", "J.K. Rowling", "123");
    Livro *l2 = new FC("Fundacao", "Asimov", "456", "Trantor", 10000);
    Livro *l3 = new Policial("Morte no Nilo", "Agatha Christie", "789", "Poirot", 10);

    Biblioteca a, b;

    b.addLivro(l1);
    b.addLivro(l2);
    b.addLivro(l3);

    a = b;

    b.eliminaLivro("456");      // Destruir o livro com ISBN

    std::cout << b << std::endl << a << std::endl;

    return 0;
}


