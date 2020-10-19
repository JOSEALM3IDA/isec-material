%MENUGRAFICOS Pede metodo(s) a representar e representa-os
% 
%INPUT (Informação de um PVI): 
%   strF - Função em x e y em formato string
%   f - Função da equação diferencial, em x e y
%   a - Limite esquerdo do intervalo
%   b - Limite direito do intervalo
%   n - Numero de sub-intervalos
%   y0 - Valor Inicial do PVI
%
%OUTPUT: 
%   Nada
%
%   09/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   09/04/2020 - José Almeida .: a2019129077@isec.pt
%   09/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function menuGraficos(strF, f, a, b, n, y0)

listaOpcoes = {'Método de Euler',...
             'Metodo de Euler Melhorado',...
             'Método de Runge-Kutta (ordem 2)',...
             'Método de Runge-Kutta (ordem 4)',...
             'Método usando ODE45',...
             'Método do Ponto Médio'};
         
escolha = listdlg('ListString',listaOpcoes,'ListSize',[350 100],'Name','Tabela e Gráficos de Resultados','PromptString','Escolha um ou varios métodos...',...
                  'OKString','Continuar','CancelString','Voltar');
              
if isempty(escolha) % só executa o resto do codigo se a escolha tiver sido feita (para evitar problemas com o botão Voltar)
    return
end

[header, tabela] = fazerTabela(escolha, strF, f, a, b, n, y0);              % Chama a função 'fazerTabela' e coloca os valores num array
tamanho = length(escolha);                                                  % tamanho recebe o tamanho de 'escolha'

fprintf('\n----------Tabela de Valores----------\n');
disp(header);                                                               % Mostra o cabeçalho
disp(tabela);                                                               % Mostra a tabela
fprintf('\nCarregue em qualquer tecla para avançar para o gráfico...\n');
pause                                                                       % Pausa o progama até o utilizador carregar numa tecla

h = (b-a)/n;                                                % Calcula o passo (h)
grid on                                                     % Mostra a grelha
t = a:h:b;                                                  % Alocação de memória
plot(t, tabela(:,2), 'DisplayName', 'S.Exata');             % Mostra o gráfico da Solução Exata
hold on                                                     % Necesário colocar para poderem aparecer mais valores no mesmo gráfico

i = 3;                              % inicialização da variável i que vai ser utilizada para incrementar a posição na tabela

for k = 1:tamanho                   % ciclo de 1 até ao número de opções escolhidas no menu
    index = escolha(k);             % index recebe a opção escolhida
    switch index                    % Switch que verifica qual/quais as opções escolhidas no menu
        case 1 % ('----------Solução usando o Método de Euler----------')
            plot(t,tabela(:,i),'--ro','DisplayName','Euler')           % mostra o grafico do método de Euler, com a linha a vermelho e com legenda 'Euler'

        case 2 % ('----------Solução usando o Método de Euler Melhorado (Heun)----------')
            plot(t,tabela(:,i),'--gx','DisplayName','Heun')
            
        case 3 % ('----------Solução usando o Método de Runge-Kutta de ordem 2----------')
            plot(t,tabela(:,i),'--b+','DisplayName','RK2')
           
        case 4 %('----------Solução usando o Método de Runge-Kutta de ordem 4----------')
            plot(t,tabela(:,i),'--c*','DisplayName','RK4')
   
        case 5 % ('----------Solução usando a função ODE45 do MATLAB----------')
            plot(t,tabela(:,i),'--ms','DisplayName','ODE45')
   
        case 6 % ('----------Solução usando o Método do Ponto Médio----------')
            plot(t,tabela(:,i),'--k^','DisplayName','MidPoint')

        otherwise
            errordlg('Opção desconhecida', 'ERRO', 'modal');
    end
    i=i+1;
 end

title('Solução do PVI em modo gráfico')             % titulo do gráfico
legend show                                         % mostra a legenda dos métodos escolhidos
grid on                                             % mostra as grelhas do gráfico
hold off                                            % deve-se colocar quando não há mais plots a fazer
shg;                                                % mostra o gráfico