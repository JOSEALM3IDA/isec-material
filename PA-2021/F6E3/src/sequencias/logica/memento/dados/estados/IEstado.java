package sequencias.logica.memento.dados.estados;


import sequencias.logica.memento.dados.Situacao;

public interface IEstado{

   //Transicoes
   IEstado comecar();
   IEstado recolher(int indice);
   IEstado relancar();
   IEstado avaliar();
   IEstado terminar();

   Situacao getSituacaoAtual();
}
