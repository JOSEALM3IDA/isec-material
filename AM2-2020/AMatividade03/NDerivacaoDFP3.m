% NDerivacaoDFP3 Derivação Numérica - Fórmula das Diferenças Progressivas (3 pontos)
% Formúla das Diferenças Progressivas (3 pontos)
% f'(x(i))=(-3*f(x(i)) + 4*f(x(i+1)) + f(x(i+2))/(2*h)
% INPUT:  f - função
%         [a, b] - intervalo de derivação
%         h - passo da discretização
%         y - imagens x vs y
% OUTPUT: [x, y] - malha de pontos
%         dydx - derivada de f 

%   25/05/2020 - Carlos Pais .: a2010017171@isec.pt
%   25/05/2020 - José Almeida .: a2019129077@isec.pt
%   25/05/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function [x,y,dydx] = NDerivacaoDFP3(f,a,b,h,y)

x=a:h:b;                                                    % Alocação de memória

n=length(x);                                                % Número de pontos (tamanho do vetor de abcissas)

if nargin==4
    y=f(x);                                                 % y é a função f(x)
end

dydx=zeros(1,n);                                            % Alocação de memória

for i=1:n-2
    dydx(i)=(-3*y(i) + 4*y(i+1) - y(i+2))/(2*h);            % Derivada (aproximada) de f no ponto atual
end

dydx(n-1)=(y(n-3) - 4*y(n-2) + 3*y(n-1))/(2*h);             % Derivada (aproximada) de f no ponto atual
dydx(n)=(y(n-2) - 4*y(n-1) + 3*y(n))/(2*h);                 % Derivada (aproximada) de f no ponto atual
