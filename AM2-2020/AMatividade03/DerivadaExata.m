% DerivadaExata Derivação Analítica
% Derivação Analítica pela função diff
% 
% INPUT:  strF - função f em formato string
%
% OUTPUT: h - derivada exata da funçao f
% 
%   25/05/2020 - Carlos Pais .: a2010017171@isec.pt
%   25/05/2020 - José Almeida .: a2019129077@isec.pt
%   25/05/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function f = DerivadaExata(strF)

syms x                                      % cria a variável simbólica x
h = @(x) eval(vectorize(strF));

f = matlabFunction(diff(h(x)));             % Calcula, através da função diff, a derivada exata