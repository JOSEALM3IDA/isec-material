#include <vector>

#include "Imovel.h"
#include "Loja.h"
#include "Apartamento.h"
#include "Imobiliaria.h"

int main()
{
    // Deveria ser uma classe RP
    std::vector<Imovel*> RP = { new Loja(10), new Apartamento(15,2,3), new Loja(100)};

    Imobiliaria a("ERA");

    a.addImovel(RP[0]);
    a.addImovel(RP[1]);

    std::cout << a << std::endl;
   
    int i;
    for(i = 0; i < RP.size(); i++)
        std::cout << *(RP[i]) << std::endl;
     
    // Deveria estar no destrutor da classe RP
    for(i = 0; i < RP.size(); i++)
        delete RP[i];
    
    return 0;
}

