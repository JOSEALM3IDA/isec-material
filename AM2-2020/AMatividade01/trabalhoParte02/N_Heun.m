%NHeun  Método Númerico para resolver um PVI: Heun (Euler melhorado)
%   y = NHeun(f,a,b,n,y0) Método numérico para a resolução de um PVI
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
%   08/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   08/04/2020 - José Almeida .: a2019129077@isec.pt
%   08/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function y = N_Heun(f,a,b,n,y0)
    h = (b-a)/n;                     % Tamanho de cada subintervalo (passo)
    
    t = a:h:b;                       % Alocação de memória - vetor das abcissas
    y = zeros(1, n+1);               % Alocação de memória - vetor das ordenadas
    
   
    y(1) = y0;                       % O primeiro valor de y é sempre y0 (condição inicial do pvi)
    
    for i=1:n                        % O número de iterações vai ser igual a n
        k1 = f(t(i),y(i));           % Inclinação no início do intervalo
        k2 = f(t(i+1), y(i) + k1*h); % Inclinação no fim do intervalo
        k = 0.5*(k1+k2);             % Cálculo da média das inclinações
        y(i+1)=y(i)+h*k;             % Próximo valor aproximado da solução do problema original
    end
end