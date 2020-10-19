% NDerivacaoDFP Derivação Numérica -  Formúla da 2º Derivada (3 pontos)
% Formúla da 2º Derivada (3 pontos)
% f''(x(i))=(f(x(i+1))-f(x(i))/h
% INPUT:  f - função
%         [a, b] - intervalo de derivação
%         h - passo da discretização
%         y - imagens x vs y
% OUTPUT: [x, y] - malha de pontos
%         dydx - segunda derivada de f 
%
%   25/05/2020 - Carlos Pais .: a2010017171@isec.pt
%   25/05/2020 - José Almeida .: a2019129077@isec.pt
%   25/05/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function [x,y,dydx] = NDerivacaoD2(f,a,b,h,y)

x=a:h:b;                                                    % Alocação de memória

n=length(x);                                                % Número de pontos (tamanho do vetor de abcissas)

if nargin==4
    y=f(x);                                                 % y é a função f(x)
end

dydx=zeros(1,n);                                            % Alocação de memória

temp1=(-3*y(1) + 4*y(2) - y(3))/(2*h);                      % Primeira derivada no ponto x = a
temp2=(-3*y(2) + 4*y(3) - y(4))/(2*h);                      % Primeira derivada no ponto x = a + h
temp3=(-3*y(3) + 4*y(4) - y(5))/(2*h);                      % Primeira derivada no ponto x = a + 2*h

dydx(1)=(-3*temp1 + 4*temp2 - temp3)/(2*h);                 % Segunda derivada no ponto x = a

for i=2:n-1
    dydx(i)=(y(i+1) - 2*y(i) + y(i-1))/(h*h);               % Derivada (aproximada) de f no ponto atual
end

tempn2=(y(n-4) - 4*y(n-3) + 3*y(n-2))/(2*h);                % Primeira derivada no ponto x = b - 2*h
tempn1=(y(n-3) - 4*y(n-2) + 3*y(n-1))/(2*h);                % Primeira derivada no ponto x = b - h
tempn=(y(n-2) - 4*y(n-1) + 3*y(n))/(2*h);                   % Primeira derivada no ponto x = b

dydx(n)=(tempn2 - 4*tempn1 + 3*tempn)/(2*h);                % Segunda derivada no ponto x = b
