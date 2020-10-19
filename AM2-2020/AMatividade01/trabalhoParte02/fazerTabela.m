%FAZERTABELA Faz a tabela com os métodos pretendidos
% 
%INPUT (Informação de um PVI + vetor com informaçao dos metodos selecionados): 
%   escolha - Vetor com informação dos métodos pretendidos
%   strF - Função em x e y em formato string
%   f - Função da equação diferencial, em x e y
%   a - Limite esquerdo do intervalo
%   b - Limite direito do intervalo
%   n - Numero de sub-intervalos
%   y0 - Valor Inicial do PVI
%
%OUTPUT: 
%   header - Header da tabela com os métodos pretendidos
%   tabela - Tabela preenchida com os métodos pretendidos
%
%   11/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   11/04/2020 - José Almeida .: a2019129077@isec.pt
%   11/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function [header, tabela] = fazerTabela(escolha, strF, f, a, b, n, y0)

i = 3;                                                     % inicialização da variável i que vai ser utilizada para incrementar a posição na tabela

tamanho = length(escolha);

tabela = zeros(n+1, tamanho*2 + 2);                        % alocaçao de memoria de uma matriz de zeros

try
    header = strings(1, tamanho*2 + 2);                        % inicialização de um vetor vazio de caracteres
catch armenio
    disp('Aviso: alocação do "header" impossível. A funçao strings() só foi implementada na versão r2016b! Isto poderá reduzir a velocidade do programa');
end
h = (b-a)/n;                                            % Calcula o passo (h)
t = a:h:b;                                              % Alocação de memória
header{1} = 'x';                                        % Coloca um 'x' na posição 1 do header
tabela(:,1) = t';                                       

sExata = dsolve(['Dy=', strF], ['y(',num2str(a),')=',num2str(y0)]);
g = @(t) eval(vectorize(char(sExata)));
y = g(t);
header{2} = 'Exata';
tabela(:,2) = y';

for k = 1:tamanho                                       % ciclo de 1 até ao número de opções escolhidas no menu
    index = escolha(k);                                 % index recebe a opção escolhida
    switch index                                        % Switch que verifica qual/quais as opções escolhidas no menu
        case 1 % ('----------Solução usando o Método de Euler----------')
            y = N_Euler(f, a, b, n, y0);              % y recebe o valor do resultado do método de Euler                                       
            header{i} = 'Euler';                        % Caso for selecionado o método de Euler, adiciona-o ao Cabeçalho
            tabela(:,i) = y';                           % na posição de i vai copiar todo o array de y (:) para a tabela

        case 2 % ('----------Solução usando o Método de Euler Melhorado (Heun)----------')
            y = N_Heun(f, a, b, n, y0);                  % y recebe o valor do resultado do método de Heun
            header{i} = 'Heun';                         % Caso for selecionado o método de Heun, adiciona-o ao Cabeçalho
            tabela(:,i) = y';                           % na posição de i vai copiar todo o array de y (:) para a tabela

        case 3 % ('----------Solução usando o Método de Runge-Kutta de ordem 2----------')
            y = N_RK2(f, a, b, n, y0);                   % y recebe o valor do resultado do método RK2
            header{i} = 'RK2';                          % Caso for selecionado o método de RK2, adiciona-o ao Cabeçalho
            tabela(:,i) = y';                           % na posição de i vai copiar todo o array de y (:) para a tabela

        case 4 %('----------Solução usando o Método de Runge-Kutta de ordem 4----------')
            y = N_RK4(f, a, b, n, y0);                   % y recebe o valor do resultado do método RK4
            header{i} = 'RK4';                          % Caso for selecionado o método de RK4, adiciona-o ao Cabeçalho
            tabela(:,i) = y';                           % na posição de i vai copiar todo o array de y (:) para a tabela

        case 5 % ('----------Solução usando a função ODE45 do MATLAB----------')
            y = N_ODE45(f, a, b, n, y0);                % y recebe o valor do resultado do método ODE45
            header{i} = 'ODE45';                        % Caso for selecionado o método de ODE45, adiciona-o ao Cabeçalho
            tabela(:,i) = y;                            % na posição de i vai copiar todo o array de y (:) para a tabela

        case 6 % ('----------Solução usando o Método do Ponto Médio----------')
            y = N_PM(f, a, b, n, y0);                    % y recebe o valor do resultado do método Mid Point
            header{i} = 'MidPoint';                     % Caso for selecionado o método de Mid Point, adiciona-o ao Cabeçalho
            tabela(:,i) = y';                            % na posição de i vai copiar todo o array de y (:) para a tabela
        otherwise
            errordlg('Opção desconhecida', 'ERRO', 'modal');
    end
    i=i+1;                                              % incrementa a posição do array tabela
end

while(i <= tamanho*2+2)
    header{i} = append('Erro ',header{i - tamanho});              % Popular o header dos erros
    
    tabela(:,i) = abs(tabela(:,i-tamanho) - tabela(:,2));         % Popular as colunas dos erros
    
    i = i+1;
end




