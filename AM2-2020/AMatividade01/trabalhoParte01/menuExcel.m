%MENUEXCEL Pede metodo(s) a representar e representa-os
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
%   10/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   11/04/2020 - José Almeida .: a2019129077@isec.pt
%   09/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function menuExcel(strF, f, a, b, n, y0)

listaOpcoes = {'Método de Euler',...
             'Metodo de Euler Melhorado',...
             'Método de Runge-Kutta (ordem 2)',...
             'Método de Runge-Kutta (ordem 4)',...
             'Método usando ODE45',...
             'Método do Ponto Médio'};
         
escolha = listdlg('ListString',listaOpcoes,'ListSize',[350 100],'Name','Criação de Ficheiro Excel','PromptString','Escolha um ou varios métodos...',...
                  'OKString','Continuar','CancelString','Voltar');
              
if isempty(escolha) % só executa o resto do codigo se a escolha tiver sido feita (para evitar problemas com o botão Voltar)
    return
end

[header, tabela] = fazerTabela(escolha, strF, f, a, b, n, y0);              % Chama a função 'fazerTabela' e coloca os valores num array

filename = 'MetodosNumericos.xlsx';                                         % A variável 'filename' fica associada ao ficheiro pdf

if exist(filename, 'file')                              % Verifica se o ficheiro 'MetodosNumericos.xlsx' existe
    delete(filename);                                   % se existir apaga-o
end

xlswrite(filename,header,'Sheet1','B2');                                    % Escreve o cabeçalho no ficheiro excel a partir da célula B2
xlswrite(filename,tabela,'Sheet1','B3');                                    % Escreve os valores da tabela no ficheiro excel a partir da célula B3
winopen(filename);                                                          % Abre o ficheiro excel