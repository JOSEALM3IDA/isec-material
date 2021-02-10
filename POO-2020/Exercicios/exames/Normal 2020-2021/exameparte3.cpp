// Exercicio 1
class Eletrodomestico {
   bool ativo = false;
   string nome;

public:
   Eletrodomestico(string n);
   virtual ~Eletrodomestico();

   void ativar();
   void desativar();
   void getNome() const;
   void getAtivo() const;

   virtual void limpa() = 0;
   virtual void enxaguar();
   virtual void secagem();
};

class Roupa : public Eletrodomestico {
   float calculaPeso();
public:
   virtual void limpa();
   virtual void enxaguar();
};

class Louca : public Eletrodomestico {
   bool depositoSal;

public:
   Louca(bool hasDeposito);
   virtual void limpa();
   virtual void secagem();
};

class Assistente {
   const vector<Eletrodomestico*> maquinas;

public:
   Assistente(initializer_list<Eletrodomestico*> il);
   Assistente(const Assistente& a) = delete;
   bool limparEletrodomestico(string n);
};


// Exercicio 2
class Balcao {
   vector<Bet> apostas;
   static int valor;
public:
  bool emiteAposta(string nomeArtista) {
     if (valor == 0)
        return false;

     apostas.push_back(nomeArtista, valor--);
     return true;
  }
};

Balcao::valor = 200;