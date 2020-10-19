%MENUGRAFICOS Pede método a utilizar e devolve o vetor das soluções
% 
%INPUT (Informação de um PVI): 
%   f - Função da equação diferencial, em x e y
%   a - Limite esquerdo do intervalo
%   b - Limite direito do intervalo
%   n - Numero de sub-intervalos
%   y0 - Valor Inicial do PVI
%
%OUTPUT: 
%   auxiliar - Usada quando o utilizador decide fechar o programa
%
%   07/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   07/04/2020 - José Almeida .: a2019129077@isec.pt
%   07/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function auxiliar = menuMetodos(f, a, b, n, y0)

    auxiliar = 0;
    
    while 1
        escolha = menu('Métodos Numéricos para PVI',...
                     'Método de Euler',...
                     'Metodo de Euler Melhorado',...
                     'Método de Runge-Kutta (ordem 2)',...
                     'Método de Runge-Kutta (ordem 4)',...
                     'Método usando ODE45',...
                     'Método do Ponto Médio',...
                     'Voltar');
         switch escolha
             case 0 % caso o utilizador clique na cruz
                 sair = questdlg('Tem a certeza que deseja sair?', 'Sair?', 'Sim', 'Não', 'Sim');
                 if strcmp(sair, 'Sim')
                     auxiliar = 1;
                     return;
                 end

             case 1 % Método de Euler
                 disp('----------Solução usando o Método de Euler----------')
                 y = N_Euler(f, a, b, n, y0);
                 y'

             case 2 % Método de Euler Melhorado / Método de Heun
                 disp('----------Solução usando o Método de Euler Melhorado (Heun)----------')
                 y = N_Heun(f, a, b, n, y0);
                 y'

             case 3 % Método de Runge-Kutta de ordem 2
                 disp('----------Solução usando o Método de Runge-Kutta de ordem 2----------')
                 y = N_RK2(f, a, b, n, y0);
                 y'

             case 4 % Método de Runge-Kutta de ordem 4
                 disp('----------Solução usando o Método de Runge-Kutta de ordem 4----------')
                 y = N_RK4(f, a, b, n, y0);
                 y'

             case 5 % Método usando ODE45 do MATLab
                 disp('----------Solução usando a função ODE45 do MATLAB----------')
                 y = N_ODE45(f, a, b, n, y0);
                 y'
                 

             case 6 % Método do Ponto Médio (midpoint method)
                 disp('----------Solução usando o Método do Ponto Médio----------')
                 y = N_PM(f, a, b, n, y0);
                 y'

             case 7 % caso o utilizador pretenda voltar atrás
                 return;

             otherwise
                 errordlg('Opção desconhecida', 'ERRO', 'modal');
         end
     end