% INumRTrapezios Integracao Numerica - Formula da Regra dos Trapezios
%
% INPUT:  f - funcao integranda
%         [a, b] - intervalo de integracao
%         n - numero de subintervalos
%
% OUTPUT: area - Valor da area calculada pela Regra dos Trapezios
%
%   25/05/2020 - Carlos Pais .: a2010017171@isec.pt
%   25/05/2020 - José Almeida .: a2019129077@isec.pt
%   25/05/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function area = INumRTrapezios(f,a,b,n)

h=(b-a)/n;                      % Valor de cada subintervalo (passo)
x=a;                            % 'x' recebe o valor de 'a' (primeira abcissa)
s=0;                            % Inicializacao da variavel 's' a 0

for i=1:n-1
    x=x+h;                      % Ao valor de 'x' e somado o passo ('h')
    s=s+f(x);                   % Ao valor de 's' e somado o valor da funcao
end
area = (h/2)*(f(a)+2*s+f(b));
