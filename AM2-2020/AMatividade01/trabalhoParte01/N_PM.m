%NPMI  Método Númerico para resolver um PVI: Ponto Médio
%   y = NPM(f,a,b,n,y0) Método numérico para a resolução de um PVI
%
%INPUT:
%   f - Função da equação diferencial, em t e y
%   a - Limite esquerdo do intervalo
%   b - Limite direito do intervalo
%   n - Numero de sub-intervalos
%   y0 - Valor (condição) Inicial do PVI
%
%OUTPUT: 
%   y - vector das soluções aproximadas
%
%   09/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   09/04/2020 - José Almeida .: a2019129077@isec.pt
%   09/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function y = N_PM(f,a,b,n,y0)

    h = (b-a)/n;                                                    % Tamanho de cada subintervalo (passo)
    
    t = a:h:b;                                                      % Alocação de memória - vetor das abcissas
    y = zeros(1, n+1);                                              % Alocação de memória - vetor das ordenadas
    
    y(1) = y0;                                                      % O primeiro valor de y é sempre y0 (condição inicial do pvi)

    for i=1:n                                                       % O número de iterações vai ser igual a n
        k1 = 0.5 * f(t(i), y(i));                                   % variavel auxiliar
        y(i+1) = y(i) + h*f(t(i) + h/2, y(i) + h*k1);               % ponto médio explícito
        y(i+1) = y(i) + h*f(t(i) + h/2, 0.5*(y(i) + y(i+1)));       % ponto médio implícito e próximo valor aproximado da solução do problema original
    end


