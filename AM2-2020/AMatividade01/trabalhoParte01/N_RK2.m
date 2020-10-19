%NRK2  Método Númerico para resolver um PVI: Runge-Kutta de ordem 2
%   y = NRK2(f,a,b,n,y0) Método numérico para a resolução de um PVI
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
%   07/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   18/03/2020 - José Almeida .: a2019129077@isec.pt
%   07/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function y = N_RK2(f,a,b,n,y0)
    h = (b-a)/n;                            % Tamanho de cada subintervalo (passo)
   
    t = a:h:b;                              % Alocação de memória - vetor das abcissas
    y = zeros(1, n+1);                      % Alocação de memória - vetor das ordenadas
        
    y(1) = y0;                              % O primeiro valor de y é sempre y0 (condição inicial do pvi)
    
    for i=1:n                               % O número de iterações vai ser igual a n
        k1 = h * f(t(i), y(i));             % Inclinação no início do intervalo
        k2 = h * f(t(i + 1), y(i) + k1);    % Inclinação no fim do intervalo
        
        y(i + 1)=y(i) + (k1 + k2)/2;        % Próximo valor aproximado da solução do problema original
    end
end
