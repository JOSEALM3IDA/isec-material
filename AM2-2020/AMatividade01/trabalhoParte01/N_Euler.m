%NEULER_v2  Método Númerico para resolver um PVI: Euler (com memory alloc)
%   y = NEuler(f,a,b,n,y0) Método numérico para a resolução de um PVI 
%
%INPUT:
%   f - Função da equação diferencial, em t e y
%   a - Limite esquerdo do intervalo
%   b - Limite direito do intervalo
%   n - Numero de sub-intervalos
%   y0 - Valor (condição) Inicial do PVI
%
%OUTPUT: 
%   y - vetor das soluções aproximações
%
%   03/03/2020 - ArménioCorreia .: armenioc@isec.pt 
%   07/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   07/04/2020 - José Almeida .: a2019129077@isec.pt
%   07/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function y = N_Euler(f,a,b,n,y0)
    h = (b-a)/n;                        % Tamanho de cada subintervalo (passo)
	
    t = a:h:b;                          % Alocação de memória - vetor das abcissas
    y = zeros(1, n+1);                  % Alocação de memória - vetor das ordenadas
	
    y(1) = y0;                          % O primeiro valor de y é sempre y0 (condição inicial do pvi)
    
    for i=1:n                           % O número de iterações vai ser igual a n
        y(i+1)=y(i)+h*f(t(i),y(i));     % Aproximação do método de Euler para a iésima iteração
    end
end
